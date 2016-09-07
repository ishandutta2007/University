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

const int maxn = 100020;
const int oo = 1e9+7;

int a[maxn];
int n;
int mx[maxn], mxr[maxn];
ll solve()
{
  mx[0] = 0;
  for (int i = 1; i < n; i++)
  {
    mx[i] = max(mx[i-1], abs(a[i]-a[i-1]));
  }
  mxr[n-1] = 0;
  for (int i = n-2; i >= 0; i--)
  {
    mxr[i] = max(mxr[i+1], abs(a[i]-a[i+1]));
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == 0) ans += mxr[i+1];
    else if(i == n-1) ans += mx[i-1];
    else ans += max(abs(a[i+1]-a[i-1]), max(mx[i-1], mxr[i+1]));
  }
  return ans;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    printf("%I64d\n", solve());
  }
  return 0;
}
