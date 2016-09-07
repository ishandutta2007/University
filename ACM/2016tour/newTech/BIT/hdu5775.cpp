#include <bits/stdc++.h>
using namespace std;
const int maxn = 150020;
typedef long long ll;
struct Bit
{
  ll s[maxn];
  int num;
  void add(int x, int z)
  {
    for (int i=x;i<=num;i+=(i&-i)) s[i]+=z;
  }
  ll ask(int x)
  {
    ll tmp=0;
    for (int i=x;i;i-=(i&-i)) tmp+=s[i];
    return tmp;
  }
  void clear(int n)
  {
    num=n;
    memset(s,0,sizeof(s));
  }
}bit;

int n, a[maxn];
int mi[maxn], mx[maxn];

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    int n;
    scanf("%d", &n);
    bit.clear(n+1);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
      mi[a[i]] = min(i, a[i]);
    }
    for (int i = n; i > 0; i--)
    {
      mx[a[i]] = i + bit.ask(a[i]);
      bit.add(a[i], 1);
    }
    printf("Case #%d:", ka);
    for (int i = 1; i <= n; i++)
      printf(" %d", mx[i]-mi[i]);
    printf("\n");
  }
  return 0;
}

