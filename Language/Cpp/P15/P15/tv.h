#ifndef TV_H_
#define TV_H_

#include <iostream>
using namespace std;

class Remote;		//ǰ������
class Tv
{
private:
	int state;			//������
	int volume;			//����
	int maxchannel;		//���Ƶ����
	int channel;		//��ǰƵ��
	int mode;			//ģʽ(����/����)
	int input;			//TV/DVD
public:
	friend class Remote;
	enum {off,on};	//����״̬
	enum {minval,maxval = 20};	//��������
	enum {antenna,cable};		//����/��������
	enum {tv,dvd};				//Tv / DVD����

	//���캯��
	Tv(int s = off, int mc = 125) :state(s), volume(s), maxchannel(mc), channel(2), mode(cable), input(tv) {}
	//��������
	~Tv() {}
	//���غ���
	void onoff() { state = (state == on) ? off : on; }
	//���ص�ǰ����״̬
	bool ison() { return state == on; }
	//����+
	bool volup();
	//����-
	bool voldown();
	//Ƶ��+
	void chanup();
	//Ƶ��-
	void chandown();
	//����ģʽ
	void setmode() { mode = (mode == antenna) ? cable : antenna; }
	//��������
	void setinput() { input = (input == tv) ? dvd : tv; }
	//��ʾ����
	void show() const;
	//���û���/����ģʽ
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
	enum { regular, interaction };	//���� / ����
	//Ĭ�Ϲ��� 
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

