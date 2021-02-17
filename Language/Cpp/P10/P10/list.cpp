#include "pch.h"
#include "list.h"
#include <iostream>

List::List()
{
}

List::~List()
{
}

bool List::isempty() const
{
	return top == 0;
}

bool List::isfull() const
{
	return top == max;
}

bool List::add(const Item_me& data)
{
	if (top < max)
	{
		items[top++] = data;
		return true;
	}
	else
		return false;
}

void List::visit(void(*pf)(Item_me& data))
{
	for (int i = 0; i < top; i++)		//逐渐对每个成员进行操作
	{
		pf(items[i]);		//pf为某函数 该处为plus100
	}
}

void List::showitem() const
{
	using std::endl;
	using std::cout;
	for (int i = 0; i < top; i++)
	{
		cout << "#" << i + 1 << " : " << items[i] << endl;
	}
}

void plus100(Item_me& data)
{
	data += 100;
}