int n, s[maxn];
int top;
bool cmp(point a, point b) {
  int tmp = (a-p[0])^(b-p[0]);
  int dis1 = (a-p[0])*(a-p[0]);
  int dis2 = (b-p[0])*(b-p[0]);
  if (tmp > 0 || (tmp == 0 && dis1 > dis2)) return true;
  return false;
}

int graham() {
  for (int i = 0; i < n; i++) {
    if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
      swap(p[i], p[0]);
  }
  sort(p+1, p+n, cmp);
  s[0] = 0;
  s[1] = 1;
  top = 1;
  for (int i = 2; i < n; i++) {
    // 注意是否包含边上的点
    // while(top && ((p[i-1]-p[0])^(p[i]-p[0])) <= 0) top--;
    while(top && ((p[s[top]]-p[s[top-1]])^(p[i]-p[s[top-1]])) < 0) top--;
    s[++top] = i;
  }
  top++;
  return top;
}

bool cmpxy(point a, point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
// 包含边上的点就将 <= 改为 <
int convexHull(Point *p, int n) {
  sort(p, p + n, cmpxy);
  int top = 0;
  for (int i = 0; i < n; i++) {
    while(top>1 && ((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]])) <= 0) top--;
    s[top++] = i;
  }
  int k = top;
  for (int i=n-2;i>=0;i--) {
    while(top>k && ((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]])) <= 0) top--;
    s[top++] = i;
  }
  if (n > 1) top--;
  return top;
}
