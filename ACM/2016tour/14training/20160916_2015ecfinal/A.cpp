#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

long long n;
int main()
{
  int T;
  cin >> T;
  for (int ka = 1; ka <= T; ka++)
  {
    cin >> n;
    
    ll l = 1 ,r = 2220000000LL, mid;
    ll ans = 0;
    while(l <= r)
    {
      mid = (l+r)/2;
      if (mid*mid+mid <= 2*n)
      {
        ans = max(ans, mid);
        l = mid+1;
      }
      else
        r = mid-1;
    }
    printf("Case #%d: %lld\n", ka, (ans*ans+ans)/2);
  }



  return 0;
}
