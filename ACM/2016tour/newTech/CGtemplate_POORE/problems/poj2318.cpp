#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

#define X first
#define Y second
using namespace std;

typedef long long ll;

typedef pair<ll, ll> vec;


const int maxn = 5200;

ll onright(vec A, vec B)
{
  return (A.X*B.Y - A.Y*B.X) > 0? true:false;
}

ll n, m, x1, y1, x2, y2;
ll U[maxn], L[maxn];
int ans[maxn];
vec V[maxn];

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r" ,stdin);
  #endif
  bool fst = 1;
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
      V[i].X = L[i]-U[i];
      V[i].Y = y2-y1;
    }
    memset(ans, 0, sizeof(ans));
    ll tx, ty;
    for (int i = 0; i < m; i++)
    {
      scanf("%lld%lld", &tx,&ty);
      for (int i = 0; i <= n; i++)
      {
        vec tl = vec(tx-U[i], ty-y1);
        vec tr = vec(tx-U[i+1], ty-y1);
        if (onright(V[i], tl) && (onright(tr, V[i+1])))
        {
          ans[i] ++;
          break;
        }
      }
    }
    if(fst) fst = false;
    else printf("\n");
    for (int i = 0; i <= n; i++)
      printf("%d: %d\n", i, ans[i]);
  }
  return 0;
}
