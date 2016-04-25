#include <bits/stdc++.h>
using namespace std;

int dp[1020][1020][3];
const int oo = 0x3f3f3f3f;
class EllysSocks
{
public:
    int getDifference(vector <int> S, int p)
    {
      sort(S.begin(), S.end());
      memset(dp, 0x3f, sizeof(dp));
      dp[0][0][0] = 0;
      int n = S.size();
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n/2; j++)
        {
          if(dp[i][j][0] != oo)
          {
            dp[i+1][j+1][1] = min(dp[i+1][j+1][1], max(dp[i][j][0], abs(S[i+1] - S[i])));
            dp[i+1][j][0] = min(dp[i][j][0], dp[i+1][j][0]);
          }
          if(dp[i][j][1] != oo)
          {
            dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1]);
          }
        }
        return min(dp[n-1][p][0], dp[n-1][p][1]);
    }
};


