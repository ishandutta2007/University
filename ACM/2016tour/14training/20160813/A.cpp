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
const int oo = 1e9+7;

int a[10], b[10];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
  #endif

  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    for (int i = 0; i < 4; i++)
      scanf("%d", &a[i]);
    swap(a[2], a[3]);
    for (int i = 0; i < 4; i++)
      scanf("%d", &b[i]);
    swap(b[2], b[3]);
    bool ok = false;
    for (int d = 0; d < 4; d++)
    {
      bool tmp = true;
      for (int i = 0; i < 4; i++)
      {
        if (a[i] != b[(i+d)%4])
          tmp = false;
      }
      if (tmp) ok = true;
    }

    printf("Case #%d: %s\n", ka, ok ? "POSSIBLE":"IMPOSSIBLE");

  }

  return 0;
}
