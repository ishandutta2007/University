#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

int arr[maxn][maxn];
int illegal[maxn][maxn];
int n, m, t, p;
int vis[maxn];
int ans;
int used;

void dfs(int r, int c, int d)
{
  if (used == t){
    ans++;
    return;
  }
  if (d > n * m)
  {
    return;
  }
  if (n*m - d + 1 < t - used) return;
  for (int i = 1; i <= t; i++)
  {
    if (vis[i] == 0 && illegal[i][arr[r-1][c]] == 0 && illegal[i][arr[r][c-1]] == 0)
    {
      arr[r][c] = i;
      vis[i] = 1;
      used++;
      dfs(r+(c==m), (c==m? 1:c+1), d+1);
      used--;
      vis[i] = 0;
    }
  }
  arr[r][c] = 0;
  dfs(r+(c==m), (c==m? 1:c+1), d+1);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d", &p);
    memset(illegal, 0, sizeof(illegal));
    memset(arr, 0, sizeof(arr));
    ans = 0;
    used = 0;
    int tx, ty;
    for (int i = 0; i < p; i++)
    {
      scanf("%d%d", &tx, &ty);
      illegal[tx][ty] = illegal[ty][tx] = 1;
    }
    memset(vis, 0, sizeof(vis));
    dfs(1, 1, 1);
 //   printf("[%d]\n", ans);
    if (ans == 0) printf("impossible\n");
    else printf("%d\n", ans);
  }
  return 0;
}

