#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 15;
const int oo = 1000000007;

int dp[20][1<<maxn][30];

LL inv(LL x, LL m)
{
  if (x == 1) return x;
  return inv(m % x, m)*(m - m / x) % m;
}

int co(int x)
{
  int ret = 0;
  while(x)
  {
    ret += x % 2;
    x /= 2;
  }
  return ret;
}

class ColorfulGardenHard
{
public:
  int count(string garden, string forbid)
  {
    dp[0][0][0] = 1;
    int n = garden.length();
    for (int i = 0; i < n; i++)
      for (int mask = 0; mask < (1<<n); mask++)
        for (int c = 0; c <= 27; c++) if (dp[i][mask][c] != 0 && co(mask) == i)
        {
          // cout << i << " " << mask << " " << c << " = " << dp[i][mask][c] << endl;
          for (int j = 0; j < n; j++)
          {

            if (((mask>>j) & 1) == 0 && forbid[i] != garden[j] && garden[j] != c + 'a' - 1)
            {
              // cout <<"garden : " << j << endl;
              (dp[i+1][mask|(1<<j)][garden[j] - 'a' + 1] += dp[i][mask][c]) %= oo;
              // cout << i+1 << " " << (mask|(1<<j)) << " " << garden[j] << " = " << dp[i+1][mask|(1<<j)][garden[j] - 'a' + 1] << endl;
            }
          }
        }
    LL ans = 0;
    for (int i = 0; i <= 26; i++)
      ans += dp[n][(1<<n)-1][i];
    ans %= oo;
    cout << ans << endl;

    for (int i = 0; i < n; i++) if (garden[i] != '.')
    {
      LL tmp = 1;
      LL mul = 1;
      for (int j = i + 1; j < n; j++)
        if (garden[j] == garden[i])
        {
          tmp++;
          mul = mul * tmp % oo;
          garden[j] = '.';
        }
      cout << "mul = " << mul << endl;
      ans = (ans * (int)inv(mul, oo)) % oo;
    }
    return (int)ans;
  }
};
