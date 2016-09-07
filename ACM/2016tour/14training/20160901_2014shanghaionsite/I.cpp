#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 100020;
const int oo = 1e9+7;

typedef long long ll;
typedef pair<int,int> pii;

pii my[maxn], en[maxn];
int n, m;
map<int, int> mp;
map<int, int>::iterator itup;

bool cmpmy(pii &a, pii &b)
{
  return a.X > b.X;
}
bool cmpen(pii &a, pii &b)
{
  if (a.Y == b.Y)
    return a.X > b.X;
  else
    return a.Y > b.Y;
}

int solve()
{
  int sacri = 0;
  mp.clear();
  
  int p = 0;
  for (int i = 0; i < m; i++)
  {
    while(p < n && my[p].X >= en[i].Y)
    {
      if (!mp.count(my[p].Y)) mp[my[p].Y] = 0;
      mp[my[p].Y] ++;
      p++;
    }
    if (mp.size() == 0) return -1;
    
    int tmp;
    int mx = (--mp.end())->X;
    if (mx <= en[i].X)
    {
      tmp = mp.begin()->X;
    }
    else
    {
      itup = mp.upper_bound(en[i].X);
      tmp = itup->X;
    }
    if (tmp <= en[i].X)
      sacri++;
    mp[tmp]--;
    if (mp[tmp] == 0)
      mp.erase(tmp);
  }
  return n-sacri;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
      scanf("%d%d", &my[i].X, &my[i].Y);
    for (int i = 0; i < m; i++)
      scanf("%d%d", &en[i].X, &en[i].Y);

    sort(my, my+n, cmpmy);
    sort(en, en+m, cmpen);

    printf("Case #%d: %d\n", ka, solve());
  }
  return 0;
}
