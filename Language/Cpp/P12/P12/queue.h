#ifndef QUEUE_H_
#define QUEUE_H_

//客户类
class customer	
{
private:
	long arrive;		//到达时间
	int processtime;	//等待时间
public:
	customer() { arrive = processtime = 0; }
	~customer();
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }

};

typedef customer Item2;

//队列类
class queue
{
private:
	struct Node
	{
		Item2 item;			//本元素
		struct Node* next;	//下个元素地址指针
	};
	enum { q_size = 10 };
	Node* front;	//队列头地址
	Node* rear;		//队列尾地址
	int num_items;		//当前队列中的个数
	const int qsize;	//队列中元素个数最大值
	//提前定义防止公有函数复制
	queue(const queue& q) :qsize(0) {}
	queue& operator=(const queue& q) { return *this; }

public:
	queue(int qs = q_size);		//默认创建长度为10的队列
	~queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool addqueue(const Item2 & it);
	bool delqueue(Item2& it);

};



#endif // !QUEUE_H_

