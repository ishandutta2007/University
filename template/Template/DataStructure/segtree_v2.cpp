#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
typedef long long ll;
const int maxn = 1e5+20;
using namespace std;
ll segsum[maxn<<2], lazy[maxn<<2];
void pushup(int rt) {
  segsum[rt] = segsum[rt<<1] + segsum[rt<<1|1];
}
void build(int l, int r, int rt) {
  if(l == r) {
    scanf("%lld",&segsum[rt]);
    return;
  }
  int m = (l+r)>>1;
  build(lson); build(rson);
  pushup(rt);
}
void pushdown(int rt, int m) {
  lazy[rt<<1] += lazy[rt];
  lazy[rt<<1|1] += lazy[rt];
  segsum[rt<<1] += lazy[rt]*(m-(m>>1));
  segsum[rt<<1|1] += lazy[rt]*(m>>1);
  lazy[rt] = 0;
}
void update(int L, int R, int c, int l, int r, int rt) {
  if(L <= l && r <= R) {
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
ll querysum(int L, int R, int l, int r, int rt) {
  if(L <= l && R >= r) 
    return segsum[rt];
  if(lazy[rt] != 0)
    pushdown(rt, r - l + 1);
  int m = (l+r)>>1;
  ll tmp = 0;
  if(L <= m) tmp += querysum(L, R, lson);
  if(R > m) tmp += querysum(L, R, rson);
  return tmp;
}

