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

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 400000;
const int oo = 1000000007;

int n, m, k, tot;
ll f[maxn], g[maxn] ,mu[maxn];
int a[maxn];
int np[maxn], prime[maxn];
int br[maxn];
int cntbads[maxn];

ll fact[maxn];

ll inv(ll x, ll m)
{
  if (x == 1) return x;
  return inv(m % x, m)*(m - m / x) % m;
}
ll cal(ll n, ll m)
{
  if (n < m) return 0;
  return fact[n] * inv(fact[m], oo) % oo * inv(fact[n-m], oo) % oo;
}

ll pow_mod(ll a, ll b, ll p)
{
  if (b == 0) return 1;
  if (b < 0 || a == 0) return 0;
  ll ret = 1;  
  while(b) {  
    if(b & 1) ret = (ret*a)%p;  
    a = (a*a)%p;  
    b >>= 1;
  }  
  return ret%p;  
}

ll solve(int d)
{
  int tcntbad = 0, cntbad, cntd = m / d;
  // cntbad = 0;
  // for (int i = 0; i < n; i++)
  //   if (a[i] % d == 0) tcntbad++;
  int x = cntbads[d];
  // cntbad = tcntbad;
  // printf("%d: %d %d\n",d, cntbad, tcntbad);
  if (n - x > k) return 0;
  else return cal(x, n-k) * pow_mod(cntd-1, k-n+x, oo)%oo * pow_mod(cntd, n - x, oo)%oo;
}

//莫比乌斯反演
void get_prime(int n)
{
  memset(np,0,sizeof(np));
  tot=0;
  mu[1]=1;
  for (int i=2;i<=n;i++)
  {
    if (!np[i])
    {
      prime[++tot]=i;
      mu[i]=-1;
    }
    for (int j=1;j<=tot && i*prime[j]<=n;j++)
    {
      np[i*prime[j]]=1;
      if (i%prime[j]) mu[i*prime[j]]=-mu[i];
      else
      {
        mu[i*prime[j]]=0;
        break;
      }
    }
  }
}

void getcntbad()
{
  memset(cntbads, 0, sizeof(cntbads));
  for (int d = 1; d <= m; d++)
  {
    for (int j = d; j <= m; j+=d)
      cntbads[d] += br[j];
  }
}

int main()
{

  fact[0] = 1;
  for (int i = 1; i < maxn - 100; i++)
    fact[i] = fact[i-1] * i % oo;
  get_prime(maxn-100);
  while(scanf("%d%d%d", &n, &m, &k) != EOF)
  {

    memset(br, 0, sizeof(br));
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      br[a[i]]++;
    }
    getcntbad();
    for (int d = 1; d <= m; d++)
    {
      f[d] = solve(d);
    }
    for (int i=1;i<=m;i++)
    {
      g[i]=0;
      for (int j=i;j<=m;j+=i)
      {
        (g[i]+= (f[j]*mu[j/i]+oo))%=oo;
      }
    }
    // for (int i = 1; i <= m; i++)
    //   printf("%d %I64d\n", i, f[i]);
    for (int i = 1; i <= m; i++)
    {
      // if (g[i] < 0) system("pause");
      printf(i==m?"%I64d\n":"%I64d ",g[i]);
    }

    //printf("=========\n");
  }
  return 0;
}

