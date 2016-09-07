#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 60;

int n = 50, m, len;
int Ha[maxn], cnt;
int dp[1<<23];
int de[maxn];

class Gperm
{
public:
  int countfee(vector<int> x, vector<int> y)
  {
    m = x.size();
    for (int i = 0; i < m; i++)
    {
      de[x[i]]++;
      de[y[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
      if (de[i] > 1) Ha[i] = cnt++;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int mask = 0; mask < (1<<cnt); mask++)
    {
      int t = 0;
      for (int i = 0; i < m; i++)
        if ((de[x[i]] == 1 || (mask&(1<<Ha[x[i]])))&&(de[y[i]] == 1 || (mask&(1<<Ha[y[i]]))))
          t++;
      dp[mask] = t*(t+1)/2;
      for (int i = 0; i < cnt; i++) if (mask & (1<<i))
        dp[i] = min(dp[i], dp[mask^(1<<i)]+t);
    }
    return dp[(1<<cnt)-1];
  }
};
