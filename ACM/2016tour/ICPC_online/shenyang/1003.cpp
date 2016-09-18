/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef ll LL;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
const int oo = 1e9+7;
const int maxn = 1e6+20;

ll fac[maxn];
ll rev[maxn];

LL inv(LL x, LL m)
{
  if (x == 1) return x;
  return inv(m % x, m)*(m - m / x) % m;
}

ll cal(ll a, ll b)
{
  if (a < b) return 0;
  if (b < 0) return 0;
  return fac[a]*rev[b]%oo*rev[a-b]%oo;
}

ll n, m, k;

ll solve()
{
  ll ret = 0;
  for (int i = 0; i < k; i++)
  {
    ll bac = max(k-i, 0ll);
    ll rest = n-i-bac-1;
    ll tmp = cal(rest-k*(m-1), m-1);
    ret = (ret+tmp)%oo;
  }
  ll rest = n-k;
  ret = (ret + cal(rest-k*(m-1), m))%oo;
  return ret;
}


int main()
{
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int T;
  fac[0] = 1;
  for (int i = 1; i < maxn; i++)
    fac[i] = fac[i-1]*i%oo;
  rev[maxn-1] = inv(fac[maxn-1], oo);
  for (int i = maxn-2; i >= 0; i--)
    rev[i] = rev[i+1]*(i+1)%oo;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    if (m == 1)
    {
      printf("%I64d\n", n);
      continue;
    }
    ll ans = solve();
    printf("%I64d\n", ans);
  }
  return 0;
}

