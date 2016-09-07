#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
const ll maxn = 500020;
const ll oo = 1e9+7;
typedef pair<ll,ll> pii;

pii sg[maxn];

int n, m, l1, r1, a, b, c1, c2;
int ansl[maxn], ansr[maxn];
int rgl[maxn], rgr[maxn];

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
    sort(sg+1, sg+n+1);

    /*
    for (int i = 1; i <= n; i++)
    {
      printf("%d--%d\n", sg[i].X, sg[i].Y);
    }
    */
    for (int i = 1; i <= n; i++)
    {
      sg[i].X/=30000000;
      sg[i].Y/=30000000;
    }

    int bk = 0;
    for (int i = 1; i <= n; i++)
    {
      if (sg[i].Y < bk)
      {
        rgl[i] = rgl[i-1];
        ansl[i] = ansl[i-1];
      }
      else
      {
        int s = max(bk, rgl[i-1]);
        ansl[i] = ansl[i-1] + sg[i].Y-s+1;
        rgl[i] = sg[i].Y+1;
        bk = sg[i].Y + 1;
      }
    }
    int ft = 1e9+10;
    rgr[n+1] = ft;
    ansr[n+1] = 0;
    for (int i = n; i >= 1; i--)
    {
      if (sg[i].X > ft)
      {
        rgr[i] = rgr[i+1];
        ansr[i] = ansr[i+1];
      }
      else
      {
        int e = min(ft, rgr[i+1]);
        ansr[i] = ansr[i+1] + e-sg[i].X+1;
        rgr[i] = sg[i].X-1;
        ft = sg[i].X-1;
      }
    }
    
    for (int i = 0; i <= n+1; i++)
    {
      printf("%d, ", ansl[i]);
    }
    printf("\n");
    
    for (int i = 0; i <= n+1; i++)
    {
      printf("%d, ", ansr[i]);
    }
    printf("\n");

    int ans = min(ansl[n], ansr[1]);
    for (int i = 1; i <= n; i++)
    {
      if (rgl[i-1] <= rgr[i+1] + 1)
        ans = min(ans, ansl[i-1] + ansr[i+1]);
    }
    printf("Case #%d: %I64d\n", ka, ans);
  }
  return 0;
}
