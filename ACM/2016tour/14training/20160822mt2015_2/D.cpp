#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100020;

int n, k, L;
ll ans = 0;
ll mid;
int pos[maxn], tot;

ll clockcost[maxn];
ll countercost[maxn];

void preclock()
{
  for (int i = 1; i <= n; i++)
  {
    if (i-k >= 0) clockcost[i] = clockcost[i-k];
    else clockcost[i] = 0;
    //printf("%d %d\n", i, clockcost[i]);
    clockcost[i] += pos[i] * 2;
  }
}

void precounter()
{
  for (int i = n; i >= 1; i--)
  {
    if (i+k <= n+1) countercost[i] = countercost[i+k];
    else countercost[i] = 0;
    countercost[i] += (L -pos[i]) * 2;
  }
}

ll solve(int x)
{
  ll ret = clockcost[x-1] + countercost[x];
  if (x+k <= n)
    ret = min(ret, clockcost[x-1] + countercost[x+k] + L);
  else
    ret = min(ret, clockcost[x-1] + L);
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  ll baseans;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d%d", &L, &n, &k);
    tot = 0;
    baseans = 0;
    int tp, tt;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &tp, &tt);
      if (tt >= k)
      {
        baseans += (ll)tt/k * min(L-tp, tp)*2;
        tt %= k;
      }
      for (int j = 0; j < tt; j++)
        pos[++tot] = tp;
    }
    n = tot;
    sort(pos+1, pos+n+1);
    memset(clockcost, 0, sizeof(clockcost));
    memset(countercost, 0, sizeof(countercost));
    preclock();
    precounter();
    ans = min(clockcost[n], countercost[1]);
    for (int i = 1; i <= n; i++)
    {
      ans = min(ans, solve(i));
    }
    ans += baseans;
    printf("%I64d\n", ans);
  }
  return 0;
}

