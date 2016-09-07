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

const int maxn = 100020;
const int oo = 0x3f3f3f3f;

ll n, L, R;
ll a[maxn];
ll ans;
vector<pll> seg;
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%I64d%I64d%I64d", &n, &L, &R);
    // cout << n << " " << L << " " << R << endl;
    for (int i = 0; i < n; i++)
    {
      scanf("%I64d", &a[i]);
    }
    sort(a, a + n);

    seg.clear();
    for (int i = 1; i < n; i++)
    {
      pll tmp = pll(a[i]-a[i-1] + 1, a[i]+a[i-1]-1);
      if (tmp.Y >= tmp.X)
        seg.push_back(tmp);
    }
    sort(seg.begin(), seg.end());
    ans = 0;
    ll low = L, high = R;


    for (int i = 0, len = seg.size(); i < len; i++)
    {
      pll& tmp = seg[i];

      // cout << tmp.X << " " << tmp.Y << endl;

      if (tmp.Y < low) continue;
      if (tmp.X > high) continue;

      if (tmp.Y >= low && tmp.Y <= high)
      {
        ans += min(tmp.Y - tmp.X + 1, tmp.Y - low + 1);
        low = tmp.Y + 1;
      }
      else if (tmp.X >= low && tmp.X <= high)
      {
        ans += min(tmp.Y - tmp.X + 1, high - tmp.X + 1);
        low = tmp.Y + 1;
      }
      else if (tmp.X <= low && tmp.Y >= high)
      {
        ans += high - low + 1;
        break;
      }
      if (low > high)
        break;
    }
    printf("%I64d\n", max(0LL, R - L + 1 - ans));
  }
  return 0;
}
