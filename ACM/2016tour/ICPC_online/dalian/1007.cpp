#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
const int oo = 1e9+7;

int main()
{
  #ifndef ONLINE_JUDGE
  //freopen("data.in", "r", stdin);
  #endif

  ll n, m, ans;
  while(cin >> n >> m)
  {
    ans = n;
    ans += n*(n-5)/2;
    if (ans > m)
      puts("F");
    else
      puts("T");
  }
  return 0;
}
