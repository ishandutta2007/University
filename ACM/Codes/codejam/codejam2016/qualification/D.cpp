#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 120;

ll K, C, S;

int vis[maxn];
vector<ll> ans;

void go(ll &now, int c, ll pos)
{
  //cout << now << ' ' << c << ' ' << pos << ' ' << endl;

  if (now <= K)
  {
    vis[now] = 1;
    now++;
  }
  if (c == C)
  {
    ans.push_back(pos);
    return;
  }
  if (now <= K)
    go(now, c+1, (pos-1)*K + now);
  else
    go(now, c+1, (pos-1)*K + 1);
}


int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%I64d%I64d%I64d", &K, &C, &S);
    memset(vis, 0, sizeof(vis));
    ans.clear();
    ll now = 1;
    while(now <= K)
    {
      go(now, 1, now);
    }
    printf("Case #%d:", ka);
    if (ans.size() <= S)
    {
      for (int i = 0, len = ans.size(); i < len; i++)
        printf(" %I64d", ans[i]);
    }
    else
      printf(" IMPOSSIBLE");
    printf("\n");
  }
  return 0;
}
