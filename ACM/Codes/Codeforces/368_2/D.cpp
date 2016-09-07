#include <bits/stdc++.h>

using namespace std;

const int maxn = 1020;
const int maxq = 100020;

int vis[maxq];
int bk[maxn][maxn];

vector<int> G[maxq];

int n, m, q;
int cmd[maxq], a1[maxq], a2[maxq];
int ans[maxq];
int mem[maxn];


void go(int t, int tsum)
{
  //printf("now = %d : %d\n", t, tsum);
  ans[t] = tsum;
  for (int i = G[t].size()-1; i>=0; i--)
  {
    int p = G[t][i];
    if (cmd[p] == 4)
    {
      go(p, tsum);
    }

    else if (cmd[p] == 1)
    {
      int tmp = bk[a1[p]][a2[p]];
      bk[a1[p]][a2[p]] = 1;
      go(p, tsum + (tmp == 0));
      bk[a1[p]][a2[p]] = tmp;
    }

    else if (cmd[p] == 2)
    {
      int tmp = bk[a1[p]][a2[p]];
      bk[a1[p]][a2[p]] = 0;
      go(p, tsum - (tmp == 1));
      bk[a1[p]][a2[p]] = tmp;
    }
    
    else if (cmd[p] == 3)
    {
      int tmp = a1[p];
      for (int j = 1; j <= m; j++)
      {
        if (bk[tmp][j] == 0)
          tsum++;
        else
          tsum--;
        bk[tmp][j] ^= 1;
      }
      go(p, tsum);
      for (int j = 1; j <= m; j++)
      {
        if (bk[tmp][j] == 0)
          tsum++;
        else
          tsum--;
        bk[tmp][j] ^= 1;
      }
    }
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= q; i++)
  {
    scanf("%d", &cmd[i]);
    if (cmd[i] <= 2)
      scanf("%d%d", &a1[i], &a2[i]);
    else
      scanf("%d", &a1[i]);

    if (cmd[i] == 4)
    {
      G[a1[i]].push_back(i);
    }
    else
      G[i-1].push_back(i);
  }

  memset(bk, 0, sizeof(bk));

  go(0, 0);

  for (int i = 1; i <= q; i++)
    printf("%d\n", ans[i]);
  return 0;
}

/*
4 1 6
3 4
3 3
3 3
2 2 1
1 1 1
4 0
*/
