/*小明为什么向小红求不了婚呢？*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
  cout << "/*****************************" << endl;
  cout << "****小明和小红青梅竹马" << endl;
  cout << "****小明为了考验小红是否和他心有灵犀" << endl;
  cout << "****他心中想了一串数字" << endl;
  cout << "****他叫小红猜一猜" << endl;
  cout << "****如果小红猜的数字正好与小明所想的顺序相反" << endl;
  cout << "****他就会向小红求婚" << endl;
  cout << "*****************************/" << endl << endl;
  string xiaoming;
  string xiaohong;
  cout << "请输入小明心中所想的字符串:" << endl;
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
  cout << "小红所猜的一串数字————" + xiaohong << endl;
  return 0;
}
