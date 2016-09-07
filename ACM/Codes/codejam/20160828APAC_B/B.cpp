#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
const int maxn = 100020;
const int oo = 1e9+7;
typedef pair<int,int> pii;
typedef ll LL;

ll a, b, k, n;

ll cta[maxn], ctb[maxn];

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

int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  // small
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%I64d%I64d%I64d%I64d", &a,&b,&n,&k);
    memset(cta,0,sizeof(cta));
    memset(ctb,0,sizeof(ctb));
    for (int i = 1; i <= k; i++)
    {
      ll tmp = pow_mod(i, a, k);
      cta[tmp] += n/k;
      if (i <= n%k) cta[tmp]++;
      cta[tmp]%=oo;
    }
    
    for (int i = 1; i <= k; i++)
    {
      ll tmp = pow_mod(i, b, k);
      ctb[tmp] += n/k;
      if (i <= n%k) ctb[tmp]++;
      ctb[tmp]%=oo;
    }

    /*
    for (int i = 0; i <= k; i++)
    {
      printf("%d %d\n", cta[i], ctb[i]);
    }
    */
    ll ans = 0;
    for (int i = 0; i < k; i++)
      ans = (ans+cta[i]*ctb[(k-i)%k])%oo;
    ll tot = 0;
    for (int i = 1; i <= k; i++)
    {
      if ((pow_mod(i,a,k)+pow_mod(i,b,k))%k==0)
      {
        tot += n/k;
        if (i <= n%k)
          tot++;
        tot%=oo;
      }
    }
    printf("Case #%d: %I64d\n", ka, (ans-tot+oo)%oo);
  }



  return 0;
}

