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
const int oo = 0x3f3f3f3f;

int n;
int cnt1, cnt2;


int main()
{
  #ifndef ONLINE_JUDGE
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    int tmp;
    cnt1 = cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &tmp);
      cnt1 += tmp&1;
      cnt2 += tmp>>1;

    }

    // cout << cnt1 << " " << cnt2 << endl;

    if (cnt1 == 0)
    {
      printf("%d\n",cnt2 * 2);
    }

    else
    {
      printf("%d\n", cnt2 / cnt1 * 2 + 1);
    }

  }
  return 0;
}
