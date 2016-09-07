#include <bits/stdc++.h>
using namespace std;
const int maxn = 400020;
typedef pair<int, int> PII;
typedef long long ll;
const ll oo = 0x3f3f3f3f3f3f3f3f;
struct Edge
{
  int u, v;
  ll l;
  int co;
  Edge(){}
  Edge(int u,int v, ll l, int co):u(u),v(v),l(l),co(co){}
};
struct Node
{
  int v, co;
  ll l;
  Node(){}
  Node(int v, int co, ll l):v(v),co(co),l(l){}
  bool operator < (const Node &a) const
  //priority_queue 的优先级和 < 相反
  {
    return l > a.l;
  }
};
vector<Edge>G[maxn];
priority_queue<Node>pq;
ll dist[maxn],vis[maxn],tot;
void add_edge(int u, int v, ll l, int co)
{
  G[u].push_back(Edge(u, v, l, co));
}

ll dijstra(int s, int d)
//start s, dest d
{
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  while(!pq.empty()) pq.pop();
  vis[s] = 1;
  for (auto e: G[s])
  {
    pq.push(Node(e.v,e.co,e.l));
  }
  while(!pq.empty())
  {
    const Node nd = pq.top();
    pq.pop();
    if(vis[nd.v]) continue;
    if(dist[nd.v] < nd.l) continue;
    vis[nd.v] = true;
    dist[nd.v] = nd.l;
    for(int i = 0, len = G[nd.v].size(); i < len; i++)
    {
      Edge& e = G[nd.v][i];
      if(!vis[e.v])
      {
        if (nd.co == 0)
          pq.push(Node(e.v, e.co, nd.l + e.l));
        else
          pq.push(Node(e.v, e.co, nd.l + e.l + abs(nd.co-e.co)));
      }
    }
  }
  //dist[d]: shortest distance
  //cost[d]: mincost
  return dist[d];
}
int n, m;
int main()
{
  while(scanf("%d%d", &n,&m) == 2)
  {
    for (int i = 0; i <= 3*n + 100; i++)
      G[i].clear();
    int a, b, c, t;
    for (int i = 1; i <= m; i++)
    {
      scanf("%d%d%d%d", &a,&b,&c,&t);
      add_edge(a, n+i, 0, c);
      add_edge(n+i, b, t, c);
      add_edge(a, n+m+i, t, c);
      add_edge(n+m+i, b, 0, c);
    }
    ll ans = dijstra(1, n);

    for (int i = 1; i <= 3*n; i++)
    if (dist[i] < 0) printf("%d", 1/0);

    printf("%lld\n", ans);
  }
  return 0;
}

