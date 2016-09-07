#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int n, m;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int ans = 0;
    cin >> n >> m;
    ll have = 1, rest = n;

    while(have < m && rest > 0)
    {
      ans++;
      int delta= min(have, min((ll)m, rest));
      have += delta;
      rest -= delta;
    }
    ans += rest / m;
    if (rest % m) ans++;
    cout << ans << endl;
  }

  return 0;
}
