// P1.cpp: 定义控制台应用程序的入口点。

#include "array"
#include "iostream"
#include "string"
#include "vector"

int main() {
  using namespace std;
  int n = INT_MAX;                                       // int的最大值
  cout << "int is " << sizeof(int) << " bytes." << endl;  //显示int大小
  float a = 1241.2222222222222222222222222222;
  double b = 1241.2222222222222222222222222222;
  int c = 12456789;
  cout << a << endl << b << endl << c << endl;  //默认显示6位
  char d = 'D';
  cout << d << endl << int(d) << endl;  //强制类型转换

  int test[] = {1, 2, 3, 4};  //数组初始化
  vector<int> vi;
  vi.push_back(2);
  vi.push_back(4);
  cout << vi[1] << endl;
  array<int, 5> ts = {1, 2, 3, 4, 5};
  cout << ts[2] << endl;
  string hello = "hello";
  cout << hello << endl;  //想用cout输出string 必须包含头文件string而不是string.h

  return 0;
}
