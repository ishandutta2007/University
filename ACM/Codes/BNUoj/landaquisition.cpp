#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Line
{
  ll a, b;
  ll cal(ll x) { return a*x+b; }
  Line(ll a, ll b):a(a),b(b){}
  Line(){}
};
struct ConvexHull
{
  int size;
  Line *hull;
  ConvexHull(int maxsize)
  {
    hull = new Line[++maxsize], size = 0;
  }
  bool isbad(ll cur, ll pre, ll ne)
  {
    Line c = hull[cur], p = hull[pre], n = hull[ne];
    return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
  }
  void addLine(ll a, ll b)
  {
    hull[size++] = Line(a,b);
    while (size > 2 && isbad(size - 2, size - 3, size - 1))
      hull[size-2] = hull[size-1], size--;
  }
  ll query(ll x)
  {
    int l = -1, r = size - 1;
    while (r - l > 1)
    {
      int m = (l + r) / 2;
      if (hull[m].cal(x) >= hull[m+1].cal(x))
        l = m;
      else
        r = m;
    }
    return hull[r].cal(x);
  }
};

const int maxn = (int)5e4+1;
typedef pair<int, int> pii;
int n;
ll dp[maxn];
vector<pii> vpii, tmp;
bool cmp(pii &a, pii &b)
{
  return a.first == b.first? a.second > b.second : a.first > b.first;
}
int main()
{
  scanf("%d", &n);
  int th, tw;
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &th, &tw);
    tmp.push_back(pii(th, tw));
  }
  sort(tmp.begin(), tmp.end(), cmp);
  vpii.push_back(tmp[0]);
  for (int i = 1; i < n; i++)
    if (tmp[i].second > vpii.back().second)
      vpii.push_back(tmp[i]);
  n = vpii.size();
  ConvexHull hull = ConvexHull(n);
  hull.size = 0;
  dp[0] = (ll)vpii[0].first*vpii[0].second;
  for (int i = 1; i < n; i++)
  {
    hull.addLine(vpii[i].first, dp[i-1]);
    dp[i] = hull.query(vpii[i].second);
  }

  printf("%I64d\n", dp[n-1]);

  return 0;
}
