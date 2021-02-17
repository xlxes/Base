#include <iostream>

using namespace std;

typedef unsigned long Item;

class stack
{
private:
	enum {Max = 10};
	Item* items;
	int size;
	int top;
public:
	stack(int n = Max);
	stack(const stack& st);
	~stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	stack& operator=(const stack& st);
	friend ostream& operator<<(ostream& os, const stack& st);
};