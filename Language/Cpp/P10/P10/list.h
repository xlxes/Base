#ifndef LIST_H_
#define LIST_H_

typedef int Item_me;

class List
{
private:
	enum { max = 5 };		//最长定义为5
	Item_me items[max];
	int top = 0;
public:
	List();
	~List();
	bool isempty() const;
	bool isfull() const;
	bool add(const Item_me& data);
	void visit(void(*pf)(Item_me& data));
	void showitem() const;
};

void plus100(Item_me& data);

#endif // !LIST_H_

