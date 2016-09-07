#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[20][100002];
const ll mod = 1000000007;
vector<int> dvd[100002];

class DivFreed2
{
  public:
    int count(int n, int k)
    {
      for (int i = 1; i <= k; i++)
        for (int j = 2*i; j <= k; j+=i)
          dvd[j].push_back(i);

      for (int i = 1; i <= k; i++)
        dp[1][i] = 1;

      for (int i = 2; i <= n; i++)
      {
        ll sum = 0;
        for (int j = 1; j <= k; j++)
          sum += dp[i-1][j];
        sum %= mod;

        for (int j = 1; j <= k; j++)
        {
          dp[i][j] = sum;
          for (int x : dvd[j])
            dp[i][j] = (dp[i][j] + mod - dp[i-1][x]) % mod;
        }
      }
      int ans = 0;
      for (int i = 1; i <= k;i++)
        ans = (ans + dp[n][i]) % mod;
      return ans;
    }


};
