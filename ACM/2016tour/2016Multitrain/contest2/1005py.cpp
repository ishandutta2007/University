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
typedef pair<ll, ll> pll;

const int maxn = 1020;
const int oo = 1e9+7;

int n;

pll p[maxn], tp[maxn], o;

ll gcd(ll a, ll b)
{
  if(a < b) swap(a, b);
  ll r = a % b;
  if(r == 0) return b;
  return gcd(b, r);
}

ll powmod(ll a, ll b, ll p)
{
  ll ret = 1;  
  while(b) {  
    if(b & 1) ret = (ret*a)%p;  
    a = (a*a)%p;  
    b >>= 1;  
  }  
  return ret%p;  
}  


pll build(const pll &a, const pll &b)
{
  pll ret = pll(a.X-b.X, a.Y-b.Y);
  if (ret.X == 0 && ret.Y == 0)
    return ret;
  else if(ret.X == 0)
    return pll(0, ret.Y>0? 1:-1);
  else if(ret.Y == 0)
    return pll(ret.X>0? 1:-1, 0);
  ll d = gcd(abs(ret.X), abs(ret.Y));
  return pll(ret.X/d, ret.Y/d);
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data1.in", "r", stdin);
    // freopen("data.out", "w", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%I64d%I64d", &p[i].X, &p[i].Y);
    sort(p, p+n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (i > 0 && p[i] == p[i-1]) continue;

      // printf("(%I64d, %I64d)\n", p[i].X, p[i].Y);

      for (int j = i+1; j < n; j++)
      {
        tp[j] = build(p[j], p[i]);
      }
      // cout << "hello" << endl;
      sort(tp + i + 1, tp + n);

      int cntst = 1;
      for (int j = i+1; j < n; j++)
        if (tp[j].X == 0 && tp[j].Y == 0)
          cntst++;
      // printf("cntst[%d]\n", cntst);
      int sum = 0;
      int pre = -1;
      for (int j = i+1; j < n; j++)
      {
        if(tp[j].X == 0 && tp[j].Y == 0)
          continue;
        if (pre == -1)
        {
          pre = j;
          sum = 1;
          continue;
        }
        if (tp[j] == tp[pre])
          sum++;
        else
        {
          ans = (ans+(powmod(2, cntst, oo)-1) * (powmod(2, sum, oo)-1)%oo)%oo;
          sum = 1;
          pre = j;
        }
      }
      // printf("sum : %d\n", sum);
      if (pre != -1)
        ans = (ans+(powmod(2, cntst, oo)-1) * (powmod(2, sum, oo)-1)%oo)%oo;
      
      // printf("cntst : %d\n", cntst);
      if (cntst >= 2)
        ans = (ans+(powmod(2, cntst, oo)-1-cntst + oo)%oo) % oo;

      // printf("[%I64d]\n", ans);
    }

    printf("%I64d\n", ans);
  }
  return 0;
}
