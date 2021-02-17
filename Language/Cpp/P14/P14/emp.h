#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

using namespace std;

//抽象基类
class abstr_emp
{
private:
	string firstname;
	string lastname;
	string job;
public:
	abstr_emp():firstname("no noe"),lastname("no name"),job("no job") {}
	abstr_emp(const string &fn, const string &ln, const string &j) :firstname(fn), lastname(ln), job(j) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	friend ostream& operator<<(ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() = 0;
};

//公有继承
class employee :public abstr_emp
{
public:
	employee() :abstr_emp() {}
	employee(const string& fn, const string& ln, const string& j) :abstr_emp(fn, ln, j) {}
	virtual void ShowAll() const { abstr_emp::ShowAll(); }
	virtual void SetAll() { abstr_emp::SetAll(); }
};

//虚基类公有继承
class manager :virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int charge() const { return inchargeof; }
	int& charge() { return inchargeof; }
public:
	manager() :abstr_emp() {}
	manager(const string& fn, const string& ln, const string &j, int ico = 0) :abstr_emp(fn, ln, j), inchargeof(ico) {}
	manager(const abstr_emp& e, int ico = 0) :abstr_emp(e), inchargeof(ico) {}
	manager(const manager& m) :abstr_emp(m),inchargeof(m.inchargeof) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	void getinchargeof() { cout << "enter inchargeof :"; cin >> inchargeof; }
};

//虚基类公有继承
class fink :virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string ReportsTo() const { return reportsto; }
	string& ReportsTo() { return reportsto; }
public:
	fink() :abstr_emp() {}
	fink(const string& fn, const string &ln, const string &j, const string &rpo) :abstr_emp(fn, ln, j), reportsto(rpo) {}
	fink(const abstr_emp& e, const string& rpo) :abstr_emp(e), reportsto(rpo) {}
	fink(const fink& e) :abstr_emp(e), reportsto(e.reportsto) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	void getReportTo() { cout << "enter reportsto :"; cin >> reportsto; }
};

//公有继承 两个类
class highfink :public manager, public fink
{
public:
	highfink() :abstr_emp(), manager(), fink() {}
	highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico = 0) :abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
	highfink(const abstr_emp& e, const string&rpo, int ico = 0) :abstr_emp(e), manager(e, ico), fink(e, rpo) {}
	highfink(const fink& f, int ico = 0) :abstr_emp(f), manager(f, ico), fink(f) {}
	highfink(const manager& m, const string& rpo) :abstr_emp(m), fink(m, rpo), manager(m) {}
	highfink(const highfink& h) :abstr_emp(h), manager(h), fink(h) {}
	virtual void ShowAll() const;
	virtual void SetAll();
};

#endif // !EMP_H_
