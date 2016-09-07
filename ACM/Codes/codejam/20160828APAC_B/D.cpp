#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
const ll maxn = 500020;
ll oo;
ll n;

int main()
{
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);

  int T;
  cin >> T;
  for (int ka = 1; ka <= T; ka++)
  {
    cin >> n >> oo;
  
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
      ans = (ans+(n-i)*(n-i)*(i+1)) % oo;
    }
    printf("Case #%d: %I64d\n", ka, ans);
  }
  return 0;
}

