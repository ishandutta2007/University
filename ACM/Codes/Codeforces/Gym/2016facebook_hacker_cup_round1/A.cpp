/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
const int oo = 1e9+7;
const int maxn = 1e5+20;

int a[maxn];
int dp[maxn];
int n;

bool check(int l, int r)
{
  int nd = 0;
  for (int i = l; i < r; i++)
  {
    if (a[i] >= a[i+1]) return false;
    if (a[i] + 10 >= a[i+1]) continue;
    int now = a[i]+10;
    nd++;
    while(now + 10 < a[i+1])
    {
      now+=10;
      nd++;
    }
  }
  nd += r-l+1;
  return nd <= 4;
}

int solve()
{
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    dp[i] = dp[i-1]+1;
    for (int d = 1; d <= 3; d++)
    {
      int pre = max(i-d, 1);
      if (check(pre,i))
        dp[i] = min(dp[i], dp[pre-1]+1);
    }
  }
  /*
  for (int i = 1; i <= n; i++)
    printf("%d ", dp[i]);
  */
  return dp[n]*4-n;
}

int main()
{
  freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    int ans = solve();
    printf("Case #%d: %d\n", ka, ans);
  }
  return 0;
}

