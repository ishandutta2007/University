#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int maxn = 1e4+10;

typedef pair<int,int> pii;
vector<pii> G[maxn];

int tp[maxn*50];
int vis[maxn], n, m;

void dfs1(int now, int pre)
{
  //cout << now << endl;
  vis[now] = 1;
  for (auto x : G[now])
  {
    if (x.X == pre || vis[x.X]) continue;
    tp[x.Y] = 1;
    dfs1(x.X, now);
  }
}

void dfs(int now, int pre, int pid)
{
  //cout << "[" << now << "]" << endl;
  vector<int> e;
  for (auto x : G[now])
  {
    if (x.X == pre) continue;
    if (tp[x.Y] == 1)
    {
      dfs(x.X, now, x.Y);
      if (tp[x.Y] == 1)
      {
        e.push_back(x.X);
        tp[x.Y] = 2;
      }
    }
  }
  for (auto x : G[now])
  {
    //printf("(%d, %d)\n", x.X, x.Y);
    if (tp[x.Y] == 0)
    {
      e.push_back(x.X);
      tp[x.Y] = 2;
    }
  }
  if (e.size()%2 != 0)
  {
    tp[pid] = 2;
    e.push_back(pre);
  }
  for (int i = 0, len = e.size(); i < len; i += 2)
    printf("%d %d %d\n", e[i], now, e[i+1]);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  scanf("%d%d", &n,&m);
  int u, v;
  for (int i = 1; i <= m; i++)
  {
    scanf("%d%d", &u, &v);
    G[u].push_back(pii(v, i));
    G[v].push_back(pii(u, i));
  }

  dfs1(1, 0);
  printf("%d\n", m/2);
  dfs(1, 0, -1);
  return 0;
}

