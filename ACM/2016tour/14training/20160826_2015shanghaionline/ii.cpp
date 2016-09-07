#include <bits/stdc++.h>
using namespace std;

// 1. 如果a,b都是偶数, 则gcd(a, b) = gcd(a/2, b/2)  
// 2. 如果a是奇数, b是偶数,  则gcd(a, b) =  gcd(a, b/2)  
// 3. 如果a,b都是奇数, 则gcd(a, b) = gcd((a-b)/2, b)  

int k;
const int maxn = 1020;
string Zero = "0";
string sub(string a, string b)
{
  int la = a.length(), lb = b.length();
  int c = 0;
  string ret;
  int d1, d2, d;
  for (int i = 0; i < la; i++)
  {
    d1 = a[la-i-1]-'0';
    if (lb-i-1>=0)
      d2 = b[lb-i-1]-'0';
    else
      d2 = 0;
    d2 += c;
    c = 0;
    if (d1 < d2)
    {
      d1 +=2;
      c = 1;
    }
    d = d1-d2;
    ret = char(d+'0') + ret;
  }
  while(ret[0] == '0')
    ret = ret.substr(1, ret.length()-1);
  return ret;
}

int scmp(string &a, string &b)
{
  if (a.length() != b.length())
  {
    return a.length() < b.length()? -1:1;
  }
  if (a == b) return 0;
  return a < b? -1:1;
}
string gcd(string &x, string &y)
{
  int lx = x.length();
  int ly = y.length();

  k = 0;

  while(x[lx-1] =='0' && y[ly-1] == '0')
  {
    lx--;ly--;
    k++;
  }
  while(x[lx-1] == '0')
    lx--;
  x = x.substr(0, lx);
  y = y.substr(0, ly);

  while(scmp(y, Zero) > 0)
  {
    while(y[ly-1] == '0')
      ly--;
    y = y.substr(0, ly);
    string tmp = y;
    if (scmp(x, y) < 0)
      y = sub(y, x);
    else
      y = sub(x, y);
    x = tmp;
  }
  return x;
}
char bf[maxn];

int main()
{
  int T;
  scanf("%d", &T);
  string a, b;
  for (int ka = 1; ka <= T; ka++)
  {
    a.clear(), b.clear();
    scanf("%s", bf);
    for (int i = 0, len = strlen(bf); i < len; i++)
      a.push_back(bf[i]);
    scanf("%s", bf);
    for (int i = 0, len = strlen(bf); i < len; i++)
      b.push_back(bf[i]);
    string g = gcd(a, b);
    printf("Case #%d: ", ka);
    for (int i = 0, len = g.length(); i < len; i++)
      printf("%c", g[i]);
    for (int i = 0; i < k; i++)
      printf("0");
    printf("\n");
  }
  return 0;
}
