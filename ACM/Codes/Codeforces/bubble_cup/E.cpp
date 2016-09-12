#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+20;

vector<int> G[maxn];
int n, c[maxn];
int vis[maxn];
int tot = 0;
vector<int> ans;


void dfs(int now, int pre)
{
  int ct = 0, to;
  ans.push_back(now);
  for (int v : G[now]) if (v != pre)
  {
    ct++;
    to = v;
  }
  //cout << "dfs" << now << " " << pre << endl;
  int de;
  if (ct%2 == 1)
    de = 0;
  else de = 1;
  if (c[now] != de)
  {
    c[to] ^= 1;
    c[now] ^= 1;
    ans.push_back(to);
    ans.push_back(now);
  }

  for (int v : G[now]) if (v != pre)
  {
    c[v] ^= 1;
    dfs(v, now);
    ans.push_back(now);
  }
  //ans.push_back(now);
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &c[i]);
    if (c[i] == -1)
    {
      tot++;
      c[i] = 0;
    }
  }
  int u, v;
  for (int i = 1; i < n; i++)
  {
    scanf("%d%d", &u,&v);
    G[v].push_back(u);
    G[u].push_back(v);
  }
  if (tot == 0)
  {
    printf("1\n");
    return 0;
  }
  dfs(1, 0);
  for (int i = 0, len = ans.size(); i < len; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}

