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

const int maxn = (int)1e6+1;
int n;
ll a, b, c;
ll x[maxn], sum[maxn];
ll dp[maxn];

int main()
{
  int T;
  scanf("%d", &T);
  ConvexHull hull = ConvexHull(maxn);
  while(T--)
  {
    scanf("%d", &n);
    scanf("%I64d%I64d%I64d", &a, &b, &c);
    memset(sum, 0, sizeof(sum));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
      scanf("%I64d", &x[i]);
      sum[i] = sum[i-1] + x[i];
    }
    hull.size = 0;
    
    dp[1] = a*sum[1]*sum[1] + b*sum[1] + c;
    for (int i = 2; i <= n; i++)
    {
      hull.addLine(-2ll*a*sum[i-1], dp[i-1]+a*sum[i-1]*sum[i-1]-b*sum[i-1]);
      dp[i] = max(a*sum[i]*sum[i]+b*sum[i]+c+hull.query(sum[i]), a*sum[i]*sum[i]+b*sum[i]+c);
    }

    printf("%I64d\n", dp[n]);
  }
  return 0;
}

