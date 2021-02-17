#include "pch.h"
#include "queue.h"
#include <cstdlib>


customer::~customer()
{
}

//queue����

//����������ʽ��ͬ
queue::queue(int qs):qsize(qs)	//����Ϊqsize�ṩ��ʼ��ֵ 
{
	front = rear = nullptr;
	num_items = 0;
}

queue::~queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;		//��ͷ��ʼ����ɾ��
		front = front->next;
		delete temp;
	}
}

bool queue::isempty() const
{
	return num_items == 0;
}

bool queue::isfull() const
{
	return num_items == qsize;
}

int queue::queuecount() const
{
	return num_items;
}

//���һ��Ԫ��
bool queue::addqueue(const Item2& it)
{
	if (isfull())
		return false;
	//������ʱ�ڵ㲢��ֵ
	Node* add = new Node;		
	add->item = it;
	add->next = nullptr;
	//�ڵ���++
	num_items++;
	//����front��ַ��rear��ַ
	if (front == nullptr)
		front = add;
	else
		rear->next = add;	//��ʱrear��ʾ�����ڶ���Ԫ��
	rear = add;
	return true;
}

//ɾ��һ��Ԫ��
bool queue::delqueue(Item2& it)
{
	if (front == nullptr)
		return false;
	it = front->item;
	num_items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (num_items == 0)
		rear = nullptr;
	return true;
}

//���ÿͻ�
void customer::set(long when)
{
	processtime = std::rand() % 3 + 1;	//���ѡȡ�ͻ���Ҫ�����ʱ��
	arrive = when;

}