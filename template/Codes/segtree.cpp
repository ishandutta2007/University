#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define maxn 100200
#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
struct SegTree{
  ll segsum[maxn<<2];
  ll lazy[maxn<<2];
  void clear()
  {
    memset(segsum, 0, sizeof(segsum));
    memset(lazy, 0, sizeof(lazy));
  }
  void pushup(int rt)
  {
    segsum[rt] = segsum[rt<<1] + segsum[rt<<1|1];
  }
  void build(int l, int r, int rt)
  {
    if(l == r)
    {
      scanf("%lld",&segsum[rt]);
      return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
  }
  void pushdown(int rt, int m)
  {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    segsum[rt << 1] += lazy[rt] * (m - (m >> 1));
    segsum[rt << 1 | 1] += lazy[rt] * (m >> 1);
    lazy[rt] = 0;
  }
  void update(int L, int R, int c, int l, int r, int rt)
  {
    if(L <= l && r <= R)
    {
      lazy[rt] += c;
      segsum[rt] += (r - l + 1) * c;
      return;
    }
    if(lazy[rt] != 0)
      pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
    pushup(rt);
  }
  void check(int l, int r, int rt)
  {

    printf("l=%d r=%d rt=%d sum=%lld\n", l,r,rt,segsum[rt]);
    if(l == r)
    {
      return;
    }
    int m = (l+r)>>1;
    check(lson);
    check(rson);
  }
  ll querysum(int L, int R, int l, int r, int rt){
    if(L <= l && R >= r) 
    {
      return segsum[rt];
    }
    if(lazy[rt] != 0)
      pushdown(rt, r - l + 1);
    int m = (l+r)>>1;
    ll tmp = 0;
    if(L <= m) tmp += querysum(L, R, lson);
    if(R > m) tmp += querysum(L, R, rson);
    return tmp;
  }
}segtree;

int main()
{
  int n, q;
  scanf("%d%d",&n,&q);
  segtree.clear();
  segtree.build(1, n, 1);
  char cmd[2];
  int x, y ,z;
  while(q--){
    scanf("%s", cmd);
    if(cmd[0] == 'Q')
    {
      scanf("%d%d",&x,&y);
      printf("%lld\n", segtree.querysum(x, y, 1, n, 1));
    }else{
      scanf("%d%d%d",&x,&y,&z);
      segtree.update(x, y, z, 1, n, 1);
    }
  }
  return 0;
}
