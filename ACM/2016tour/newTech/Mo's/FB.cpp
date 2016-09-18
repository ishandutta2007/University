#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5+20;

struct bit {
  ll s[maxn];
  ll num;
  void add(int x, int z) {
    if (z > 100000) return;
    for (int i=x;i<=num;i+=(i&-i)) s[i]+=z;
  }
  ll ask(int x) {
    int tmp=0;
    for (int i=x;i;i-=(i&-i)) tmp+=s[i];
    return tmp;
  }
  void clear(int n) {
    num=n;
    memset(s,0,sizeof(s));
  }
}bita, bitb;

struct Query{
  int l, r, k, lp, id;
  Query(){}
  Query(int l, int r, int k, int lp, int id):l(l),r(r),k(k),lp(lp),id(id){}
}q[maxn];

bool operator < (const Query &a, const Query &b)
{
  if (a.lp == b.lp) return a.r < b.r;
  else return a.lp < b.lp;
}

int a[maxn], b[maxn];
int n, Q;
ll ans[maxn];

void update(int &l, int &r, int L, int R)
{
  while(r < R)
  {
    r++;
    bita.add(a[r], 1);
    bitb.add(b[r], 1);
  }
  while(r > R)
  {
    bita.add(a[r], -1);
    bitb.add(b[r], -1);
    r--;
  }
  while(l < L)
  {
    bita.add(a[l], -1);
    bitb.add(b[l], -1);
    l++;
  }
  while(l > L)
  {
    l--;
    bita.add(a[l], 1);
    bitb.add(b[l], 1);
  }
}

int main()
{
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &b[i]);
  int rtn = sqrt(n);
  for (int i = 0; i < Q; i++)
  {
    int l, r, k, lp;
    scanf("%d%d%d", &l, &r, &k);
    lp = l/rtn;
    q[i] = Query(l, r, k, lp, i);
  }
  sort(q, q+Q);
  int nowl = 1, nowr = 1;
  bita.clear(100002);
  bitb.clear(100002);
  bita.add(a[1], 1);
  bitb.add(b[1], 1);
  for (int i = 0; i < Q; i++)
  {
    update(nowl, nowr, q[i].l, q[i].r);
    int bel = q[i].id, k = q[i].k;
    ans[bel] = 0;
    int rk = sqrt(q[i].k);
    for (int j = 1; j <= rk; j++)
    {
      ans[bel] += (ll)(bita.ask(j)-bita.ask(j-1))*(bitb.ask(k/j));
      ans[bel] += (ll)(bitb.ask(j)-bitb.ask(j-1))*(bita.ask(k/j));
    }
    ans[bel] -= (ll)bita.ask(rk)*bitb.ask(rk);
  }

  for (int i = 0; i < Q; i++)
    printf("%I64d\n", ans[i]);
  return 0;
}
