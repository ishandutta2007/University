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

using namespace std;
typedef long long LL;

const int maxN = 1000020;
const int oo = 0x3f3f3f3f;

LL l, n, k;
bool check(int x)
{
  LL len = 0, need, range;

  while (len < l)
  {
    need = x / (k-1);
    if (x % (k-1) != 0) need ++;
    

  }



  return true;
}





int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif

  while (cin >> l >> n >> k)
  {
    int left, right, mid;
    int ans = 0;

    while (left <= right)
    {
      mid = (left + mid) / 2;

      if (check(mid))
      {
        ans = mid;
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
