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
const int maxn = 1e5+20;

ll a[maxn];
ll sum[maxn];
int n, l, r;
int L, R;
ll N;
ll S;

double cal()
{
  double ret = 0.0;
  ll tmpl = (l/S) * S;
  if (tmpl < l) tmpl += S;
  ll tmpr = ((r+1)/S) * S-1;
  ll cnt = (tmpr-tmpl+1)/S;
  for (int i = 1; i <= n; i++)
  {
    ll d = sum[i]-sum[i-1];
    ret += d*d*0.5*cnt/(1.0*N);
  }
  int p = n-1;
  while(tmpl > l)
  {
    ll delta = min(sum[p+1]-sum[p], tmpl-l);
    tmpl -= delta;
    ret += (sum[p+1]-sum[p]-delta*0.5)*delta/(1.0*N);
    p--;
  }
  p = 1;
  while(tmpr < r)
  {
    ll delta = min(sum[p]-sum[p-1],r-tmpr);
    ret += (delta*0.5)*delta/(1.0*N);
    tmpr += delta;
    p++;
  }
  return ret;
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d%d%d", &n, &l, &r);
    r--;
    N = r-l+1;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1]+a[i];
    }
    S = sum[n];
    //if (ka != 5) continue;
    double ans = cal();
    printf("Case #%d: %.8f\n", ka, ans);
  }
  return 0;
}

