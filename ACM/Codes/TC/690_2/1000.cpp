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

LL dp[2020][2020][2][2];
const LL oo = 1000000007;

class WolfHockeyTeamEasy
{
public:
  int count(int N, int K)
  {
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= N; j++) if (abs(i-j) < 2)
      {
        if(i+j < K)
        {
          if (i <= j)
            (dp[i+1][j][0][0] += dp[i][j][0][0]*(i+1))%=oo;
          if (i >= j)
            (dp[i][j+1][0][0] += dp[i][j][0][0]*(j+1))%=oo;
        }
        else
        {
          if (i <= j)
          {
            (dp[i+1][j][1][0] += (dp[i][j][0][0]+dp[i][j][1][0])*(i+1))%=oo;
            (dp[i+1][j][1][1] += (dp[i][j][0][1]+dp[i][j][1][1])*(i+1))%=oo;
          }
          if (i >= j)
          {
            (dp[i][j+1][0][1] += (dp[i][j][0][0]+dp[i][j][0][1])*(j+1))%=oo;
            (dp[i][j+1][1][1] += (dp[i][j][1][0]+dp[i][j][1][1])*(j+1))%=oo;
          }
        }
      }

    printf("\n");
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        printf("%d %d %d %d\n", (int)dp[i][j][0][0], (int)dp[i][j][0][1], (int)dp[i][j][1][0], (int)dp[i][j][1][1]);
      }
      printf("\n\n");
    }

    return dp[N][N][1][1];
  }
};