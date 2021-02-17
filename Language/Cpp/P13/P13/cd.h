#ifndef _CD_H
#define _CD_H_

//Ã‚1
//class Cd {
//private:
//	char performers[50];
//	char label[20];
//	int selections;
//	double playtime;
//public:
//	explicit Cd(const char* s1 = "",const char* s2 = "", int n = 0, double x = 0.0);
//	virtual ~Cd() {};
//	virtual void Report() const;
//};
//
//class Classic : public Cd
//{
//private:
//	static const unsigned mk_size = 64;
//	char m_songs[mk_size];
//public:
//	Classic(const char* song_list = "", const char* s1 = "", const char* s2 = "", int n = 0, double x = 0.0);
//	virtual void Report() const;
//};

class Cd {
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	explicit Cd(const char* s1 = "",const char* s2 = "", int n = 0, double x = 0.0);
	Cd(const Cd& d);
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};

class Classic : public Cd
{
private:
	char* songs;
public:
	explicit Classic(const char* song_list = "", const char* s1 = "", const char* s2 = "", int n = 0, double x = 0.0);
	Classic(const Classic& c);
	virtual ~Classic();
	Classic& operator=(const Classic& c);
	virtual void Report() const;
};

#endif // !_CD_H

