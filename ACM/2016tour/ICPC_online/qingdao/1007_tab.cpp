#include<bits/stdc++.h>

using namespace std;
int vis[200][200];

int tab(int n)
{
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++)
    vis[i][(i+1)%n] = vis[(i+1)%n][i]= 1;
  int cnt = 0;
  for (int s = 0; s < n; s++)
  {
    int d = 0;
    for (int j = 0; j < n-5; j++)
    {
      int e = (s+3+j)%n;
      if (vis[s][e]) continue;
      if (vis[s][(e-1+n)%n]) continue;
      if (vis[s][(e+1)%n]) continue;
      if (vis[(s+1)%n][e]) continue;
      if (vis[(s-1+n)%n][e]) continue;
      cnt++;
      d++;
      vis[s][e] = vis[e][s] = 1;
    }
  }
  /*
  if (n == 7)
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        printf("%d%c", vis[i][j], j==n-1? '\n':' ');
  }
  */
  return cnt;
}

int main()
{
  freopen("data.out", "w", stdout);
  int n = 100;
  for (int i = 1; i <= n; i++)
  {
    printf("%d = %d\n", i ,i + tab(i));
  }
  return 0;
}

