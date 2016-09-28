bool cmp(Point a, Point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
bool cmpy(int a, int b) {
  return p[a].y < p[b].y;
}

double closePair(int l, int r) {
  if (l == r) return inf;
  if (l+1 == r) return Lenth((p[l]-p[r]));
  int mid =(l+r)/2;
  double tdis = min(closePair(l, mid), closePair(mid+1, r));
  int cnt = 0;
  for (int i = l; i <= r; i++) if (fabs(p[i].x-p[i+1].x) < tdis)
    t[cnt++] = i;
  sort(t, t + cnt, cmpy);
  for (int i = 0; i < cnt; i++) {
    for (int j = i+1; j < cnt && dcmp(p[t[j]].y-p[t[i]].y-tdis) < 0; j++) {
      double tmp = Lenth((p[t[i]]-p[t[j]]));
      tdis = min(tdis, tmp);
    }
  }
  return tdis;
}

