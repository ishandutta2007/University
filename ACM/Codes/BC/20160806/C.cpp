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

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 200020;
const int oo = 1e9+7;

int n, m, k;
int a[maxn], sum[maxn];

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    ll ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1] + (a[i] >= m);
    }

    for (int i = 1; i <= n; i++)
    {
      int nd = k+sum[i-1];
      int pos = lower_bound(sum+1, sum + n + 1, nd) - sum;
      ans += n - pos + 1;
    }
    
    cout << ans << endl;

  }
  return 0;
}
