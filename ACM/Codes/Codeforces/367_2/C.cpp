#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;

const int maxn = 100200;

ll dp[maxn][2], n, c[maxn];
string str[maxn][2];

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  for (int i = 1; i <= n; i++)
  {
    cin >> str[i][0];
    str[i][1].assign(str[i][0].rbegin(), str[i][0].rend());
  }

  str[0][0] = str[0][1] = "";
  memset(dp, 0x3f, sizeof(dp));
  dp[0][1] = dp[0][0] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (str[i][j] >= str[i-1][0])
        dp[i][j] = min(dp[i][j], dp[i-1][0] + j*c[i]);
      if (str[i][j] >= str[i-1][1])
        dp[i][j] = min(dp[i][j], dp[i-1][1] + j*c[i]);
    }
  }

  ll ans = min(dp[n][0], dp[n][1]);
  if (ans >= 0x3f3f3f3f3f3f3f3f) ans = -1;
  cout << ans << endl;

  return 0;
}
