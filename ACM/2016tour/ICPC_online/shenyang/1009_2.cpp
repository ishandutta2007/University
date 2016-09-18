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
typedef pair<ll,ll> pii;
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
const int maxn = 320;

pii vp[maxn];
int n;
ll dp1[maxn][maxn];
ll dp[maxn][maxn];
ll g[maxn][maxn]; 

ll gcd(ll x, ll y)
{
  if (x%y == 0) return y;
  else return gcd(y, x%y);
}

int main()
{
  //freopen("data.in", "r", stdin);
  int T;

  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%I64d", &vp[i].X);
    for (int i = 1; i <= n; i++)
      scanf("%I64d", &vp[i].Y);
    memset(dp1, 0, sizeof(dp1))
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        g[i][j] = gcd(vp[i].X, vp[j].X);
    for (int i = 1; i < n; i++) if (g[i][i+1] > 1)
      dp1[i][i+1] = 1;
    for (int k = 4; k <= n; k+=2)
    {
      if (k%2 == 1) continue;
      for (int i = 1; i+k-1 <= n; i++)
      {
        int ed = i+k-1;
        dp1[i][ed] |= dp1[i+1][ed-1];
        for (int j = i; j <= ed; j++) 
          dp1[i][ed] |= (dp1[i][j] & dp1[j+1][ed]);
      }
    }

    /*
    for (int k = 2; k <= n; k++)
    {
      for (int i = 1; i+k-1 <= n; i++)
      {
        int ed = i+k-1;
        for (int j = i; j <= ed; j++) 
        {
          //if (gcd(vp[j].X, vp[j+1].X) > 1)
          if (j+1 <= ed && g[j][j+1] > 1)
            dp[i][ed] = max(dp[i][ed], dp[i][j-1]+vp[j].Y+vp[j+1].Y+dp[j+2][ed]);
          dp[i][ed] = max(dp[i][ed], dp[i][j]+dp[j+1][ed]);
        }
      }
    }
    */

    printf("%I64d\n", dp[1][n]);
  }
  return 0;
}

