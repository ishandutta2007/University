#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
const ll maxn = 500020;
const ll oo = 1e9+7;
typedef pair<int,int> pii;

pii sg[maxn];

int n, m, l1, r1, a, b, c1, c2;
int cnt[maxn];

int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

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
    for (int i = 1; i <= n; i++)
    {
      sg[i].X/=30000000;
      sg[i].Y/=30000000;
    }
    */
    
    memset(cnt, 0, sizeof(cnt));
    int l = sg[1].X, r = sg[1].Y, p = 1;
    int tot = r - l + 1;
    for (int i = 2; i <= n; i++)
    {
      if (sg[i].Y <= r)
      {
        if (sg[i].X > l)
          cnt[p] += sg[i].X - l;
        l = max(l, sg[i].Y + 1);
      }
      else if (sg[i].X > r)
      {
        cnt[p] += r-l+1;
        p = i;
        l = sg[i].X;
        r = sg[i].Y;
        tot += r-l+1;
      }
      else
      {
        if (sg[i].X > l) cnt[p] += sg[i].X-l;
        tot += sg[i].Y-r;
        l = r+1;
        r = sg[i].Y;
        p = i;
      }
    }
    cnt[p] += r-l+1;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
      tmp = max(tmp, cnt[i]);

    printf("Case #%d: %I64d\n", ka, tot-tmp);
  }
  return 0;
}

