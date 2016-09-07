#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5+10;

template <class T>
inline void rd(T &x) { char c = getchar(); x = 0;while(!isdigit(c)) c = getchar();
while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }}
template <class T> void Out(T a) { if(a < 0){putchar('-');a = -a;}if(a >= 10)Out(a / 10);putchar(a % 10 + '0');  }  

set<int> g[20];

int n, m, p, k;
int pos[20], pay[20];
vector<int> G[maxn];
int vis[maxn];
int mask;
int flag;
int s, t;

void dfspre(int p, int now, int r)
{
  if (r > k) return;
  vis[now] = 1;
  g[p].insert(now);
  for (int x : G[now]) if (!vis[x] && r < k)
  {
    dfspre(p, x, r+1);
  }
}

void dfs(int now)
{
  vis[now] = 1;
  for (int i = 0; i < p; i++)
    if (((mask>>i)&1) == 1 && g[i].count(now)) return;
  if (now == t) flag = 1;
  for (int x : G[now]) if (!vis[x])
    dfs(x);
}

int main()
{
  scanf("%d%d%d%d", &n,&m,&p,&k);
  //rd(n);
  //rd(m);
  //rd(p);
  //rd(k);

  for (int i = 0; i < p; i++)
    scanf("%d", &pos[i]);
    //rd(pos[i]);
  for (int i = 0; i < p; i++)
    scanf("%d", &pay[i]);
    //rd(pay[i]);
    
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u,&v);
    //rd(u);
    //rd(v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  scanf("%d%d", &s, &t);
  //rd(s);
  //rd(t);
  ll ans = 0x3fffffffffffffff;
  for (int i = 0; i < p; i++)
  {
    memset(vis, 0, sizeof(vis));
    dfspre(i,pos[i],0);
  }

  for (mask = 0; mask < (1<<p); mask++)
  {
    ll tmp = 0;
    for (int i=0; i<p;i++)
      tmp += (((mask>>i)&1) == 0) * pay[i];
    if (tmp > ans) continue;
    memset(vis, 0, sizeof(vis));
    flag = 0;
    dfs(s);
    if (flag)
      ans = min(ans, tmp);
  }
  printf("%I64d\n", ans);
  return 0;
}
