#include <bits/stdc++.h>
using namespace std;
const int maxn = 400;
int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};
int cost[maxn][maxn];
int xx[maxn], yy[maxn];
int dp[maxn][maxn];
class FriendlyRobot
{
public:
  int n, allow;
  string str;
  void pre()
  {
    xx[0] = yy[0] = 1;
    int dr = 0;
    memset(cost, -1, sizeof(cost));
    for (int i = 1; i <= n;i++)
    {
      if (str[i] == 'U') dr = 0;
      if (str[i] == 'R') dr = 1;
      if (str[i] == 'D') dr = 2;
      if (str[i] == 'L') dr = 3;
      xx[i] = xx[i-1] + mx[dr];
      yy[i] = yy[i-1] + my[dr];
      for (int prei = 1; prei <= i; prei++) if ((i - prei + 1) % 2 == 0)
        cost[prei][i] = (abs(xx[i] - xx[prei-1]) + abs(yy[i] - yy[prei-1])) / 2;
    }
  }
  int findMaximumReturns(string tmpstr, int tmpint)
  {
    str = "#" + tmpstr;
    allow = tmpint;
    n = tmpstr.length();
    pre();
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int k = 0; k <= allow; k++)
      {
        dp[i][k] = -2000000000;
        for (int prei = 1; prei <= i; prei++) 
        if (k >= cost[prei][i] && cost[prei][i] >= 0)
        {
          dp[i][k] = max(dp[i][k], dp[prei-1][k-cost[prei][i]] + 1);
          ans = max(ans, dp[i][k]);
        }
      }
    return ans;
  }
};

