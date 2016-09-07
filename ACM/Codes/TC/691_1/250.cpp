#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;


int vis[100], cpn[100], cpncnt;
int dist[100][100];
vi a;

ll calk(int st)
{
  ll ret = 0;
  int now = st;
  while(vis[now] == 0)
  {
    ret ++;
    vis[now] = st+1;
    now = a[now];
    if (vis[now] == st+1)
      ret = 
  }
}

class Sunnygraphs
{
public:
  int n;
  ll count(vi ta)
  {
    a = ta;
    n = a.size();
    for (int i = 0; i < n; i++)
      dist[i][a[i]] = 1;
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
    memset(cpn, -1, sizeof(cpn));
    for (int i = 0; i < n; i++) if (cpn[i] == -1)
    {
      cpn[i] = ++cpncnt;
      for (int j = 0; j < n; j++)
        if (dist[i][j] && dist[j][i])
          cpn[j] = cpn[i];
    }
    ll key0 ,key1;
    key0 = calk(0);
    key1 = calk(1);
    if (key0 == 0 || key1 == 0)
    {
      return pow(2, n) - pow(2, max(key0, key1)) + 1;
    }
    return pow(2, n - key0 - key1) * ( pow(2, key0)-1 ) * (pow(2,key1) - 1);

  }
};
