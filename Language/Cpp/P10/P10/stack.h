#ifndef STACK_H_
#define STACK_H_

struct customer
{
	char fullnanme[35];
	double payment;
};

typedef customer Item;
class Stack
{
private:
	static const int max = 10;
	Item items[max];
	int top;
public:
	Stack();
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
};
#endif