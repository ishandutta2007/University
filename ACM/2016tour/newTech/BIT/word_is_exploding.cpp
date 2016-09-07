#include <bits/stdc++.h>

using namespace std;

const int maxn = 50020;
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
}bit, bit1;
struct Bitr
{
  ll s[maxn];
  int num;
  void add(int x, int z)
  {
    for (int i=x;i;i-=(i&-i)) s[i]+=z;
  }
  ll ask(int x)
  {
    ll tmp=0;
    for (int i=x;i<=num;i+=(i&-i)) tmp+=s[i];
    return tmp;
  }
  void clear(int n)
  {
    num=n;
    memset(s,0,sizeof(s));
  }
}bitr, bitr1;

int a[maxn], h[maxn];
int n;
ll ans12, ans21, ansd;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif

  while(scanf("%d", &n) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      h[i] = a[i];
    }
    sort(h, h + n);

    ans12 = ans21 = ansd = 0;
    for (int i = 0; i < n; i++)
      a[i] = lower_bound(h, h + n, a[i]) - h + 1;
    bit.clear(n+2);
    bitr.clear(n+2);
    for (int i = 0; i < n; i++)
    {
      ll tmplow = bit.ask(a[i]-1);
      ll tmphigh = bitr.ask(a[i]+1);
      
      //printf("%d -- %d\n", tmplow, tmphigh);

      ans12 += tmplow;
      ans21 += tmphigh;
      ansd += tmplow*tmphigh;
      bit.add(a[i], 1);
      bitr.add(a[i], 1);
    }
    //printf("[%d]\n", ansd);
    bit.clear(n+2);
    bitr.clear(n+2);
    for (int i = n-1; i >= 0; i--)
    {
      ll tmplow = bit.ask(a[i]-1);
      ll tmphigh = bitr.ask(a[i]+1);
      ansd += tmplow*tmphigh;
      bit.add(a[i], 1);
      bitr.add(a[i], 1);
    }

    bit.clear(n+2);
    bit1.clear(n+2);
    bitr.clear(n+2);
    bitr1.clear(n+2);
    for (int i = 0; i < n; i++)
    {
      bit1.add(a[i], 1);
      bitr1.add(a[i], 1);
    }
    for (int i = 0; i < n; i++)
    {
      bit1.add(a[i], -1);
      bitr1.add(a[i], -1);
      ll tmp1 = bit.ask(a[i]-1);
      ll tmp2 = bit1.ask(a[i]-1);
      ansd += tmp1*tmp2;
      bit.add(a[i], 1);
      tmp1 = bitr.ask(a[i]+1);
      tmp2 = bitr1.ask(a[i]+1);
      ansd += tmp1*tmp2;
      bitr.add(a[i], 1);
    }

    //cout << ans12 << " " << ans21 << " " << ansd << endl;
    printf("%I64d\n", ans12*ans21-ansd);
  }
  return 0;
}

