#ifndef MOVE_H_
#define MOVE_H_

class Move
{
private:
	double x;
	double y;

public:
	Move(double a = 0, double b = 0);
	~Move();
	void showmove()const;
	Move add(const Move& m) const;
	void reset(double a = 0, double b = 0);
};



#endif // !MOVE_H_

