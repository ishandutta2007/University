#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
const int maxn = 10020;
const int oo = 1e9+7;
typedef pair<int,int> pii;

int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  int T;
  scanf("%d", &T);
  int l, r;
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d%d", &l, &r);
    ll ans = min(l, r);
    
    ans = ans*(ans+1)/2;


    printf("Case #%d: %I64d\n", ka, ans);
  }




  return 0;
}
