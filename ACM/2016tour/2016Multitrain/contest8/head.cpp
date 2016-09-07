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

const int maxn = 1000020;
const int oo = 0x3f3f3f3f;

int n;
ll C;
int v0[maxn];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%I64d\n", &n, &C);
    int x, d;
    for (int i = 1; i <= n; i++)
      scanf("%d%d%d", &v0[i], &x, &d);
    
    sort(v0 + 1, v0 + n + 1);
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
      ll t, k;
      scanf("%I64d%I64d",&t, &k);
      double ans = v0[k]*1.0;
      ans = sqrt(C*2.0*t + ans*ans);
      printf("%.3f\n", ans);
    }
  }
  return 0;
}
