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
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxN = 120;
const int oo = 0x3f3f3f3f;
const int maxM = 4000;

int dp[maxN][maxN][maxM];
int a[maxN][maxN], a2[maxN][maxN], a3[maxN][maxN];
int n, m;

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    memset(dp, -1, sizeof(dp));
    memset(a, 0, sizeof(a));
    memset(a2, 0, sizeof(a2));
    memset(a3, 0, sizeof(a3));

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
      {
        scanf("%d", &a[i][j]);
        int tmp = a[i][j];

        while (tmp % 2 == 0)
        {
          tmp /= 2;
          a2[i][j]++;
        }
        while (tmp % 3 == 0)
        {
          tmp /= 3;
          a3[i][j]++;
        }
      }

    dp[1][1][a2[1][1]] = a3[1][1];
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int k = 0; k <= 2500; k++) if (dp[i][j][k] != -1)
        {
          if (i == n && j == m)
            ans = max(min(k, dp[i][j][k]), ans);
          dp[i][j+1][k+a2[i][j+1]] = max(dp[i][j+1][k+a2[i][j+1]], dp[i][j][k] + a3[i][j+1]);
          dp[i+1][j][k+a2[i+1][j]] = max(dp[i+1][j][k+a2[i+1][j]], dp[i][j][k] + a3[i+1][j]);
        }
    printf("%d\n", ans);
  }
  return 0;
}