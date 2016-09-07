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

const int maxn = 200200;
const int oo = 0x3f3f3f3f;

int n;
int a[maxn];
char str[maxn];


int main()
{
  scanf("%d", &n);
  scanf("%s", str);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int ans = oo;
  for (int i = 1; i < n; i++)
  {
    if (str[i-1] == 'R' && str[i] == 'L')
      ans = min(ans, a[i] - a[i-1]);
  }

  if (ans == oo)
    printf("-1\n");
  else
    printf("%d\n", ans/2);

  return 0;
}
