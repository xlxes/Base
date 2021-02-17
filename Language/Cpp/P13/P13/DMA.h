#ifndef _DMA_H_
#define _DMA_H_

#include <iostream>

using namespace std;

class ABC
{

public:
	ABC();
	~ABC();
	virtual void View() = 0;	//必须有一个纯虚函数
};

class baseDMA :public ABC
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* i = "null", int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA() {};
	baseDMA& operator=(const baseDMA& rs);
	friend ostream& operator<<(ostream& os, const baseDMA& rs);
	virtual void View();
};

class lacksDMA :public baseDMA
{
private:
	enum {col_len = 40};
	char color[col_len];
public:
	lacksDMA(const char* c = "blank", const char* i = "null", int r = 0);
	lacksDMA(const char* c, const baseDMA& rs);
	friend ostream& operator<<(ostream& os, const lacksDMA& rs);
	virtual void View();
};

class hasDMA :public baseDMA
{
private:
	char* style;
public:
	hasDMA(const char* s = "none", const char* i = "null", int r = 0);
	hasDMA(const char* s, const baseDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& rs);
	friend ostream& operator<<(ostream& os, const hasDMA& rs);
	virtual void View();
};

#endif // !_DMA_H_

