#include "pch.h"
#include "stack.h"
#include <iostream>


Stack::Stack()
{
	top = 0;
}

Stack::~Stack()
{
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == max;
}

bool Stack::push(const Item& item)
{
	if (top < max)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}