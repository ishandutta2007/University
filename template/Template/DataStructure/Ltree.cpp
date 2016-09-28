/*
 * 左倾树
 * 多个优先队列，合并logn
 *
 */

int lc[maxn], rc[maxn];
int v[maxn], size[maxn], d[maxn];
int tot;
int merge(int x, int y) {
  if (x==0||y==0) return x+y;
  if (v[x] < v[y]) swap(x, y);
  rc[x] = merge(rc[x], y);
  size[x] = size[lc[x]]+size[rc[x]]+1;
  if (d[rc[x]]>d[lc[x]]) swap(lc[x],rc[x]);
  d[x] = d[rc[x]]+1;
  return x;
}
int top(int x) {
  return v[x];
}
int sz(int x) {
  return size[x];
}
void pop(int &x) {
  x = merge(lc[x], rc[x]);
}
int newHeap(int x) {
  tot++;
  v[tot] = x;
  size[tot] = 1;
  lc[tot]=rc[tot]=d[tot]=0;
  return tot;
}
ll a[maxn];
int rt[maxn];
int L[maxn], R[maxn];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i]-=i;
  }
  tot = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt++;
    rt[cnt] = newHeap(a[i]);
    L[cnt] = R[cnt] = i;
    while(cnt>1 && top(rt[cnt]) < top(rt[cnt-1])) {
      rt[cnt-1] = merge(rt[cnt], rt[cnt-1]);
      R[cnt-1] = R[cnt];
      while(sz(rt[cnt-1]) > (R[cnt-1]-L[cnt-1]+2)/2)
        pop(rt[cnt-1]);
      cnt--;
    }
  }
  ll ans = 0;
  for (int i = 1; i <= cnt; i++) {
    for (int j = L[i]; j <= R[i]; j++)
      ans += abs(top(rt[i]) - a[j]);
  }
  printf("%I64d\n", ans);
  return 0;
}

