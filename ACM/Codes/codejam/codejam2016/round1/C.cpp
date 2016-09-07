#include <bits/stdc++.h>

using namespace std;

const int maxn = 1020;

set<int> path, cir;
vector<int> G[maxn];
int vis[maxn], bff[maxn];
int ans, ans2, p1, p2, mxlen;
int n;

void findc(int p)
{
  cir.clear();
  while(!cir.count(p))
  {
    cir.insert(p);
    p = bff[p];
  }
  ans = max(ans, (int)cir.size());
}

void dfs(int p)
{
  path.insert(p);
  vis[p] = 1;
  if (path.count(bff[p]))
  {
    findc(p);
  }
  else if (!vis[bff[p]])
  {
    dfs(bff[p]);
  }
}

void dfs1(int p, int l)
{
  //printf("now = %d : %d\n", p, l);
  mxlen = max(mxlen, l);
  for (int v : G[p]) if (v != p1 && v != p2)
  {
    dfs1(v, l+1);
  }
}


int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      G[i].clear();
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &bff[i]);
      G[bff[i]].push_back(i);
    }
    memset(vis, 0, sizeof (vis));
    ans = 0;
    for (int i = 1; i <= n; i++) if (!vis[i])
    {
      path.clear();
      dfs(i);
    }
    ans2 = 0;
    
    for (int i = 1; i <= n; i++) if (bff[i] > i && bff[bff[i]] == i)
    {
      p1 = i, p2 = bff[i];
      //cout << p1 << "---" << p2 << endl;
      mxlen = 0;
      dfs1(p1, 1);
      //printf("mxlen = %d\n", mxlen);
      ans2 += mxlen;
      mxlen = 0;
      dfs1(p2, 1);
      ans2 += mxlen;
      //printf("mxlen = %d\n", mxlen);
    }
    //cout << ans << " " << ans2 << endl;
    printf("Case #%d: %d\n", ka, max(ans, ans2));
  }
  return 0;
}
