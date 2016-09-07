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

int fact[100];
int mx = 10;

void dfs(int pre, int now, int t, int tmp, int n, int m)
{
  if (t > m)
  {
    ans += tmp;
    return;
  }
  
  for (int i = now; i <= n; i++)
  {
    tmp = tmp * C(i, now) % oo;
  }
  

}


int cal(int n, int m)
{
  ans = 0;
  for (int i = 0; i <= n; i++)
    dfs(-1, i, m-1, 0, n, m);
  return ans;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
  #endif
  fact[0] = 1;
  for (int i = 1; i <= mx; i++)
    fact[i] = fact[i-1] * i;

  for (int n = 0; n <= mx; n++)
    for (int m = 0; m <= mx; m++)
    {
      printf("(%d,%d) : %d\n", n, m, cal(n, n));
    }



  return 0;
}
