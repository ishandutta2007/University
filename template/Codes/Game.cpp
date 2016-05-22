#include <bits/stdc++.h>
using namespace std;

//Wythoff Game
//A first
//B second
//当 n 过大时需要用高精度处理，和精确的黄金比例数
int main()
{
  int T;
  scanf("%d", &T);
  
  while(T--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a > b) swap(a, b);
    
    int k = b - a;
    if(a == (int)((k)*(1+sqrt(5.0))/2.0)) cout << "B" << endl;
    else cout << "A" << endl;
    
  }
  return 0;
}
