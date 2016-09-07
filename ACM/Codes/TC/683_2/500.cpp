#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100002;
const int mod = 1000000007;
ll cnt[maxn], ans[maxn];
ll a[maxn];
int vis[maxn];
int pre[maxn];
vector<int> G[maxn];
ll inv(ll x, ll m)
{
  if (x == 1) return x;
  return inv(m % x, m)*(m - m / x) % m;
}
void dfs(int now)
{
  vis[now] = 1;
  
  cnt[now] = 1;
  for (int i = 0, len = G[now].size(); i < len; i++)
  {
    int to = G[now][i];
    if (vis[to] != 0) continue;
    pre[to] = now;
    dfs(to);
    cnt[now] = cnt[now]*(cnt[to]+1)%mod;
  }
  ans[now] = cnt[now];
  for (int i = 0, len = G[now].size(); i < len; i++)
  {
    int to = G[now][i];
    if (pre[to] != now) continue;
    ans[now] = ans[now] + cnt[now] * inv(cnt[to]+1, mod) % mod * ans[to] % mod;
    ans[now] %= mod;
  }

}

class SubtreesCounting
{
  public:
    int sumOfSizes(int n, int a0, int b, int c, int m)
    {
      a[0] = a0;
      for (int i = 1; i <= n-2; i++)
        a[i] = (b*a[i-1]+c) % m;
      for (int i = 1; i <= n-1; i++)
      {
        int tmp = a[i-1] % i;
        G[i].push_back(tmp);
        G[tmp].push_back(i);
      }
      memset(pre, -1, sizeof(pre));
      dfs(0);
      ll ret = 0;
      for (int i = 0; i < n; i++)
        ret += ans[i];
      return ret % mod;
    }

};
