// P6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cctype"
#include "iostream"
#include "array"
#include "string"
#include "fstream"
using namespace std;
int main()
{
	/*char ch;
	cout << "input and @ to stop";
	while (cin.get(ch) && ch != '@')
	{
		if (isalpha(ch))
		{
			if (isupper(ch))
			{
				cout << char(tolower(ch));
			}
			else
				cout << char(toupper(ch));
		}
	}*/

	/*array<double, 10>num = { 0 };
	double sum = 0;
	double aver = 0;
	double temp = 0;
	int i=0;
	int count = 0;
	while (cin >> temp && !isdigit(temp))
	{
		num[i] = temp;
		sum += num[i];
		i++;
	}
	if (i != 0)
	{
		aver = sum / i;
		cout << "sum: " << sum<<endl;
		cout << "aver: " << aver << endl;
	}
	for (int j = 0; j < i; j++)
	{
		if (num[j] > aver)
			count++;
	}
	cout << "大于平均数的个数： " << count<<endl;*/

	/*cout << "请输入以下选择：\n"
		<< "c)carnivore    p)pianist\n"
		<< "t)tree         g)game\n";
	cout << "请输入c,p,t,g:";
	char ch;
	cin >> ch;
	while (ch != 'c'&&ch != 'p'&&ch != 't'&&ch != 'g')
	{
		cout << "请输入c,p,t,g:";
		cin >> ch;
	}
	switch (ch)
	{
	case 'c':
		cout << "A map is a carnivore.\n";
		break;
	case 'p':
		cout << "A map is a pianist.\n";
		break;
	case 't':
		cout << "A map is a tree.\n";
		break;
	case 'g':
		cout << "A map is a game.\n";
		break;
	default:
		break;
	}*/

	/*const int strsize = 10;
	struct bop
	{
		char fullname[strsize];
		char title[strsize];
		char bopname[strsize];
		int preference;
	};

	cout << "Benevolent Order of Programmers name structure\n"
		<< "a.display by name        b.display by title\n"
		<< "c.display by bopname     d.display by preference\n"
		<< "q.quit\n";
	char ch;
	bop memb[5] = {
		{"xwy","eng","demon",0},
		{"xmy","jun","boom",1},
		{"zj","sup","mips",2},
		{"lzp","pol","loopy",2},
		{"oy","ana","wai",1}
	};
	cout << "enter your choice:";
	while (cin.get(ch) && ch != 'q')
	{
		switch (ch)
		{
		
		case 'a':
			for (int i = 0; i < 5; i++)
				cout << memb[i].fullname << endl;
			break;
		case 'b':
			for (int i = 0; i < 5; i++)
				cout << memb[i].title << endl;
			break;
		case 'c':
			for (int i = 0; i < 5; i++)
				cout << memb[i].bopname << endl;
			break;
		case 'd':
			for (int i = 0; i < 5; i++)
			{
				if(memb[i].preference==0)
					cout << memb[i].fullname << endl;
				else if(memb[i].preference==1)
					cout << memb[i].title << endl;
				else if(memb[i].preference==2)
					cout << memb[i].bopname << endl;
			}
			break;
		default:
			break;
		 }
		cout << "next choice:";
	}
	cout << "bye!\n";*/

	/*int money;
	string a = "税收: ";
	cout << "输入收入：" << endl;
	while (cin >> money && money >0)		//cin>>可自动检查输入是否匹配
	{										//若为非数字自动退出
		if (money < 5000)
			cout << a << 0 << endl;
		else if (money < 15000 && money >= 5001)
			cout << a << (money - 5000)*0.1 << endl;
		else if (money < 35000 && money >= 15001)
			cout << a << 10000 * 0.1 + (money - 15000)*0.15 << endl;
		else if (money > 35000)
			cout << a << 10000 * 0.1 + 20000 * 0.15 + (money - 35000)*0.2 << endl;
		else
			cout << "不可知错误！" << endl;
		cout << "输入收入：" << endl;
	}*/
	
	/*struct team
	{
		string name;
		double donate;
	};
	int number;
	int count = 0;
	cout << "输入捐献者数目" << endl;
	cin >> number;
	cin.get();	//收取回车
	team *p = new team[number];
	for (int i = 0; i < number; i++)
	{
		cout << "第" << i + 1 << "个捐赠者\n";
		cout << "姓名：";
		getline(cin, (p+i)->name);
		cout << "款项：";
		cin >> (p + i)->donate;
		cin.get();
	}
	cout << "Grand Patrons\n";
	for (int i = 0; i < number; i++)
	{
		if ((p + i)->donate > 10000)
		{
			cout << p[i].name << "    " << p[i].donate << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "None" << endl;
	cout << "Patrons\n";
	for (int i = 0; i < number; i++)
	{
		if ((p + i)->donate < 10000)
		{
			cout << p[i].name << "    " << p[i].donate << endl;
			count++;
		}
	}
	if (count == 0)
		cout << "None" << endl;
	delete[] p;*/

	/*int yy = 0, fy = 0, other = 0;
	char word[15];
	cout << "请输入单词";
	while (cin >> word)
	{
		if (isalpha(word[0]))
		{
			if (word[0] == 'q'&&strlen(word) == 1)
				break;
			else if (word[0] == 'a' || word[0] == 'i' || word[0] == 'e' ||
				word[0] == 'u' || word[0] == 'o')
				yy++;
			else
			{
				fy++;
			}
		}
		else
			other++;
	}
	cout << "元音：" << yy << endl;
	cout << "辅音：" << fy << endl;
	cout << "其他: " << other << endl;*/
	
	/*ifstream f;
	char ch;			//整行读取使用getline(f,string)
	int sum = 0;
	f.open("test.txt");
	if (!f.is_open())
	{
		cout << "can not open file\n";
		exit(EXIT_FAILURE);
	}
	f >> ch;
	while (f.good())
	{
		cout << ch;
		++sum;
		f >> ch;
	}
	cout << endl;
	if (f.eof())
		cout << "end of file.\n";
	else if (f.fail())
		cout << "data mismatch.\n";
	else
		cout << "unknow error.\n";
	cout << "总共有" << sum << "个字符" << endl;
	f.close();*/

	/*struct team
	{
		string name;
		double donate;
	};
	ifstream f;
	int number;
	int count = 0;
	string file;
	cout << "输入文件名：";
	getline(cin, file);
	f.open(file+".txt");		//打开文件
	if (!f.is_open())
	{
		cout << "can not open file!\n";
		exit(EXIT_FAILURE);
	}
	f >> number;		//读取第一个数字
	f.get();			//忽略回车
	team *p = new team[number];		//构建动态结构数组
	for (int i = 0; i < number; i++)
	{
		getline(f,p[i].name);	//读取名字,string需要这样，char可以使用f.getline()
		f >> (p + i)->donate;	//读取捐赠数
		f.get();
	}
	cout << "Grand Patrons\n";
	for (int i = 0; i < number; i++)
	{
		if ((p + i)->donate > 10000)
		{
			cout << p[i].name << "    " << p[i].donate << endl;
			count++;
		}
	}
	if (count == 0)
	cout << "None" << endl;
	cout << "Patrons\n";
	for (int i = 0; i < number; i++)
	{
		if ((p + i)->donate < 10000)
		{
			cout << p[i].name << "    " << p[i].donate << endl;
			count++;
		}
	}
	if (count == 0)
	cout << "None" << endl;
	delete[] p;
	f.close();*/
	return 0;
}

