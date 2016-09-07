#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef ll LL;


ll n, m, k;
const int oo = 1e9+7;

// 快速幂
// (a^b) % p
LL pow_mod(LL a, LL b, LL p)
{
  LL ret = 1;  
  while(b) {  
    if(b & 1) ret = (ret*a)%p;  
    a = (a*a)%p;  
    b >>= 1;  
  }  
  return ret%p;  
}  

ll cal(int x)
{
  ll ret;
  ret = (n-x+1);
  printf("ret = %I64d\n", ret);
  if (n-x >= 0) ret = ret*pow_mod(k, n-x, oo)%oo;
  printf("ret = %I64d\n", ret);
  return ret;
}



int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  
  int T;
  scanf("%d", &T);

  while(T--)
  {
    scanf("%I64d%I64d%I64d\n", &n, &m, &k);
    ll ans = 0;
    ans += cal(m);

    printf("[%I64d]\n", ans);

    ans = (((ans - cal(m+1))%oo)+oo) % oo;
    ans = ans*pow_mod(k, n, oo) % oo;
    printf("%I64d\n", ans);

  }

  return 0;
}
