#include <bits/stdc++.h>


#define X first
#define Y second
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 2020;

typedef long long ll;
typedef pair<double, double> pdd;
typedef pdd Point;
int n;
Point p[maxn], tp[maxn];

double kk[maxn * 2];

int dcmp(double a, double b)
{
  if (fabs(a-b) < eps) return 0;
  return a > b? 1 : -1;
}

int solve(int o)
{
  int ret = 0;
  for (int i = 0, pos = 0; i < n; i++) if (i != o)
    kk[pos++] = atan2(p[i].Y - p[o].Y, p[i].X - p[o].X);
  sort(kk, kk + n - 1);
  for (int i = 0; i < n-1; i++)
    kk[i + n - 1] = kk[i] + 2.0*pi;
  for (int i = 0; i < n-1; i++)
  {
    int p1 = upper_bound(kk, kk + 2*n-2, kk[i]) - kk;
    int p2 = lower_bound(kk, kk + 2*n-2, kk[i] + pi/2.0) - kk;
    if (dcmp(kk[i] + pi/2, kk[p2]) <= 0) p2--;
    int p5 = lower_bound(kk, kk + 2*n-2, kk[i] + pi) - kk;
    if (dcmp(kk[p5], kk[i]+pi) >= 0) p5--;
    if (p2 >= p1) ret += p2 - p1 + 1;
    if (dcmp(kk[p5], kk[i]+pi) <= 0 && dcmp(kk[p5], kk[i] + pi/2) >= 0) ret -= 2*p5 - 2*p2;
  }
  return ret;
}

int main()
{
  //freopen("data.in", "r", stdin);
  //freopen("in.txt", "r", stdin);
  while(scanf("%d", &n) != EOF)
  {
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &p[i].X, &p[i].Y);
    ll ans = 0;
    for (int o = 0; o < n; o++)
    {
      ans += solve(o);
    }
    printf("%I64d\n", ans/3);
  }
  return 0;
}
