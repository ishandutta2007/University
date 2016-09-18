#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+20;
const ll oo = 1e18+20;

ll n, g, p;
ll t, r;
int v[maxn];
ll sum[maxn];
ll deep;

bool check2(ll mid)
{
  ll now = mid;
  ll maxtmp = 0, maxtmp1 = 0;
  ll tt = t;
  for (int i = 0; i < n; i++)
  {
    now += v[i];
    if (now < 0) now = 0;

    if (i < r) maxtmp = max(maxtmp, now);
    maxtmp1 = max(maxtmp1, now);
    if (now >= g && i < r)
      return true;
    if (now >= g && tt)
      return true;
  }
  ll delta = now - mid;
  if (delta <= 0) return false;
  if ((g-maxtmp)/delta <= tt)
    return true;
  if ((g-maxtmp1)/delta <= tt-1)
    return true;
  return false;
}
bool check1(ll mid)
{
  if (mid >= g) return true;
  ll now = mid;
  ll tt = t;
  for (int i = 0; i < n; i++)
  {
    now += v[i];
    if (now < 0) now = 0;
    if (now >= g && i < r)
      return true;
    if (now >= g && tt)
      return true;
  }
  return false;
}

ll solve1() {
  ll ret = oo;
  ll low = 0, high = oo, mid;
  while(low <= high)
  {
    mid = (low+high)/2;
    if (check1(mid))
    {
      ret = min(ret, mid);
      high = mid-1;
    }
    else
      low = mid+1;
  }
  return ret;
}

ll solve2() {
  //cout << "!!" << endl;
  ll ret = oo;
  ll low = max(-deep, 0ll), high = oo, mid;
  while(low <= high)
  {
    mid = (low+high)/2;
    
    //cout << "mid = " << mid << endl;

    if (check2(mid))
    {
      ret = min(ret, mid);
      high = mid-1;
    }
    else
      low = mid+1;
  }
  return ret;
}

int main()
{
  //freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%lld%lld%lld", &n, &g, &p);
    deep = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &v[i]);
      if (i == 0) sum[i] = v[i];
      else sum[i] = sum[i-1] + v[i];
      deep = min(sum[i], deep);
    }
    r = p % n;
    if (r == 0)
      r = n;
    t = (p-r)/n;
    ll ans = g;
    ans = min(ans, solve1());
    //cout << check2(5) << endl;
    //cout << solve1() << " " << solve2() << endl;
    //cout << sum[n-1] << endl;
    if (sum[n-1] >= 0) ans = min(ans, solve2());
    printf("Case #%d: %lld\n", ka, ans);
  }
  return 0;
}
