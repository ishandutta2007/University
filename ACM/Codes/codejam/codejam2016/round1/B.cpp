#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
int ls[maxn][maxn];
int tab[maxn][maxn];
int vis[maxn];
int row[maxn], cl[maxn];
int ans[maxn];
int n;

vector<int> vi[2520];

bool fd;

bool cmp(int a, int b)
{
  return ls[a][0] < ls[b][0];
}

bool same(int pos, int r)
{
  for (int i = 0; i < n; i++)
  {
    if (tab[r][i] != 0 && tab[r][i] != ls[pos][i])
      return false;
  }
  return true;
}

bool check(int x)
{
  for (int i = 0; i < 2*n-1; i++) if (!vis[i])
  {
    int flag = false;
    for (int j = 0; j < n; j++)
      if (same(i, j)) 
      {
        flag = true;
        row[j] = i;
      }
    if (flag == false) return false;
  }
  /*
  for (int i = 0; i < n; i++)
    printf(" %d", cl[i]);
  printf("\n");

  for (int i = 0; i < n; i++)
    printf("%d\n", row[i]);
    */
  if (x == 1)
  {
    int space;
    for (int i = 0; i < n; i++) if (cl[i] == -1)
      space = i;
    for (int i = 0; i < n; i++)
      ans[i] = ls[row[i]][space];
  }
  else
  {
    int space;
    for (int i = 0; i < n; i++) if (row[i] == -1)
      space = i;
    for (int i = 0; i < n; i++)
      ans[i] = ls[cl[i]][space];
  }
  return true;
}

void dfs(int col, int x)
{
  if (col == n && !fd)
  {
    if (check(x))
      fd = true;
    return;
  }
  for (int ii = 0, len = vi[tab[0][col]].size(); ii < len; ii++)
  {
    int i = vi[tab[0][col]][ii];
    if (vis[i] || ls[i][0] != tab[0][col]) continue;
    for (int j = 1; j < n; j++)
      tab[j][col] = ls[i][j];
    vis[i] = 1;
    cl[col] = i;

    int flag = 1;
    int pre = col-1;
    if (pre >= 0 && cl[pre] == -1) pre--;
    if (pre >= 0)
    {
      for (int j = 1; j < n; j++)
        if (tab[j][pre] >= tab[j][col])
          flag = 0;
    }
    if (flag)
      dfs(col+1, x);

    for (int j = 1; j < n; j++)
      tab[j][col] = 0;
    vis[i] = false;
    cl[col] = -1;
  }
  if (x == 0 && !fd)
    dfs(col+1, 1);
}

void solve()
{
  memset(tab, 0, sizeof(tab));
  memset(vis, 0, sizeof(vis));
  memset(row, -1, sizeof(row));
  memset(cl, -1, sizeof(cl));
  int pos = 0;
  for (int i = 1; i < 2*n-1; i++)
    if (cmp(i, pos)) pos = i;
  for (int i = 0; i < n; i++)
    tab[0][i] = ls[pos][i];
  vis[pos] = 1;
  row[0] = pos;
  fd = false;
  dfs(0, 0);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    for (int i = 1; i <= 2500; i++)
      vi[i].clear();
    scanf("%d", &n);
    for (int i = 0; i < n*2-1; i++)
    {
      for (int j = 0; j < n; j++)
        scanf("%d", &ls[i][j]);
      vi[ls[i][0]].push_back(i);
    }
    solve();
    printf("Case #%d:", ka);
    for (int i = 0; i < n; i++)
      printf(" %d", ans[i]);
    printf("\n");
  }
  return 0;
}

