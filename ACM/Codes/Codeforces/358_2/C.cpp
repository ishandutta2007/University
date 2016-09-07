#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5+7;
const ll oo = -(1e17);

struct Edge
{
  ll v, c;
  Edge(){}
  Edge(int v, int c):v(v),c(c){}
};

ll maxdist[maxn], cnt[maxn];
ll low[maxn];
int vis[maxn];

int n;
vector<Edge> G[maxn];

void dfs(int now)
{
  vis[now] = 1;
  if (maxdist[now] > low[now])
  {
    cnt[now] = 0;
    return;
  }
  cnt[now] = 1;
  for (int i = 0, len = G[now].size(); i < len; i++) if (!vis[G[now][i].v])
  {
    Edge &e = G[now][i];
    maxdist[e.v] = max(maxdist[now] + e.c, e.c);
    dfs(e.v);
    cnt[now] += cnt[e.v];
  }
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%I64d", &low[i]), maxdist[i] = -oo;
  int v, c;
  for (int i = 1; i < n; i++)
  {
    scanf("%d%d", &v, &c);
    G[i].push_back(Edge(v-1, c));
    G[v-1].push_back(Edge(i, c));
  }
  maxdist[0] = 0;
  dfs(0);

  printf("%I64d\n", n - cnt[0]);

  return 0;
}
