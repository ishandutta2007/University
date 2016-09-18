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
const int maxn = 100;


ll v[20][100];
int a[100];
int dp[100][20][100];
int n;

void pre()
{
  memset(dp, 0, sizeof(dp));
  memset(v, 0, sizeof(v));
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 10; j++)
    {
      for (int s = 0; s <= 87; s++)
      {
        dp[i][j][s] = 0;
        ll pre = s-a[i];
        if (pre < 0) continue;
        for (int t = 0; t < i; t++)
          dp[i][j][s] += dp[t][j-1][pre];
      }
    }
  for (int i = 1; i <= 10; i++)
    for (int j = 0; j <= 87; j++)
      for (int t = 0; t <= n; t++)
        v[i][j] += dp[t][i][j];
}

int main()
{
  freopen("data.in", "r", stdin);
  pre();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  pre();

  //printf("%I64d\n", v[2][0]);
  for (int i = 1; i <= 10; i++)
    printf("%I64d\n", v[i][87]);
  return 0;
}

