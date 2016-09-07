/*
 *  The ConvexHull Trick
 *	CF 244 div2 E
 *  斜率需要按升序排序
 *  求对应 x 的最大的 y 值
 *  nlogn
 *
 */
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
      if (hull[m].cal(x) <= hull[m+1].cal(x))
        l = m;
      else
        r = m;
    }
    return hull[r].cal(x);
  }
};

int const maxn = (int)2e5+1;
int n, a[maxn];
ll sum[maxn], ans, dans;

int main()
{
  scanf("%d", &n);
  ConvexHull ch = ConvexHull(n);
  sum[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    sum[i] = sum[i-1] + a[i];
    ans += (ll)a[i] * i;
  }
  ch.size = 0;
  for (int r = 2; r <= n; r++)
  {
    ch.addLine(r-1, -sum[r-2]);
    dans = max(dans, ch.query(a[r]) + sum[r-1]-(ll)a[r]*r);
  }
  ch.size = 0;
  for (int l = n - 1; l >= 1; l--)
  {
    ch.addLine(-(l+1), -sum[l+1]);
    dans = max(dans, ch.query(-a[l]) + sum[l] - (ll)a[l]*l);
  }
  printf("%I64d\n", ans + dans);
  return 0;
}

