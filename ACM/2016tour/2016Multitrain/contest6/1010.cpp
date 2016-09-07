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

int p, q;
ll ans;
ll mmi[40];

void dfs(ll rest, ll t, ll now)
{
  if (now >= ans) return;
  if (rest <= 0)
  {
    if (q + rest < 0) rest = -q;
    //printf("r = %d t = %d now = %d\n", rest, t, now);
    if (t-1 > abs(rest))
      ans = min(ans, now + t-1);
    else
      ans = min(ans, now + abs(rest));
    //printf("ans = %d\n", ans);
    return;
  }
/*  
  for (int i = 1; i < 32; i++)
    dfs(rest - mmi[i], t+1, now + i);
  return;
  */

  int pos = lower_bound(mmi, mmi+40, rest) - mmi;
  /*
  printf("r = %d t = %d now = %d\n", rest, t, now);
  printf("pos = %d\n", pos);
  system("pause");
  */
//  dfs(rest - mmi[pos+1], t+1, now + pos + 1);
  dfs(rest - mmi[pos], t+1, now + pos);
  if (pos > 1) dfs(rest - mmi[pos-1], t+1, now + pos-1);
//  if (pos > 2) dfs(rest - mmi[pos-2], t+1, now + pos - 2);
}

void test(int x)
{
  for (int i = 1000000000 - 100; i <= x; i++)
  {
    ans = oo;
    dfs(i, 0, 0);
    printf("%d %d\n", i, ans);
  }
}


int main()
{
  #ifndef ONLINE_JUDGE
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
  #endif
  for (int i = 0; i < 40; i++)
  {
    mmi[i] = (1LL << i) - 1;
  //  printf("%d %I64d\n", i, mmi[i]);
  }
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &p, &q);
    if (q >= p)
      printf("%d\n", q-p);
    else
    {
      ans = oo;
      dfs(p-q, 0, 0);
      printf("%I64d\n", ans);
    }
  }
  return 0;
}

