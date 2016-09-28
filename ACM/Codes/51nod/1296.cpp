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
const int maxn = 5e3+20;

int mark[maxn];

ll dp[maxn][maxn];
ll sum[maxn];
int n, k, l;
int solve()
{
  dp[1][1] = 1;
  sum[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    if (s[i] == 0 && s[i-1] == 0)
    {
      for (int j = 1; j < i; i++)
      {
        dp[i][j] = dp[i-1][j];
        sum[i] += dp[i][j];
      }
      dp[i][i] = sum[i];
      sum[i] += dp[i][i];
    }
    if (s[i] == 0 && s[i-1] == 1)
    {
      
    }
  }

}


int main()
{
  scanf("%d%d%d", &n, &k, &l);
  int tmp;
  for (int i = 0; i < k; i++)
  {
    scanf("%d", &tmp);
    if (mark[tmp] == 2) {
      puts("0");
      return 0;
    }
    mark[tmp] = 1;
  }
  for (int i = 0; i < l; i++)
  {
    scanf("%d", &tmp);
    if (mark[tmp] == 1) {
      puts("0");
      return 0;
    }
    mark[tmp] = 2;
  }
  pre();
  tmp = solve();
  printf("%d\n", tmp);
  return 0;
}

