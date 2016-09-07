#include <bits/stdc++.h>
#define X first
/*
 *  Dijstra shortest path and minimal cost
 */
#define maxn 260000
#define INF 0x7f7f7f7f
using namespace std;
typedef pair<int, int> PII;
int N, M;
int A[600], B[600];
struct Edge
//l 为边的长度， c为费用
{
  int u, v, l, c;
  Edge(){}
  Edge(int u,int v, int l, int c):u(u),v(v),l(l),c(c){}
};
struct Node
//Node 用于 priority_queue 的记录
//v: node id
//l: length from start
//c: mincost
{
  int v, l, c;
  Node(){}
  Node(int v, int l, int c):v(v),l(l),c(c){}
  bool operator < (const Node &a) const
  //priority_queue 的优先级和 < 相反
  {
    if(l == a.l) return c > a.c;
    return l > a.l;
  }
};
vector<Edge>G[maxn];
priority_queue<Node>pq;
int dist[maxn],cost[maxn],vis[maxn],tot;
void add_edge(int u, int v, int l, int c)
{
  G[u].push_back(Edge(u, v, l, c));
  G[v].push_back(Edge(v, u, l, c));
}
void add(int x, int y, int a, int b)
{
  if (x == a) add_edge(x*M + y, a*M + b, A[b], 0);
  else add_edge(x*M + y, a*M + b, B[a], 0);
}
PII dijstra(int s, int d)
//start s, dest d
{
  memset(dist, INF, sizeof(dist));
  memset(cost, INF, sizeof(cost));
  memset(vis, 0, sizeof(vis));
  while(!pq.empty()) pq.pop();
  pq.push(Node(s, 0, 0));
  while(!pq.empty())
  {
    const Node nd = pq.top();
    pq.pop();
    if(vis[nd.v]) continue;
    vis[nd.v] = true;
    dist[nd.v] = nd.l;
    cost[nd.v] = nd.c;
    if(nd.v == d) return make_pair(dist[d], cost[d]);
    for(int i = 0, len = G[nd.v].size(); i < len; i++)
    {
      Edge& e = G[nd.v][i];
      if(!vis[e.v])
      {
        pq.push(Node(e.v, nd.l + e.l, nd.c+e.c));
      }
    }
  }
  //dist[d]: shortest distance
  //cost[d]: mincost
  return make_pair(dist[d], cost[d]);
}
int K;
int notok[600][600];
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  scanf("%d%d", &N,&M);
  for (int i = 1; i < N; i++)
    scanf("%d", &B[i]);
  for (int i = 1; i < M; i++)
    scanf("%d", &A[i]);

  scanf("%d", &K);
  for (int i = 0; i < K; i++)
  {
    int tx, ty;
    scanf("%d%d", &tx, &ty);
    notok[--tx][--ty] = 1;
  }
  tot = N*M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) if (!notok[i][j])
    {
      if (!notok[i+1][j] && i+1<N) add(i, j, i+1, j);
      if (!notok[i][j+1] && j+1<M) add(i, j, i, j+1);
    }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    int a, b, c, d;
    scanf("%d%d%d%d", &a,&b,&c,&d);
    --a,--b,--c,--d;
    int tmp = dijstra(a*M + b, c*M + d).X;
    if (tmp == INF) tmp = -1;
    printf("%d\n", tmp);
  }
  return 0;
}

