#define ll long long
#define maxn 320
using namespace std;
int G[maxn][maxn], layer[maxn];
int m, n;
bool vis[maxn];
bool countLayer()
{
  queue<int>q;
  memset(layer, 0xff, sizeof(layer));
  layer[1] = 0;q.push(1);

  while(!q.empty())
  {
    int v = q.front();q.pop();
    for(int j = 1; j <= n; j++)
      if(G[v][j] > 0 && layer[j] == -1)
      {
        layer[j] = layer[v] + 1;
        if(j == n) return true;
        else q.push(j);
      }
  }
  return false;
}
int Dinic()
{
  int i;
  int maxflow = 0;
  deque<int> q;
  while(countLayer())
  {
    q.push_back(1);
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    while(!q.empty())
    {
      int nd = q.back();
      if(nd == n)
      {
        int minc = 1000000000;
        int minstart;
        for(i = 1; i < q.size();i++)
        {
          int vs = q[i-1];
          int ve = q[i];
          if(G[vs][ve] > 0 && minc > G[vs][ve])
          {
            minc = G[vs][ve];
            minstart = vs;
          }
        }
        maxflow += minc;
        for(i = 1; i < q.size(); i++)
        {
          int vs = q[i-1];
          int ve = q[i];
          G[vs][ve] -= minc;
          G[ve][vs] += minc;
        }
        while(!q.empty() && q.back() != minstart)
        {
          vis[q.back()] = false;
          q.pop_back();
        }
      }else{
        for(i = 1; i <= n; i++)
          if(G[nd][i] > 0 && layer[i] == layer[nd] + 1 && !vis[i])
          {
            vis[i] = true;
            q.push_back(i);
            break;
          } 
        if(i > n) q.pop_back();
      }
    }

  }

  return maxflow;
}

int main()
{
  while(scanf("%d%d", &m, &n) != EOF)
  {
    int s, e, c;
    memset(G, 0, sizeof(G));
    for(int i = 0; i < m; i++)
    {
      scanf("%d%d%d",&s,&e,&c);
      G[s][e] += c;
    }
    printf("%d\n", Dinic());
  }
  return 0;
}
