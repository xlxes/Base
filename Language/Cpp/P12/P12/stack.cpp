#include "pch.h"
#include "stack.h"
#include <iostream>

using namespace std;

stack::stack(int n)
{
	items = new Item[n];	//����Item����
	top = 0;				//top�����ı��
	size = 0;				//sizeΪ�������ݵ�����
}

stack::stack(const stack& st)	//��ȸ��ƹ��캯��
{
	items = new Item[st.size];
	top = 0;
	size = 0;
	for (int i = 0; i < st.size; i++)
	{
		items[i] = st.items[i];
		size++;
		top++;
	}
}

stack::~stack()
{
	delete[] items;
}

bool stack::isempty() const
{
	return top == 0;
}

bool stack::isfull() const
{
	return top == Max;	//���ñȽ�size�᲻�����
}

bool stack::push(const Item& it)		//�����µ�Ԫ��
{
	if (isfull())
		cout << "error! stack is full" << endl;
	else
	{
		items[top++] = it;
		size++;
		return true;
	}
	return false;
}

bool stack::pop(Item& it)
{
	if (isempty())
		cout << "error! stack is empty" << endl;
	else
	{
		it = items[top--];
		size--;
		return true;
	}
	return false;
}

stack& stack::operator=(const stack& st)
{
	if (this == &st)
		return *this;
	delete[] items;
	items = new Item[st.size];
	top = 0;
	size = 0;
	for (int i = 0; i < st.size; i++)
	{
		items[i] = st.items[i];
		size++;
		top++;
	}
	return *this;
}

ostream& operator<<(ostream& os, const stack& st)
{
	os << "This stack is: " << endl;
	int len = st.top - 1;
	while (len != -1)
	{
		cout << "#" << len << " " << st.items[len] << endl;
		len--;
	}
	return os;
}
