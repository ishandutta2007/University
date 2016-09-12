#include <bits/stdc++.h>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
typedef long long ll;
const int maxn = 200020;
const ll oo = 1000000000000000ll;
ll a[maxn], b[maxn];
int now;

struct segtree
{
  ll segmin[maxn<<2];
  ll lazy[maxn<<2];
  void pushup(int rt)
  {
    segmin[rt] = min(segmin[rt<<1],segmin[rt<<1|1]);
  }
  void build(int l, int r, int rt, int f)
  {
    if(l == r)
    {
      if (l%2 == f)
        segmin[rt] = b[now];
      else
        segmin[rt] = oo;
      now++;
      return;
    }
    int m = (l+r)>>1;
    build(lson, f);
    build(rson, f);
    pushup(rt);
  }
  void pushdown(int rt, int m)
  {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    segmin[rt<<1] += lazy[rt];
    segmin[rt<<1|1] += lazy[rt];
    lazy[rt] = 0;
  }
  void update(int L, int R, int c, int l, int r, int rt)
  {
    if(L <= l && r <= R)
    {
      lazy[rt] += c;
      segmin[rt] += c;
      return;
    }
    if(lazy[rt] != 0)
      pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
    pushup(rt);
  }
  ll query(int L, int R, int l, int r, int rt)
  {
    if(L <= l && R >= r) 
    {
      return segmin[rt];
    }
    if(lazy[rt] != 0)
      pushdown(rt, r - l + 1);
    int m = (l+r)>>1;
    ll tmp = oo;
    if (L <= m) tmp = min(query(L, R, lson), tmp);
    if (R > m) tmp = min(query(L, R, rson), tmp);
    return tmp;
  }
}st0, st1;

int n, q;

int solve2(int l, int r)
{
  int fr = l-1, bk=r;
  ll pre, ed, mx0, mx1;
  if (fr%2 == 0)
    pre = st0.query(fr,fr,1,n,1);
  else
    pre = st1.query(fr,fr,1,n,1);
  if (bk%2 == 0)
    ed = st0.query(bk,bk,1,n,1);
  else
    ed = st1.query(bk,bk,1,n,1);
  if (l%2==1)
  {
    mx0 = st1.query(l,r,1,n,1);
    mx1 = st0.query(l,r,1,n,1);
  }
  else
  {
    mx0 = st0.query(l,r,1,n,1);
    mx1 = st1.query(l,r,1,n,1);
  }
  if (mx0+pre<0 || mx1-pre<0) return 0;
  if ((bk-fr)%2==0 && ed-pre != 0) return 0;
  if ((bk-fr)%2==1 && ed+pre != 0) return 0;
  return 1;
}

void solve1(int l, int r, int k)
{
  if ((r-l+1)%2==0)
  {
    if (l%2==0)
      st0.update(l,r,k,1,n,1);
    else
      st1.update(l,r,k,1,n,1);
  }
  else
  {
    if (l%2==0)
      st0.update(l,r,k,1,n,1);
    else
      st1.update(l,r,k,1,n,1);
    int bk = r+1;
    if (bk > n) return;
    if (bk%2==0)
    {
      st0.update(bk,n,-k,1,n,1);
      st1.update(bk,n,k,1,n,1);
    }
    else
    {
      st0.update(bk,n,k,1,n,1);
      st1.update(bk,n,-k,1,n,1);
    }
  }
}

int main()
{
  scanf("%d", &n);
  b[1] = 0;
  for (int i = 1; i <= n; i++)
  {
    scanf("%I64d", &a[i]);
    b[i+1] = a[i]-b[i]-1;
  }
  n++;
  now = 1;
  st0.build(1, n, 1, 0);
  now = 1;
  st1.build(1, n, 1, 1);
  scanf("%d", &q);
  int l, r, k;
  while(q--)
  {
    int cmd;
    scanf("%d", &cmd);
    if (cmd == 1)
    {
      scanf("%d%d%d", &l,&r,&k);
      l+=2,r+=2;
      solve1(l, r, k);
    }
    else
    {
      scanf("%d%d", &l, &r);
      l+=2,r+=2;
      ll tmp = solve2(l, r);
      printf("%I64d\n", tmp);
    }
  }
  return 0;
}

