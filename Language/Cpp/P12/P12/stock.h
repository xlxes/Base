#ifndef STOCK_H_
#define STOCK_H_

#include <iostream>

using namespace std;

class stock
{
private:
	char* company;
	int len;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }

public:
	stock();
	stock(const char* s, long n = 0, double pr = 0);
	~stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const stock& topval(const stock& s) const;
	friend ostream& operator<<(ostream& os, const stock& s);
};
#endif // !STOCK_H_

