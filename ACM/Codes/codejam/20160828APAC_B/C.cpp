#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
const ll maxn = 500020;
const ll oo = 1e9+7;
typedef pair<ll,ll> pii;

pii sg[maxn];
ll n, m, l1, r1, a, b, c1, c2;
ll dp[maxn][2];
ll rg[maxn][2];
ll ha[maxn];

bool cmp(pii a, pii b)
{
  if (a.X == b.X) return a.Y > b.Y;
  return a.X < b.X;
}

ll geth(ll x)
{
  return lower_bound(ha, ha+2*n+1, x)-ha;
}

int main()
{
  freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);

  int T;
  cin >> T;
  for (int ka = 1; ka <= T; ka++)
  {
    cin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m;
    sg[1].X = l1;
    sg[1].Y = r1;
    
    ll x1=l1, y1=r1, tx1, ty1;

    for (int i = 2; i <= n; i++)
    {
      tx1 = (a*x1+b*y1+c1)%m;
      ty1 = (a*y1+b*x1+c2)%m;
      x1 = tx1;
      y1 = ty1;
      sg[i].X = min(x1, y1);
      sg[i].Y = max(x1, y1);
    }
    sort(sg+1, sg+n+1, cmp);

    for (int i = 1; i <= n; i++)
    {
      ha[i*2-1] = sg[i].X;
      ha[i*2] = sg[i].Y;
    }

    sort(ha+1, ha+2*n+1);
    for (int i = 1; i <= n; i++)
    {
      //sg[i].X = geth(sg[i].X);
      //sg[i].Y = geth(sg[i].Y);
      sg[i].X /= 30000000;
      sg[i].Y /= 30000000;
      printf("%d--%d\n", sg[i].X, sg[i].Y);
    }
    memset(dp, 0x3f, sizeof(dp));
    memset(rg, 0, sizeof(rg));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
      ll s, e;
      s = max(rg[i-1][0], sg[i].X);
      e = sg[i].Y;
      if (s <= e)
      {
        dp[i][0] = dp[i-1][0] + (e-s+1);
        rg[i][0] = e+1;
      }
      else
      {
        dp[i][0] = dp[i-1][0];
        rg[i][0] = rg[i-1][0];
      }

      dp[i][1] = dp[i-1][0];
      rg[i][1] = rg[i-1][0];

      s = max(rg[i-1][1], sg[i].X);
      e = sg[i].Y;
      if (s <= e && dp[i-1][1]+(e-s+1) < dp[i][1])
      {
        dp[i][1] = dp[i-1][1] + (e-s+1);
        rg[i][1] = e+1;
      }
      else if (s > e && dp[i-1][1] < dp[i][1])
      {
        dp[i][1] = dp[i-1][1];
        rg[i][1] = rg[i-1][1];
      }
    }

    for (int i = 1; i <= n; i++)
    {
      printf("%I64d(%I64d) %I64d(%I64d)\n", dp[i][0],rg[i][0],dp[i][1],rg[i][1]);
    }

    int ans = dp[n][1];
    printf("Case #%d: %I64d\n", ka, ans);
  }
  return 0;
}
