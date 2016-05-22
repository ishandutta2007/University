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

using namespace std;
typedef long long LL;

const LL oo = 1000000009;
const int maxn = 10002000;
int plen;
bool isprime[maxn];
LL prime[maxn];
int doprime(LL N)
//prime[] 储存质数。1-based index;
{
  int nprime = 0;
  memset(isprime, true, sizeof(isprime));
  isprime[1] = false;
  for(LL i = 2; i <= N; i++)
  {
    if(isprime[i])
    {
      prime[++nprime] = i;
      for(LL j = i*i; j <= N; j+=i)
        isprime[j] = false;
    }
  }
  return nprime;
}
LL pow_mod(LL a, LL b, LL p)
//快速幂   
{
  LL ret = 1;
  a = a % p;
  while(b) {  
    if(b & 1) ret = (ret*a)%p;  
    a = (a*a)%p;  
    b >>= 1;  
  }  
  return ret%p;
}  

LL k, d, m;
LL cal(LL l, LL r)
{
  if (l == r) return 1LL;
  return (10 * oo + pow_mod(r - l + 1, k, oo) - pow_mod(r - l, k, oo)*2 + pow_mod(r - l - 1, k, oo))%oo;
}

LL solve()
{
  LL ret = 1;
  LL l, r;
  for (int i = 1; i <= plen; i++)
  {
    l = r = 0;
    while (d%prime[i] == 0) d/=prime[i],l++;
    while (m%prime[i] == 0) m/=prime[i],r++;
    if (l > r) return 0LL;
    if (r == 0) continue;
    // cout << l << " " << r << "  prime is" << prime[i] << endl;
    ret = ret*cal(l,r)%oo;
    // cout << "cal is " << cal(l, r) << endl;
  }

  // cout << "d " << d << " m " << m << endl;
  if (m != d && d != 1)
  {
    return 0;
  }

  if (m != 1)
  {
    if (m != d)
    {
      ret = ret*cal(0,1)%oo;
      // ret = (ret*pow_mod(2, k, oo) - 1)%oo;
    }
  }
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif

  plen = doprime(maxn-1);
  cin >> k >> d >> m;
  cout << solve() << endl;
  return 0;
}
