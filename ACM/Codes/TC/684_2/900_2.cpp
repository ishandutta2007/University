#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dist[100][100];

vector<int> scc[60];
int tot = 0;
int vis[60];
int belongs[60];
int G[60][60];
int de[60];
int tmp;

void dfs(int p)
{
  vis[p] = 1;
  tmp++;
  for (int i = 0; i < tot; i++) if (vis[i] == 0 && G[p][i])
    dfs(i);
}


class Autohamil
{
  public:
    string check(vector<int> z0, vector<int> z1)
    {
      int n = z0.size();
      for (int i = 0; i < n; i++)
        dist[i][z0[i]] = dist[i][z1[i]] = 1;
      for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++)
            dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
      tot = 0;
      memset(belongs, -1, sizeof(belongs));
      for (int i = 0; i < n; i++)
      {
        if (vis[i] == 0)
        {
          scc[tot].push_back(i);
          belongs[i] = tot;
          vis[i] = 1;
          for (int j = 0; j < n; j++)
            if (vis[j] == 0 && dist[i][j] && dist[j][i])
            {
              scc[tot].push_back(j);
              belongs[j] = tot;
              vis[j] = 1;
            }
          tot++;
        }
      }
      for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          G[belongs[i]][belongs[j]] |= dist[i][j];

      for (int i = 0; i < tot; i++)
        for (int j = 0; j < tot; j++)
          printf("%d%c", G[i][j], j == tot-1? '\n' : ' ');
      memset(vis, 0, sizeof(vis));
      tmp = 0;
      dfs(0);
      if (tmp != tot) return "Does not exist";
      for (int i = 0; i < tot; i++)
        for (int j = 0; j < tot; j++) if (i != j && G[i][j])
        {
          de[j]++;
        }
      printf("[%d]\n", tot);
      for (int i = 0; i < tot; i++)
        cout << de[i] << endl;
      memset(vis, 0, sizeof(vis));
      //topo-sort
      for (int k = 0; k < tot; k++)
      {
        int pos = -1;
        for (int i = 0; i < tot; i++) if (vis[i] == 0)
        {
          if (de[i] == 0)
          {
            if (pos != -1) return "Does not exist";
            pos = i;
          }
        }
        if (pos == -1)
          return "Does not exist";
        vis[pos] = 1;
        for (int i = 0; i < tot; i++) if (G[pos][i] == 1 && pos != i)
          de[i]--;
      }

    return "Exists";

   }
};
