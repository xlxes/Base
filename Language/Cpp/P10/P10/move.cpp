#include "pch.h"
#include "move.h"
#include <iostream>
Move::Move(double a, double b)
{
	x = a;
	y = b;
}

Move::~Move()
{
}

void Move::showmove()const
{
	using std::endl;
	using std::cout;
	cout << "x : " << x << endl;
	cout << "y : " << y << endl;
}

Move Move::add(const Move& m) const
{
	return Move(x + m.x, y + m.y);
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
