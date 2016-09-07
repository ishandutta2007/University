#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int v[maxn][maxn];
int tot;
int f[1<<22];
class Clicountingd2 {
  public:
  int count (vector<string> g)
  {
    int n = g.size();
    for (int i = 0; i < n; i++)
      for (int j = i; j < n; j++)
      {
        if (g[i][j] == '?')
          v[i][j] = tot++;
        else
          v[i][j] = -1;
        v[j][i] = v[i][j];
      }
    for (int mask = 1; mask < (1<<n); mask++)
    {
      int tmpmask = 0;
      bool notok = false;
      for (int i = 0; i < n && !notok; i++)
        for (int j = i+1; j < n && !notok; j++) if (((1<<i)&mask) && ((1<<j)&mask))
        {
          if (g[i][j] == '0') notok = true;
          else if(g[i][j] == '?')
            tmpmask |= (1 << v[i][j]);
        }
      if (!notok) f[tmpmask] = max(f[tmpmask], __builtin_popcount(mask));
      //cout << mask << " " << tmpmask << " " << f[tmpmask] << endl;
    }
    int ans = 0;
    for (int mask = 0; mask < (1<<tot); mask++)
    {
      for (int i = 0; i < tot; i++) if (mask & (1<<i))
        f[mask] = max(f[mask], f[mask^(1<<i)]);
      ans += f[mask];
      //cout << ans << endl;
    }
    return ans;
  }
};
