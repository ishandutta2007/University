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

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 200;
const int oo = 0x3f3f3f3f;

int a[maxn], dp[maxn][4];
int n;

int main()
{

  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    a[i]++;
  }

  memset(dp, 0x3f, sizeof(dp));

  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;

  for (int i = 1; i <= n; i++)
  {
    if (a[i] == 3 || a[i] == 4)
    {
      dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][2]));
    }
    if (a[i] == 2 || a[i] == 4)
    {
      dp[i][2] = min(dp[i][2], min(dp[i-1][0], dp[i-1][1]));
    }
    dp[i][0] = min(dp[i][0], dp[i-1][0] + 1);
    dp[i][0] = min(dp[i][0], dp[i-1][1] + 1);
    dp[i][0] = min(dp[i][0], dp[i-1][2] + 1);
  }


  printf("%d\n", min(dp[n][0], min(dp[n][1], dp[n][2])));

  return 0;
}
