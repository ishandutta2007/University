#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int oo = 0x3f3f3f3f;
const int maxn = 100000;

int to10(int x)
{
  int ret = 0;
  int mod = 1;
  for (int i = 0; i < 31; i++)
  {
    ret += ((x>>i)&1) * mod;
    mod *= 10;
  }
  return ret;
}

int to2(int x)
{
  int ret = 0;
  int mod = 1;
  while(x)
  {
    ret += mod * (x%10);
    mod *= 2;
    x /= 10;
  }
  return ret;
}

int build(int x)
{
  int de = to10(x);
  int bi = to2(de);
  int len = 0;
  x = bi;
  while(x)
  {
    len++;
    x /= 2;
  }

  int last = (1<<len) - 1;
  if(((de - bi) & last) == 0)
  {
    cout << de << " : " << bi << endl;
    cout << "true" << endl;
    return 1;
  }
  // cout << "false" << endl;
  return 0;
}


int main()
{
    int n = 1000;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
      cnt += build(i);
    }    

    cout << endl;
    cout << cnt << endl;

    return 0;
}