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
const int oo = 998244353;


int b[maxn], c[maxn];
int n;
int rest;
ll ans;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
  #endif


  int T;
  scanf("%d", &T);

  while(T--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &c[i]);

    bool illegal = false;
    if (b[0] != c[0])
      illegal = true;
    for (int i = 1; i < n; i++)
      if (b[i] > b[i-1] || c[i] < c[i-1] || (b[i] < b[i-1] && c[i] > c[i-1]))
      {
        illegal = true;
        break;
      }
    if (illegal)
    {
      printf("0\n");
      continue;
    }
    ans = 1;
    int rest = 0;
    for (int i = 1; i < n; i++)
    {
      if (b[i] < b[i-1])
      {
        rest += b[i-1] - b[i] - 1;
      }
      else if (c[i] > c[i-1])
      {
        rest += c[i] - c[i-1] - 1;
      }
      else
      {
        ans = ans * rest % oo;
        rest --;
      }
    }

    printf("%I64d\n", ans);

  }
  return 0;
}
