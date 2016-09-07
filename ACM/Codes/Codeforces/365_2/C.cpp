#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int maxn = 1000020;
const int oo = 1e9+7;

ll n, w, v, u;
pii p[maxn], r;

int main()
{
  r.X = -oo;
  r.Y = -oo;
  double ans = 0;
  scanf("%I64d%I64d%I64d%I64d", &n, &w, &v, &u);
  bool leftok = true;
  for (int i = 0; i < n; i++)
  {
    scanf("%I64d%I64d", &p[i].X, &p[i].Y);
    if (u*p[i].X < v*p[i].Y) leftok = false;

    if (p[i].X > 0)
    {
      double t1 = p[i].X * 1.0 / v;
      t1 += 1.0*(w-p[i].Y)/u;
      ans = max(ans, t1);
    }
    // cout << "ans = " << ans << endl;
    if (p[i].X > r.X || (p[i].X == r.X && p[i].Y > r.Y)) r = p[i];
  }

  if (leftok || r.X <= 0)
  {
    printf("%.10f\n", w*1.0 / u);
  }
  else
  {
    printf("%.10f\n", max(ans, w*1.0 / u));
  }

  return 0;
}
