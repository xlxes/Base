#ifndef WINEC_H_ 
#define WINEC_H_

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

template<class T1,class T2>
class Pair
{
private:
	T1 year;
	T2 bottles;
public:
	Pair(const T1 & yr, const T2 & bt) :year(yr), bottles(bt) {}
	Pair() {}
	void set(const T1 & yr, const T2 & bt);
	int sum() const;
	void show(int y) const;
};

template<class T1, class T2>
void Pair<T1,T2>::set(const T1 & yr, const T2 & bt)
{
	year = yr;
	bottles = bt;
}

template<class T1, class T2>
int Pair<T1, T2>::sum() const
{
	return bottles.sum();
}

template<class T1, class T2>
void Pair<T1, T2>::show(int y) const
{
	for (int i = 0; i < y; i++)
		cout << "\t" << year[i] << "\t" << bottles[i] << endl;
}

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

//包含的方法
//class Wine
//{
//private:
//	string fullname;
//	PairArray yb;
//	int num;
//public:
//	Wine() {};
//	Wine(const char* l, int y, const int yr[], const int bot[]);
//	Wine(const char* l, int y);
//	void GetBottles();
//	string& Label();
//	void show() const;
//	int sum() const;
//};

class Wine :private PairArray, private string
{
private:
	int num;
public:
	Wine() {};
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	void GetBottles();
	string& Label();
	void show() const;
	int sum() const;
};

#endif // WINEC_H_
