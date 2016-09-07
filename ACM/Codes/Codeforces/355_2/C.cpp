#include <bits/stdc++.h>
using namespace std;
const int maxn = 200002;
const int oo = (int)1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;


char str[maxn];
int n;

int cal(char x)
{
  int a, ret = 0;
  if (x >= '0' && x <= '9')
    a = x - '0';
  else if (x >= 'A' && x <= 'Z')
    a = x - 'A' + 10;
  else if (x >= 'a' && x <= 'z')
    a = x - 'a' + 36;
  else if (x == '-')
    a = 62;
  else
    a = 63;

  while(a)
  {
    ret += a % 2;
    a /= 2;
  }

  return 6 - ret;
}

int pow3(int cnt)
{
  ll ret = 1;
  for (int i = 1; i <= cnt; i++)
    ret = ret * 3 % oo;
  return ret;
}

int main()
{
  scanf("%s", str);
  n = strlen(str);
  
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    cnt += cal(str[i]);
  }

  
  cout << pow3(cnt) << endl;

  return 0;
}
