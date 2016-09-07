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
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 1020;
const int oo = 0x3f3f3f3f;

int fa[maxn];
int n, m;

int root(int x)
{
  if (fa[x] == x)
    return x;
  return root(fa[x]);
}

int main()
{
  bool ok = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  int a, b;
  for (int i = 1; i <= m; i++)
  {
    scanf("%d%d", &a, &b);
    if (root(a) == root(b))
    {
      ok = 0;
      break;
    }
    else
    {
      int ra = root(a);
      int rb = root(b);
      fa[ra] = rb;
    }
  }
  int RT = root(1);
  for (int i = 1; i <= n; i++)
    if (root(i) != RT)
    {
      ok = 0;
    }
  if (ok) printf("yes\n");
  else printf("no\n");
  return 0;
}
