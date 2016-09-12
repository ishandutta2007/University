#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e5+20;
ll gcd(ll a, ll b)
{
  if (b == 0) return a;
  return gcd(b, a%b);
}
struct bit
{
  int s[maxn];
  int num;
  void add(int x, int z)
  {
    for (int i=x;i<=num;i+=(i&-i)) s[i]+=z;
  }
  int ask(int x)
  {
    int tmp=0;
    for (int i=x;i;i-=(i&-i)) tmp+=s[i];
    return tmp;
  }
  void clear(int n)
  {
    num=n;
    memset(s,0,sizeof(s));
  }
}bit;
int n, Q;
int a[maxn], t[maxn], ans[maxn];
map<int,int> d[maxn], pos;
pii q[maxn];
bool cmp(int a, int b)
{
  return q[a].Y < q[b].Y;
}
int main()
{
  while(scanf("%d%d", &n,&Q) != EOF)
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
      d[i].clear();
      d[i][a[i]] = i;
      for (auto g : d[i-1])
      {
        int tmp = gcd(g.X, a[i]);
        if (!d[i].count(tmp)) d[i][tmp] = g.Y;
        else d[i][tmp] = max(g.Y, d[i][tmp]);
      }
    }
    
    for (int i = 0; i < Q; i++)
    {
      scanf("%d%d", &q[i].X, &q[i].Y);
      t[i] = i;
    }
    sort(t, t+Q, cmp);
    bit.clear(n+20);
    pos.clear();
    int bk = 1;
    for (int i = 0; i < Q; i++)
    {
      int bel = t[i];
      while(bk <= q[bel].Y)
      {
        for (auto g : d[bk])
        {
          if (!pos.count(g.X))
          {
            pos[g.X] = g.Y;
            bit.add(g.Y, 1);
          }
          else if (pos[g.X] < g.Y)
          {
            bit.add(pos[g.X], -1);
            pos[g.X] = g.Y;
            bit.add(pos[g.X], 1);
          }
        }
        bk++;
      }
      ans[bel] = bit.ask(q[bel].Y) - bit.ask(q[bel].X-1);
    }
    for (int i = 0; i < Q; i++)
      printf("%d\n", ans[i]);
  }
  return 0;
}
