// P2.cpp: 定义控制台应用程序的入口点。
//对应第二章的练习题

//该头文件应该放置于最前面
#include "stdafx.h"

#include <iostream>
#include "string"

using namespace std;

void st1();
void st2();
double s2h(double tem);
double ly2au(double ly);
void time_show();

int main() {
  int distance;
  int age;
  int tem;
  double ly;

  //cout << "肖文煜-华南理工大学" << endl;
  
  //std::cout << "输入长度(long):";
  //cin >> distance;
  //cout << "等于" << 220 * distance << "码" << endl;

  st1();
  st1();
  st2();
  st2();

  cout << "请输入年龄：";
  cin >> age;
  cout << "共计" << 12 * age << "月" << endl;

  cout << "输入摄氏度:";
  cin >> tem;
  cout << tem << " degrees Celsius is " << s2h(tem) << " degrees Fahrenheit" << endl;

  cout << "请输入光年数：";
  cin >> ly;
  cout << ly << " light years = " << ly2au(ly) << " astronomical units." << endl;
  time_show();
  return 0;
}

void st1() {
  cout << "Three blind mice" << endl;
  return;
}

void st2() {
  cout << "See how they run" << endl;
  return;
}

double s2h(double tem) { return 1.8 * tem + 32.0; }

double ly2au(double ly) { return 63240 * ly; }

void time_show() {
  int hour, min;
  cout << "输入小时数：";
  cin >> hour;
  cout << "输入分钟数：";
  cin >> min;
  cout << "Time: " << hour << ":" << min << endl;
  return;
}