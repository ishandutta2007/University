#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 1e4+10;
const int oo = 1e9+7;

typedef long long ll;

int n, m;
int de[maxn];
vector<int> G[maxn];
int del[maxn];
set<int> gra, vis;
int tot;
int st, tost;
int cnttot = 0;

void delp(int p)
{
  //printf("del = %d\n", p);
  int pre = -1;
  for (int v : G[p]) if (gra.count(v))
  {
    if (pre == -1)
      pre = v;
    else
    {
      cnttot++;
      printf("%d %d %d\n", pre, p, v);
      de[pre]--;
      de[v]--;
      pre = -1;
    }
  }
  gra.erase(p);
}

void dfs(int now, int pre)
{
  vis.insert(now);
  tot += de[now];
  for (int v : G[now]) if (gra.count(v) && v != pre)
  {
    if (v == st) tost = 1;
    if (!vis.count(v))
      dfs(v, now);
  }
}

bool check(int p)
{
  //printf("check = %d\n", p);
  vis.clear();
  vis.insert(p);
  for (int v : G[p]) if (!vis.count(v) && gra.count(v))
  {
    tot = 0;
    st = p, tost = 0;
    dfs(v, p);
    if (tost == 0 && (tot-1)%4 != 0)
      return false;
  }
  return true;
}

void solve()
{
  int p1, p2;
  int fd = 0;
  for (int u : gra) if (de[u]%2 == 0)
  {
    if (de[u] == 0)
    {
      delp(u);
      return;
    }
    for (int v : G[u]) if (gra.count(v) && de[v]%2==0)
    {
      p1 = u, p2 = v;
      fd = 1;
      break;
    }
    if (fd) break;
  }
  
  //printf("%d -- %d\n", p1, p2);

  if (fd == 0)
  {
    for (int v : gra) if (de[v]%2==0)
    {
      p1 = v;
      break;
    }
  }
  if (check(p1))
    delp(p1);
  else 
    delp(p2);
}

int main()
{
#ifndef ONLINE_JUDGE
  //freopen("data.in", "r", stdin);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    gra.insert(i);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    scanf("%d%d", &u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
    de[u]++;
    de[v]++;
  }
  printf("%d\n", m/2);
  for (int k = 0; k < n; k++)
  {
    solve();
  }

  if (cnttot != m/2)
    printf("%d\n", 1/0);
  return 0;
}

