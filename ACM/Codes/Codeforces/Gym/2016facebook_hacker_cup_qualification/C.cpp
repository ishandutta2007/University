#include <bits/stdc++.h>
#define L first
#define R second

using namespace std;
const int maxn = 1e5+20;
const int oo = 1e9+7;
typedef long long ll;

typedef pair<int,int> pii;

int b[maxn];

int main()
{
  int T;
  scanf("%d", &T);
  int n, p;
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
      scanf("%d", &b[i]);
    ll ans = 0;
    ll sum = 0;
    int fr = 0;
    for (int i = 1; i <= n; i++)
    {
      sum += b[i];
      while(sum > p) sum -= b[++fr];
      ans += i-fr;
    }
    printf("Case #%d: %I64d\n", ka, ans);
  }

  return 0;
}
