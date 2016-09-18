#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int maxn = 3002;
typedef long long ll;

ll a[maxn], b[maxn];
ll dp[maxn][maxn];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%I64d", &a[i]);
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b+1, b+n+1);
  memset(dp, 0x3f, sizeof(dp));
  dp[1][1] = abs(a[1]-b[1]);
  for (int i = 2; i <= n; i++)
    dp[1][i] = min(abs(a[1]-b[i]), dp[1][i-1]);
  for (int i = 2; i <= n; i++)
    dp[i][1] = abs(a[i]-b[1]) + dp[i-1][1];
  
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= n; j++)
    {
      dp[i][j] = min(dp[i][j-1], dp[i-1][j]+abs(a[i]-b[j]));
    }
  printf("%I64d\n", dp[n][n]);
}
