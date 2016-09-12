#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 1e6+10;
const int oo = 1e9+7;

typedef pair<int,int> pii;
typedef long long ll;

int main()
{
  int T;
  scanf("%d", &T);
  ll n;
  while (T--)
  {
    cin >> n;

    if (n == 0)
    {
      cout << 0 << endl;
      continue;
    }
    
    ll x = (n-1)/3 + 1;
    ll y = n*2;
    if (x%2 == 0) x++;
    if (y%2 == 1) y--;
    ll ans = 0;
    {
      ll tmp = n;
      if (tmp % 2 == 0)
        tmp --;
      ans += max(0ll, (tmp-x)/2 + 1);
    }
    {
      ll tmp = n+1;
      if (tmp % 2 != 0)
        tmp++;
      ans += max(0ll, (y-tmp)/2 + 1);
    }
    
    cout << ans << endl;
  }

  return 0;
}
