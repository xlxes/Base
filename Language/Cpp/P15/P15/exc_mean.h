#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <cmath>
#include <stdexcept>		//含logic_error类
#include <string>

using namespace std;

class bad_hmean :public logic_error
{
private:
	string name;
public:
	explicit bad_hmean(const string& n = "hmean", const string& s = "error in hmean()\n");
	string mesg();
	virtual ~bad_hmean() throw() {}
};

//构造函数
bad_hmean::bad_hmean(const string& n, const string& s) :name(n), logic_error(s)
{}

inline string bad_hmean::mesg()
{
	return "hmean() arguments a=-b should be div a+b=0!\n";
}

class bad_gmean :public logic_error
{
private:
	string name;
public:
	explicit bad_gmean(const string& n = "gmean", const string& s = "error in gmean()\n");
	string mesg();
	virtual ~bad_gmean() throw() {}		//析构函数且抛出异常
};

bad_gmean::bad_gmean(const string& n, const string& s) :name(n), logic_error(s)
{}

inline string bad_gmean::mesg()
{
	return "gmean() arguments should be >=0\n";
}

class bad_hhmean :public logic_error
{
private:
	string name;
public:
	double a;
	double b;
	explicit bad_hhmean(double a = 0, double b = 0, const string& s = "error in hhmean()\n");
	void mesg();
	virtual ~bad_hhmean() throw() {};
};

bad_hhmean::bad_hhmean(double a, double b, const string& s) :a(a), b(b), logic_error(s)
{
	name = "hhmean";
}

inline void bad_hhmean::mesg()
{
	cout << name << "(" << a << " , " << b << ")arguments a=-b should be div a+b=0!\n";
}

class bad_ggmean :public bad_hhmean
{
private:
	string name;
public:
	explicit bad_ggmean(double a = 0, double b = 0, const string& s = "error in ggmean()\n");
	void mesg();
	virtual ~bad_ggmean() throw() {};
};

bad_ggmean::bad_ggmean(double a, double b, const string& s) :bad_hhmean(a,b,s)
{
	name = "ggmean";
}

inline void bad_ggmean::mesg()
{
	cout << name << "(" << bad_hhmean::a << " , " << bad_hhmean::b << ") arguments should be >=0\n";
}

#endif // !EXC_MEAN_H_

