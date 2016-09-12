#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int maxn = 5e4+20;

int n, e;
vector<int> G[maxn];
set<int> wl[maxn];

typedef pair<int,int> pii;

pii cnt[maxn];
int vis[maxn];
int belongs[maxn];
int team[maxn];
int co[maxn];
int T;

void go(int id, int pre, int c)
{
  vis[id] = 1;
  //printf("go : %d %d %d\n", id, pre, c);
  co[id] = c+1;
  int tid = -1;
  for (int tt : wl[id])
  {
    //cout << "!!" << tt << endl;
    if (team[tt] == co[id])
    {
      tid = tt;
      break;
    }
    if (team[tt] == 0)
    {
      tid = tt;
    }
  }
  //cout << tid << endl;
  //system("pause");
  if (tid != -1)
  {
    team[tid] = c+1;
    belongs[id] = tid;
    vis[id] = true;
    for (int v : G[id]) if (!vis[v])
    {
      go(v, id, c^1);
    }
  }
  else
  {
    go(id, pre, c^1);
  }
}


int main()
{
  scanf("%d%d", &n, &e);
  for (int i = 0; i < e; i++)
  {
    int u, v;
    scanf("%d%d", &u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
    cnt[v].X++;
    cnt[u].X++;
  }
  for (int i = 1; i <= n; i++)
  {
    cnt[i].Y = i;
    int cnt;
    scanf("%d", &cnt);
    int tmp;
    while(cnt--)
    {
      scanf("%d", &tmp);
      wl[i].insert(tmp);
      T = max(T, tmp);
    }
  }
  //sort(cnt+1, cnt+n+1);
  for (int i = 1; i <= n; i++)
  {
    int id = cnt[i].Y;
    if (vis[id]) continue;
    go(id, 0, 0);
  }
  for (int i = 1; i <= n; i++)
    printf("%d ", belongs[i]);
  printf("\n");
  for (int i = 1; i <= T; i++)
  {
    if (team[i] == 0) team[i]++;
    printf("%d ", team[i]);
  }
  printf("\n");
  return 0;
}
