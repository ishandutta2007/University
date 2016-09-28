/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define H second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

const int oo = 1e9+7;
const int maxn = 3e5+20;

ll ha[maxn];
pii p[maxn];
ll l2[maxn], lsum[maxn];
ll cnt[maxn];
int n;
deque<pii> q;

ll solve() {
  ll ret = 0;
  q.clear();
  memset(l2, 0, sizeof(l2));
  memset(lsum, 0, sizeof(lsum));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    ll th = p[i].H, tx = p[i].X;
    ret += cnt[th]*tx%oo*tx%oo;
    ret %= oo;
    ret += l2[th];
    ret %= oo;
    ret -= 2LL*tx%oo*lsum[th]%oo;
    ret %= oo;
    while(!q.empty() && q.back().H < th) {
      pii tmp = q.back();
      q.pop_back();
      l2[tmp.H] -= tmp.X*tmp.X%oo;
      l2[tmp.H] %= oo;
      lsum[tmp.H] -= tmp.X;
      lsum[tmp.H] %= oo;
      cnt[tmp.H] --;
    }
    q.push_back(p[i]);
    l2[th] += tx*tx%oo;
    l2[th] %= oo;
    lsum[th] += tx;
    lsum[th] %= oo;
    cnt[th] ++;
  }
  return (ret%oo+oo)%oo;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data2.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%I64d%I64d", &p[i].X, &p[i].H);
      ha[i] = p[i].H;
    }
    sort(ha+1, ha+n+1);
    for (int i = 1; i <= n; i++) {
      p[i].H = lower_bound(ha+1,ha+n+1,p[i].H) - ha;
    }
    sort(p+1, p+n+1);
    ll ans = solve();
    printf("Case #%d: %I64d\n", ka, ans);
  }
  return 0;
}

