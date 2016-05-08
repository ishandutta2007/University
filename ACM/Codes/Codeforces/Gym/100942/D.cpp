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


LL solve(LL l, LL n, LL k)
{
  if (n <= 0) return 0;
  LL rest , per, R;
  
  rest = n % k;
  per = n / k + (n%k==0? 0 : 1);
  while (rest / (n / k + ))



  // rest = R * (per*2 - 1);
  cout << l << " " << n << " " << k << endl;
  cout << "per " << per << ", rest " << rest << ", R" << R << endl;
  if (R >= l) return n - l*(per*2 - 1);
  else return solve(l - R, n - rest, k);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif



  LL l, n, k;
  while(cin >> l >> n >> k)
  cout << solve(l, n, k) << endl;

  return 0;
}
