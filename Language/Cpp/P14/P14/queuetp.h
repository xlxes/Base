#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template<typename T>

class QueueTp
{
private:
	struct Node { T item; struct Node* next; };
	Node *front;
	Node *rear;
	int items;
	const int qsize;
	QueueTp(const QueueTp& q) :qsize(0) {}
	QueueTp& operator=(const QueueTp& q) { return *this; }
public:
	QueueTp(int qs = 10);
	~QueueTp();
	bool isempty() const { return items == 0; }
	bool isfull() const { return items == qsize; }
	int queuecount() const { return items; }
	bool enqueue(const T& item);
	bool dequeue(T& item);
};

template<typename T>
QueueTp<T>::QueueTp(int qs) :qsize(qs)
{
	front = rear = NULL;
	items = 0;		
}

template<typename T>
QueueTp<T>::~QueueTp()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
bool QueueTp<T>::enqueue(const T& item)
{
	if (isfull())
		return false;
	Node* add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<typename T>
bool QueueTp<T>::dequeue(T& item)	//������������
{
	if (front == NULL)		//����Ϊ��
		return false;
	item = front->item;		//��ֵ
	items--;				//������1
	Node* temp = front;		//ȡ�õ�ǰ�������ַ
	front = front->next;	//ͷָ��������һ��
	delete temp;			//ɾ������ռ�
	if (items == 0)
		rear = NULL;
	return true;
}

class Worker
{
private:
	string fullname;
	long id;
public:
	Worker() :fullname("noname"), id(0L) {}
	Worker(const string &s, long n) :fullname(s), id(n) {}
	~Worker();
	void set();
	void show() const;
};

#endif // !QUEUETP_H_

