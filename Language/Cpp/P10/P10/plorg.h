#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
	char name[19];
	int CI;
public:
	Plorg(const char* a = "Plorg", int b = 50);
	~Plorg();
	void set_ci(int a);
	void showplorg() const;
};



#endif // !PLORG_H_

