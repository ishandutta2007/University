#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll mod = 1000000007;
ll expc, chpc;
ll n, m, k, d;
ll fact[300];

ll inv(ll x, ll mm)
{
  if (x == 1) return x;
  return inv(mm % x, mm)*(mm - mm / x) % mm;
}


ll cal(int a, int b)
{
  if (a < b) return 0ll;
  return ((fact[a] * inv(fact[b], mod))%mod * inv(fact[a-b], mod)) % mod;
}


int main()
{
  int T;
  scanf("%d", &T);
  fact[0] = 1;
  for (int i = 1; i <= 210; i++)
    fact[i] = fact[i-1]*i % mod;

  while(T--)
  {
    cin >> n >> m >> k >> d;
    expc = chpc = 0;
    for (int i = 0; i < n; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      if (tmp >= d) expc++;
      else chpc++;
    }

    ll ans = 0;
    for (int i = k; i <= expc; i++)
    {
      if ( m-i >= 0 && chpc >= m-i)
        (ans += cal(expc, i) * cal(chpc, m-i)) %= mod;
    }

    cout << ans <<endl;

  }
  return 0;
}
