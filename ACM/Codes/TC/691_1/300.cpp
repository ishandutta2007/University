#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
vi a;
int n, vis[2][100];
int connected;
int p0, p1;
int rest;
void go(int st)
{
  int now = st;
  while(vis[st][now] == 0)
  {
    vis[st][now] = 1;
    now = a[now];
  }
}
class Sunnygraphs
{
public:
  long long count(vector <int> ta)
  {
    a = ta;
    n = a.size();
    go(0);
    go(1);
    connected = 0;
    rest = p0 = p1 = 0;
    for (int i = 0; i < n; i++)
    {
      if (vis[0][i] == 1 && vis[1][i] == 1)
        connected = 1;
      if (vis[0][i] == 1 && vis[1][i] == 0)
        p0++;
      if (vis[0][i] == 0 && vis[1][i] == 1)
        p1++;
      if (vis[0][i] == 0 && vis[1][i] == 0)
        rest++;
    }
    if (connected)
      return (1LL << n) - ((1LL << p0) - 1) * (1LL << rest) - ((1LL << p1) - 1) * (1LL << rest);
    else
      return ((1LL << p0) - 1) * ((1LL << p1) - 1) * (1LL << rest);
  }
};
