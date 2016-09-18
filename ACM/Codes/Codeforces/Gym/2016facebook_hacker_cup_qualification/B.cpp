#include <bits/stdc++.h>
#define L first
#define R second

using namespace std;
const int maxn = 1020;
const int oo = 1e9+7;
typedef long long ll;

typedef pair<int,int> pii;

char bf[2][maxn];
vector<pii> sg[2];

int vis[2][maxn];

int main()
{
  int T, n;
  scanf("%d", &T);

  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d", &n);
    scanf("%s %s", bf[0]+1, bf[1]+1);

    for (int p = 0; p < 2; p++)
    {
      sg[p].clear();
      int pre = -1;
      for (int i = 1; i <= n; i++)
      {
        if (pre == -1 && bf[p][i] == '.')
          pre = i;
        if (pre != -1 && (bf[p][i+1] == 'X' || i==n))
        {
          sg[p].push_back(pii(pre, i));
          pre = -1;
        }
        if (bf[p][i] == 'X')
          pre = -1;
      }
    }


    memset(vis, 0, sizeof(vis));
    int p0=0,p1=0;
    int len1 = sg[0].size();
    int len2 = sg[1].size();
    int ans = 0;
    int ans1 = 0;
    while(p0 < len1 || p1 < len2)
    {
      if (p0 == len1)
      {
        if (!vis[1][p1])
          ans++;
        p1++;
        continue;
      }
      if (p1 == len2)
      {
        if (!vis[0][p0])
          ans++;
        p0++;
        continue;
      }
      if (vis[0][p0])
      {
        p0++;
        continue;
      }
      if (vis[1][p1])
      {
        p1++;
        continue;
      }
      if (sg[0][p0].R < sg[1][p1].L)
      {
        ans++;
        p0++;
        continue;
      }
      if (sg[1][p1].R < sg[0][p0].L)
      {
        ans++;
        p1++;
        continue;
      }
      
      if (sg[0][p0].L == sg[0][p0].R || sg[1][p1].L == sg[1][p1].R)
      {
        ans++;
        p0++;
        p1++;
        continue;
      }


      if (sg[0][p0] < sg[1][p1])
      {
        for (int i = p1; i < len2; i++) if (sg[1][i].L == sg[1][i].R && sg[1][i].L <= sg[0][p0].R)
        {
          vis[1][i] = 1;
          break;
        }
        ans++;
        p0++;
      }

      else
      {
        for (int i = p0; i < len1; i++) if (sg[0][i].L == sg[0][i].R && sg[0][i].L <= sg[1][p1].R)
        {
          vis[0][i] = 1;
          break;
        }
        ans++;
        p1++;
      }
    }
    printf("Case #%d: %d\n", ka, ans);
  }
  return 0;
}
