#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;
vector<pii> sg;
int n;
int vis[18880];

int main()
{
  while(scanf("%d", &n) != EOF)
  {
    if (n == 0) break;
    sg.clear();
    for (int i = 0; i < n; i++)
    {
      int d, m;
      scanf("%d", &d);
      m = d;
      for (int j = 0; j < i; j++)
      {
        int pd = sg[j].Y;
        int pm = sg[j].X;
        if (d <= pd)
          m = max(pm+d*2, m);
        else
          m = max(pm+pd*2, m);
      }
      sg.push_back(pii(m, d));
    }
    sort(sg.begin(), sg.end());
    for (int i = 0; i < n; i++)
    {
      //printf("(%d -- %d)\n", sg[i].X, sg[i].Y);

      memset(vis, 0, sizeof(vis));
      for (int j = 0; j < n; j++) if (sg[j].Y > sg[i].Y)
      {
        for (int k = sg[j].X-sg[j].Y; k < sg[j].X+sg[j].Y; k++)
          vis[k] = 1;
      }
      bool has = 0;
      for (int j = sg[i].X-sg[i].Y; j < sg[i].X+sg[i].Y; j++)
        if (vis[j] == 0)
          has = true;
      if (has)
        printf("%d ", i+1);
    }
    printf("\n");
  }

  return 0;
}
