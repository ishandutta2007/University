struct Edge
{
  int u, v, c;
  Edge(){}
  Edge(int u, int v, int c):u(u),v(v),c(c){}
};
vector<Edge> G[10020];
void addedge(int u, int v, int c)
{
  G[u].push_back(Edge(u,v,c));
  G[v].push_back(Edge(v,u,c));
}
int n, m;
int vis[10020];
int dist[10020];
int prim()
{
  int ans = 0;
  memset(vis, 0, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));
  vis[1] = 1;
  int minid, minc;
  int now = 1;
  for (int t = 1; t < n; t++)
  {
    for (int i = 0, len = G[now].size(); i < len; i++)
    {
      int to = G[now][i].v, c = G[now][i].c;
      if(vis[to] == 1) continue;
      if(dist[to] > c)
        dist[to] = c;
    }
    minid = -1;
    minc = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) if((!vis[i]) && dist[i] < minc) 
    {
      minid = i;
      minc = dist[i];
    }
    ans += minc;
    vis[minid] = 1;
    now = minid;
  }
  return ans;
}

int main()
{
  scanf("%d%d", &n, &m);
  int u,v,c;
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &u,&v,&c);
    addedge(u,v,c);
  }
  printf("%d\n" ,prim());
  return 0;
}
