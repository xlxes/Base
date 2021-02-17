#include "pch.h"
#include "queue.h"
#include <cstdlib>


customer::~customer()
{
}

//queue定义

//与声明处方式相同
queue::queue(int qs):qsize(qs)	//必须为qsize提供初始化值 
{
	front = rear = nullptr;
	num_items = 0;
}

queue::~queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;		//从头开始依次删除
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

//添加一个元素
bool queue::addqueue(const Item2& it)
{
	if (isfull())
		return false;
	//构建临时节点并赋值
	Node* add = new Node;		
	add->item = it;
	add->next = nullptr;
	//节点数++
	num_items++;
	//跟新front地址和rear地址
	if (front == nullptr)
		front = add;
	else
		rear->next = add;	//此时rear表示倒数第二个元素
	rear = add;
	return true;
}

//删除一个元素
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

//设置客户
void customer::set(long when)
{
	processtime = std::rand() % 3 + 1;	//随机选取客户需要服务的时间
	arrive = when;

}