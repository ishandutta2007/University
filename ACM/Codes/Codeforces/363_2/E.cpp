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

const int maxn = 40;
const int oo = 0x3f3f3f3f;


double p[maxn], dp[1<<21];
double ans[maxn], sump[1<<21];

int inqu[1<<21];
int n, k;
deque<int> qu;

int count1(int mask)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (mask&(1<<i)) cnt++;

  if (cnt == k)
  {
    for (int i = 0; i < n; i++)
      if (mask&(1<<i)) ans[i] += dp[mask];
  }
  return cnt;
}

double calsum(int mask)
{
  double ret = 0.0;
  for (int i = 0; i < n; i++)
    if (mask&(1<<i)) ret += p[i];
  return ret;
}

void solve()
{
  for (int i = 0; i < (1<<n); i++)
    sump[i] = calsum(i);


  qu.clear();
  dp[0] = 1;
  inqu[0] = 1;
  qu.push_back(0);
  while(!qu.empty())
  {
    int mask = qu.front();
    qu.pop_front();

    // cout << mask << endl;

    if (count1(mask) == k)
      continue;
    for (int i = 0; i < n; i++) if (!(mask & (1<<i)))
    {
      int tmpmask = mask|(1<<i);
      dp[tmpmask] += dp[mask] * p[i] / (1.0 - sump[mask]);
      if (!inqu[tmpmask])
      {
        qu.push_back(tmpmask);
        inqu[tmpmask] = 1;
      }
    }
  }
}


int main()
{
  while(scanf("%d%d", &n, &k) != EOF)
  {
    int tcnt = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%lf", &p[i]);
      if (p[i] > 0.0) tcnt++;
    }

    if (tcnt <= k)
    {
      for (int i = 0; i < n; i++)
      {
        double tans = p[i] > 0.0? 1.0 : 0.0;
        printf("%.8f%c", tans, i == n-1? '\n' : ' ');
      }
      continue;
    }


    memset(ans, 0, sizeof(ans));
    memset(inqu, 0, sizeof(inqu));
    memset(dp, 0, sizeof(dp));
    solve();
    for (int i = 0; i < n; i++)
      printf("%.8f%c", ans[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}
