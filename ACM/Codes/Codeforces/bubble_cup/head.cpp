#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5+20;

ll a[maxn];


int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%I64d", &a[i]);
  sort(a, a + n);
  ll ans = 0;
  int l = 0, r = n-1;
  while(l <= r)
  {
    if (l != r)
      ans = (ans + 2*a[l]*a[r])%10007;
    else
      ans = (ans + a[l]*a[r])%10007;
    l++;
    r--;
  }
  printf("%I64d\n", ans);
  return 0;
}
