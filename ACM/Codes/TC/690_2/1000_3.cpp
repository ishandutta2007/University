#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

LL dp[1020][1020][2];
const LL oo = 1000000007;

class WolfHockeyTeamEasy
{
public:

  int count(int n, int k)
  {
    dp[1][0][0] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= i; j++)
      {
        int num = 2*n-1-i-j;
        if (i < n)
        {
          (dp[i+1][j][0] += dp[i][j][0]) %= oo;
          (dp[i+1][j][1] += dp[i][j][1]) %= oo;
            if (num >= k)
              (dp[i+1][j][1] += dp[i][j][0]) %= oo;
        }
        if (j < i)
        {
          (dp[i][j+1][num >= k] += dp[i][j][0]) %= oo;
          (dp[i][j+1][1] += dp[i][j][1]) %= oo;
        }
      }
    
    LL ans = dp[n][n][1] * 2;
    for (LL i = 1; i <= n; i++)
      (ans*=i)%=oo;
    return ans;
  }
};
