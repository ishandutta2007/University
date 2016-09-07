#include <bits/stdc++.h>
using namespace std;
const int maxn = 200020;
const int oo = (int)1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

int a[maxn];
int n, h, k;
ll ans, rest;

int main()
{
  
  scanf("%d%d%d", &n, &h, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int pos = 0;
  ans = 0;
  while(pos < n || rest > 0)
  {
    while(rest + a[pos] <= h && pos < n)
    {
      rest += a[pos];
      pos++;
    }
    if (rest <= k)
    {
      ans ++;
      rest = 0;
    }
    else
    {
      ans += rest / k;
      rest %= k;
    }
  }
  cout << ans << endl;
  return 0;
}
