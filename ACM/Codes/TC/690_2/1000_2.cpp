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

LL dp[2020][2020][2];
LL a[4020];
LL b[2020][2020];
const LL oo = 1000000007;

class WolfHockeyTeamEasy
{
public:
  int k;
  LL inv(LL x)
  {
    if (x == 1) return x;
    return inv(oo % x)*(oo - oo / x) % oo;
  }
  LL cal(int n, int k)
  {
    // cout << n << " " << k << endl;
    if (k == 0) return 1;
    return ((a[n]*inv(a[k])%oo)*inv(a[n-k]))%oo;
  }

  int f(int num, int line, int m)
  {
    if (num < 0 || line < 0) return 0;
    if (dp[num][line][m] != -1) return dp[num][line][m];
    if (line == 0 && m == 1) 
    {
      dp[num][line][m] = 1;
      return dp[num][line][m];
    }
    if (m == 1)
    {
      // cout << "hello" << endl;
      // cout << num << "  " << line << endl;
      // dp[num][line][m] = cal(num, line*2) * b[line][line]%oo;
      dp[num][line][m] = f(num-1, line-1, 1) + f(num-2, line-2, 1) + f(num-2, line-1, 1);
      if (num == 2 && line == 1)
        dp[num][line][m] -= f(num-2, line-1, 1);
      dp[num][line][m] %= oo;
      // cout << dp[num][line][m] << endl;
      // system("pause");
      // cout << "hello" << endl;
      return dp[num][line][m];
    }

    if (m == 0 && num - 1 < k)
    {
      dp[num][line][m] = 0;
      return dp[num][line][m];
    }
    dp[num][line][m] = (f(num-1, line-1, 0) + f(num-2, line-2, 1) + f(num-2, line-1, 1))%oo;
    return dp[num][line][m];
  }

  int count(int N, int K)
  {
    k = K+1;
    a[0] = 1;
    for (int i = 1; i <= N*3; i++)
      a[i] = (a[i-1] * i)%oo;
    memset(dp, -1, sizeof(dp));

    b[1][1] = 1;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
      {
        if (i+1 <= j)
        {
          b[i+1][j] += b[i][j];
          b[i+1][j] %= oo;
        }
        b[i][j+1] += b[i][j];
        b[i][j+1] %= oo;
      }

    LL tmp = f(2*N, N, 0);
    // cout << tmp << endl;
    tmp = tmp * a[N] * 2 % oo;
    return tmp;
  }
}py;

int main()
{
  cout << py.count(2, 0) << endl;
  return 0;
}