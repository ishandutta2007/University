/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
const int oo = 1e9+7;
const double pi = acos(-1.0);

const int maxn = 2e6+3;
double ans[maxn];
char str[maxn];

int in(int len)
{
  int ret = 0;
  for (int i = 0; i < len; i++)
    ret = ret*10 + str[i]-'0';
  return ret;
}

int main()
{
  ans[0] = 0.0;
  ans[1] = 1.0;
  for (int i = 2; i < maxn; i++)
  {
    ans[i] = ans[i-1] + 1.0/(i*i*1.0);
  }
  while(scanf("%s", str) != EOF)
  {
    int len = strlen(str);
    if (len > 7)
    {
      printf("1.64493\n");
      continue;
    }
    int tmp = in(len);
    if (tmp >= maxn)
    {
      printf("1.64493\n");
    }
    else
    {
      //cout <<tmp << endl;
      printf("%.5f\n", ans[tmp]);
    }
  }
  return 0;
}

