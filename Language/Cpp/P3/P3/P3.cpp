// P3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	/*const double a = 1.2;		//转换因子
	int yc;
	cout << "请输入身高(英寸)：" << "_\b";	// \b使光标向前移一格	
	cin >> yc;
	cout << (yc*a) << "英尺";*/

	/*const int a = 12;
	const float b = 0.0254;
	const float c = 2.2;	
	double shenggao1, shenggao2, tizhong;
	cout << "英尺";
	cin >> shenggao1;
	cout << "英寸";
	cin >> shenggao2;
	cout << "体重（磅）";
	cin >> tizhong;
	cout <<"BMI: "<< (tizhong / c) / pow((a * shenggao1 + shenggao2)*b, 2) << endl;*/

	/*const int a = 60;
	double deg, min, sec;
	cout << "请以度分秒的方式输入纬度" << endl;
	cout << "输入度：";
	cin >> deg;
	cout << "输入分：";
	cin >> min;
	cout << "输入秒：";
	cin >> sec;
	cout << deg << "度" << min << "分" << sec << "秒 等于";
	cout << deg + (min + sec / a) / a;*/

	/*long long sec;
	const int h2m = 60;
	const int d2h = 24;
	const int m2s = 60;
	int day, hour, min, sec2;
	cout << "请输入秒数：";
	cin >> sec;
	day = sec / (m2s*h2m*d2h);
	sec = sec - day * d2h*h2m*m2s;
	hour = sec / (h2m*m2s);
	sec = sec - hour * h2m*m2s;
	min = sec / m2s;
	sec2 = sec - min * m2s;
	cout << day << "天" << hour << "时" << min << "分" << sec2 << "秒" << endl;*/

	/*long long person_all,person_amc;
	cout << "全世界人口";
	cin >> person_all;
	cout << "美国人口";
	cin >> person_amc;
	float a;
	a = (person_amc * float(100) / person_all) ;
	cout << "占比"<<a<<"%" << endl;*/

	/*double lichengshu;
	double youliang;
	cout << "里程数";
	cin >> lichengshu;
	cout << "耗油量";
	cin >> youliang;
	cout << "1加仑油的里程：";
	cout << lichengshu / youliang;*/

	const double a = 62.14;
	const double b = 3.875;
	float mpg;
	float amc;
	cout << "请输入(升/100km)";
	cin >> amc;
	mpg = (a*b) / amc;
	cout << "等于" << mpg;

    return 0;
}

