#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> vec;

const int maxn = 1200;

ll onright(vec A, vec B)
{
  return (A.X*B.Y - A.Y*B.X) > 0? true:false;
}

ll n, m, x1, y1, x2, y2;
ll U[maxn], L[maxn];

int ans[maxn], ans1[maxn];
vec V[maxn], seg[maxn];

int solve(ll x, ll y)
{
  int ret = 0;
  int low = 0, high = n + 1, mid;
  while(low <= high)
  {
    int mid = (low+high)/2;
    vec tv = vec(x-U[mid], y-y1);
    if (onright(V[mid], tv))
    {
      ret = max(ret, mid);
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r" ,stdin);
  #endif
  while(scanf("%lld%lld%lld%lld%lld%lld", &n,&m,&x1,&y1,&x2,&y2) == 6)
  {
    if (n == 0) break;
    U[0] = x1;
    L[0] = x1;
    U[n+1] = x2;
    L[n+1] = x2;
    V[n+1] = V[0] = vec(0, y2-y1);
    for (int i = 1; i <= n; i++)
    {
      scanf("%lld%lld", &U[i], &L[i]);
      seg[i] = vec(U[i], L[i]);
    }
    sort(seg+1, seg+n+1);

    for (int i = 1; i <= n; i++)
    {
      U[i] = seg[i].X;
      L[i] = seg[i].Y;
      V[i].X = seg[i].Y - seg[i].X;
      V[i].Y = y2-y1;
    }

    memset(ans, 0, sizeof(ans));
    memset(ans1,0, sizeof(ans1));
    ll tx, ty;
    for (int i = 0; i < m; i++)
    {
      scanf("%lld%lld", &tx,&ty);
      int id = solve(tx, ty);
      ans[id] ++;
    }
    printf("Box\n");
    for (int i = 0; i <= n; i++)
      ans1[ans[i]]++;
    for (int i = 1; i <= m; i++) if (ans1[i] > 0)
      printf("%d: %d\n", i, ans1[i]);
  }
  return 0;
}
