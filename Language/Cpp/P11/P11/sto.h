#ifndef STO_H_
#define STO_H_

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class sto
{
private:
	enum { lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;

public:
	sto();
	~sto();
	sto(double lbs);
	sto(int stn, double lbs);
	
	bool operator<(const sto& st)const;
	bool operator<=(const sto& st)const;
	bool operator>(const sto& st)const;
	bool operator>=(const sto& st)const;
	bool operator==(const sto& st)const;
	bool operator!=(const sto& st)const;

	friend ostream& operator<<(ostream& os, const sto& st);


};

#endif // !STO_H_

