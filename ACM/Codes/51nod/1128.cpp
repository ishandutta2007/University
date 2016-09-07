#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100020;
const ll oo = 100000000000000LL;

int a[maxn], n, k;

bool check(ll l)
{
  ll tmp = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > l) return false;
    if (tmp + a[i] > l)
    {
      cnt++;
      tmp = a[i];
    }
    else
      tmp += a[i];
  }
  
  if (tmp) cnt++;
  //cout << cnt << endl;
  if (cnt <= k) return true;
  else  return false;
}



ll solve()
{
  ll low = 1, high = oo, mid;
  ll ans = oo;
  while(low <= high)
  {
    mid = (low + high) / 2;

//    cout << low << " " << high << endl;

    if (check(mid))
    {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
}



int main()
{
  
  freopen("data.in", "r", stdin);

  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }


  //cout << check(6) << endl;
  //return 0;

  printf("%I64d\n", solve()); 

  return 0;
}
