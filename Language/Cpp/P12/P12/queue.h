#ifndef QUEUE_H_
#define QUEUE_H_

//�ͻ���
class customer	
{
private:
	long arrive;		//����ʱ��
	int processtime;	//�ȴ�ʱ��
public:
	customer() { arrive = processtime = 0; }
	~customer();
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }

};

typedef customer Item2;

//������
class queue
{
private:
	struct Node
	{
		Item2 item;			//��Ԫ��
		struct Node* next;	//�¸�Ԫ�ص�ַָ��
	};
	enum { q_size = 10 };
	Node* front;	//����ͷ��ַ
	Node* rear;		//����β��ַ
	int num_items;		//��ǰ�����еĸ���
	const int qsize;	//������Ԫ�ظ������ֵ
	//��ǰ�����ֹ���к�������
	queue(const queue& q) :qsize(0) {}
	queue& operator=(const queue& q) { return *this; }

public:
	queue(int qs = q_size);		//Ĭ�ϴ�������Ϊ10�Ķ���
	~queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool addqueue(const Item2 & it);
	bool delqueue(Item2& it);

};



#endif // !QUEUE_H_

