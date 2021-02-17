#include "pch.h"
#include "sale.h"

//嵌套类默认赋值
Sale::bad_index::bad_index(int ix, const string& s) :logic_error(s), bi(ix)
{}

//基类构造函数1
Sale::Sale(int yy)
{
	year = yy;
	//逐个赋值为0
	for (int i = 0; i < months; i++)
		gross[i] = 0;
}

//基类构造函数2
Sale::Sale(int yy, const double *gr, int n)
{
	year = yy;
	int lim = (n < months) ? n : months;
	int i;
	for (i = 0; i < lim; i++)
	{
		gross[i] = gr[i];
	}
	for (; i < months; i++)
		gross[i] = 0;
}

//重载[] 出现异常抛出嵌套类
double Sale::operator[](int i)const
{
	if (i < 0 || i >= months)
		throw bad_index(i);
	return gross[i];
}

double& Sale::operator[](int i)
{
	if (i < 0 || i >= months)
		throw bad_index(i);
	return gross[i];
}

//继承类的嵌套类的构造函数
labeled::nbad_index::nbad_index(const string& lb, int ix, const string&s) :Sale::bad_index(ix, s)
{
	lbl = lb;
}

//继承类的构造函数1
labeled::labeled(const string& lb, int yy) : Sale(yy)
{
	label = lb;
}

//继承类的构造函数2
labeled::labeled(const string& lb, int yy, const double *gr, int n) : Sale(yy, gr, n)
{
	label = lb;
}

//继承类重载[]，异常抛出继承类的嵌套类
double labeled::operator[](int i)const
{
	if (i < 0 || i >= months)
		throw nbad_index(label_val(), i);
	return Sale::operator[](i);
}

//继承类重载[]，异常抛出继承类的嵌套类
double& labeled::operator[](int i)
{
	if (i < 0 || i >= months)
		throw nbad_index(label_val(), i);
	return Sale::operator[](i);
}


