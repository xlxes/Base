#include "pch.h"
#include "sale.h"

//Ƕ����Ĭ�ϸ�ֵ
Sale::bad_index::bad_index(int ix, const string& s) :logic_error(s), bi(ix)
{}

//���๹�캯��1
Sale::Sale(int yy)
{
	year = yy;
	//�����ֵΪ0
	for (int i = 0; i < months; i++)
		gross[i] = 0;
}

//���๹�캯��2
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

//����[] �����쳣�׳�Ƕ����
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

//�̳����Ƕ����Ĺ��캯��
labeled::nbad_index::nbad_index(const string& lb, int ix, const string&s) :Sale::bad_index(ix, s)
{
	lbl = lb;
}

//�̳���Ĺ��캯��1
labeled::labeled(const string& lb, int yy) : Sale(yy)
{
	label = lb;
}

//�̳���Ĺ��캯��2
labeled::labeled(const string& lb, int yy, const double *gr, int n) : Sale(yy, gr, n)
{
	label = lb;
}

//�̳�������[]���쳣�׳��̳����Ƕ����
double labeled::operator[](int i)const
{
	if (i < 0 || i >= months)
		throw nbad_index(label_val(), i);
	return Sale::operator[](i);
}

//�̳�������[]���쳣�׳��̳����Ƕ����
double& labeled::operator[](int i)
{
	if (i < 0 || i >= months)
		throw nbad_index(label_val(), i);
	return Sale::operator[](i);
}


