#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 120;
typedef pair<int,int> pii;
typedef long long ll;


ll dp[maxn][maxn][maxn];
ll oo = 0x3f3f3f3f3f3f3f3f;
int c[maxn];
int b[maxn][maxn];
int n, m, k;


int main()
{
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 1; i <= n; i++)
    scanf("%d", &c[i]);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &b[i][j]);
  memset(dp, 0x3f, sizeof(dp));

  dp[0][0][0] = 0;

  for (int i = 1; i <= n; i++)
  {
    if (c[i] != 0)
    {
      for (int col = 0; col <= m; col++)
      {
        for (int j = 0; j <= k; j++)
        {
          if (c[i] == col)
          {
            dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i-1][j][col]);
          }
          else
          {
            dp[i][j+1][c[i]] = min(dp[i][j+1][c[i]], dp[i-1][j][col]);
          }
        }
      }
    }
    else
    {
      for (int col = 0; col <= m; col++)
      {
        for (int j = 0; j <= k; j++)
        {
          if (col != 0)
            dp[i][j][col] = min(dp[i][j][col], dp[i-1][j][col]+b[i][col]);
          for (int t = 1; t <= m; t++) if (t != col)
          {
            dp[i][j+1][t] = min(dp[i][j+1][t], dp[i-1][j][col]+b[i][t]);
          }
        }
      }
    }
  }


  ll ans = oo;

  for (int i = 1; i <= m; i++)
    ans = min(ans, dp[n][k][i]);

  if (ans == oo)
    ans = -1;
  printf("%I64d\n", ans);

  return 0;
}
