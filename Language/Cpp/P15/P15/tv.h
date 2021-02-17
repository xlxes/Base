#ifndef TV_H_
#define TV_H_

#include <iostream>
using namespace std;

class Remote;		//前向声明
class Tv
{
private:
	int state;			//开关量
	int volume;			//音量
	int maxchannel;		//最大频道数
	int channel;		//当前频道
	int mode;			//模式(无线/有线)
	int input;			//TV/DVD
public:
	friend class Remote;
	enum {off,on};	//开关状态
	enum {minval,maxval = 20};	//音量设置
	enum {antenna,cable};		//天线/有线连接
	enum {tv,dvd};				//Tv / DVD输入

	//构造函数
	Tv(int s = off, int mc = 125) :state(s), volume(s), maxchannel(mc), channel(2), mode(cable), input(tv) {}
	//析构函数
	~Tv() {}
	//开关函数
	void onoff() { state = (state == on) ? off : on; }
	//返回当前开关状态
	bool ison() { return state == on; }
	//音量+
	bool volup();
	//音量-
	bool voldown();
	//频道+
	void chanup();
	//频道-
	void chandown();
	//设置模式
	void setmode() { mode = (mode == antenna) ? cable : antenna; }
	//设置输入
	void setinput() { input = (input == tv) ? dvd : tv; }
	//显示所有
	void show() const;
	//设置互动/常规模式
	void set_rmode(Remote& r);
};

class Remote
{
private:
	int state;
	int mode;		//tv / dvd
	int rmode;		//regular / interaction
public:
	friend class Tv;
	enum { regular, interaction };	//常规 / 互动
	//默认构造 
	Remote(int m = Tv::tv, int r = regular) :mode(m), rmode(r) {}
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void changeup(Tv& t) { t.chanup(); }
	void changedown(Tv& t) { t.chandown(); }
	void setchan(Tv& t, int c) { t.channel = c; }
	void setmode(Tv& t) { t.setmode(); }
	void setinput(Tv& t) { t.setinput(); }
	void mode_show() const { cout << "Remote pretent mode is " << (rmode == regular? "regular":"interaction") << endl; }
};

#endif // !TV_H_

