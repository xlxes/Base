// P4.cpp: 定义控制台应用程序的入口点。
//第四章程序

#include "stdafx.h"
#include "array"
#include "vector"
#include "string"
#include "iostream"
#include "istream"
using namespace std;

int main()
{
	/*array<char, 30> xwy;
	vector<int> xmy(30);
	string d = "xwy";
	int f = d.find_first_of("x");
	cout << f;
	*/

	/*string first, last;
	char grade;
	int age;
	cout << "What is your first name?";
	getline(cin, first);
	cout << "What is your last name?";
	getline(cin, last);
	cout << "What letter grade do you deserve?";
	cin >> grade;
	cout << "What is your age?";
	cin >> age;
	cout << "Name:" << first << "," << last << endl;
	cout << "Grade:" << char(grade + 1) << endl;
	cout << "Age:" << age << endl;*/

	/*const int ArSize = 20;
	string name;
	string dessert;
	cout << "Enter your name:\n";
	getline(cin, name);
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << "for you," << name << ".\n";*/

	/*char first[20];
	char last[20];
	string name;
	cout << "FIRST:";
	cin >> first;
	cout << "LAST:";
	cin >> last;
	name = (string)first + " , " + (string)last;
	cout << "Here's the information in a single string: " << name;*/

	/*struct CandyBar
	{
		string kind;
		float weight;
		int laloli;
	};
	CandyBar snack = { "Mocha Munch",2.3,350 };		//初始化可使用指针 new与delete
	cout << "kind: " << snack.kind << endl;
	cout << "weight: " << snack.weight << endl;
	cout << "laloli: " << snack.laloli << endl;*/

	/*struct CandyBar
	{
		string kind;
		float weight;
		int laloli;
	};
	CandyBar can[3] = {{ "a",2.3f,240 }, { "b",2.4f,250 }, { "c",2.5f,260 }};
	cout << can->kind << endl << (can + 1)->weight << endl << (can + 2)->laloli << endl;*/
    
	/*struct pizz
	{
		string company;
		float diameter;
		float weight;
	};
	pizz piz;
	getline(cin, piz.company);
	cin >> piz.diameter;
	cin >> piz.weight;
	cout << "名称：" << piz.company << endl;
	cout << "直径: " << piz.diameter << endl;
	cout << "重量：" << piz.weight << endl;*/

	/*struct pizz
	{
		string company;
		float diameter;
		float weight;
	};
	pizz *piz = new pizz;
	cin >> piz->diameter;
	cin.get();		//处理回车 //与getline配合使
	getline(cin, piz->company);
	cin >> piz->weight;
	cout << "名称：" << piz->company << endl;
	cout << "直径: " << piz->diameter << endl;
	cout << "重量：" << piz->weight << endl;
	delete piz;*/

	/*struct CandyBar
	{
		string kind;
		float weight;
		int caloli;
	};
	CandyBar *can = new CandyBar[3];
	can->kind = "a";
	can->weight = 1.2f;
	can->caloli = 120;
	(can + 1)->kind = "b";
	(can + 1)->weight = 1.3f;
	(can + 1)->caloli = 130;
	(can + 2)->kind = "c";
	(can + 2)->weight = 1.4f;
	(can + 2)->caloli = 140;
	cout << can->kind << endl;
	cout << (can + 1)->caloli << endl;
	cout << (can + 2)->weight << endl;*/

	array<float, 3> runtime;
	float ave;
	cin >> runtime[0];
	cin >> runtime[1];
	cin >> runtime[2];
	ave = (runtime[0] + runtime[1] + runtime[2]) / 3;
	cout << ave;
	return 0;
}

