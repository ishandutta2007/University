/*С��Ϊʲô��С�����˻��أ�*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
  cout << "/*****************************" << endl;
  cout << "****С����С����÷����" << endl;
  cout << "****С��Ϊ�˿���С���Ƿ����������Ϭ" << endl;
  cout << "****����������һ������" << endl;
  cout << "****����С���һ��" << endl;
  cout << "****���С��µ�����������С�������˳���෴" << endl;
  cout << "****���ͻ���С�����" << endl;
  cout << "*****************************/" << endl << endl;
  string xiaoming;
  string xiaohong;
  cout << "������С������������ַ���:" << endl;
  cin >> xiaoming;

  cout << xiaoming << endl;
  int len = xiaoming.size();

  for (int i = len - 1; i >= 0; i--)
  {
    // cout << xiaoming[i];
    xiaohong.push_back(xiaoming[i]);
  }
  // cout << "+====" << endl;
  // for (int i=len;i>0;i--)
  // {
  //   xiaohong[len-i] = xiaoming[i-1];
  // }
  cout << "С�����µ�һ�����֡�������" + xiaohong << endl;
  return 0;
}
