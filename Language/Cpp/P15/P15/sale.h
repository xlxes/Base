#ifndef SALE_H_
#define SALE_H_
#include <stdexcept>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

class Sale
{

public:
	enum {months = 12};
	//Ƕ���쳣��
	class bad_index :public logic_error
	{
	private:
		int bi;
	public:
		//��ʾ���캯��
		explicit bad_index(int ix, const string& s = "index error in sale object\n");
		int bi_val() const { return bi; }
		virtual ~bad_index() throw() {}
	};
	//��ֹȱʡ����ʽת��
	explicit Sale(int yy = 0);
	Sale(int yy, const double *gr, int n);
	virtual ~Sale() {}
	int year_val() const { return year; }
	virtual double operator[](int i)const;
	virtual double& operator[](int i);
private:
	double gross[months];
	int year;
};

class labeled :public Sale
{
public:
	//Ƕ���쳣�� �̳����ϸ����Ƕ����
	class nbad_index :public Sale::bad_index
	{
	private:
		string lbl;
	public:
		nbad_index(const string& lbl, int ix, const string& s = "index error in labled object\n");
		const string& label_val() const { return lbl; }
		virtual ~nbad_index() throw() {}
	};
	//��ֹȱʡ����ʽת��
	explicit labeled(const string& lb = "none", int yy = 0);
	labeled(const string& lb, int yy, const double *gr, int n);
	virtual ~labeled() {}
	const string& label_val() const { return label; }
	virtual double operator[](int i)const;
	virtual double& operator[](int i);
private:
	string label;
};

#endif // !SALE_H_

