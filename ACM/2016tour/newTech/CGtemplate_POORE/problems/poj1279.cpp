#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 3000;

const double eps = 1e-8;
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  else return x > 0 ? 1:-1;
}
struct Point {
  double x, y;
  Point(double _x, double _y):x(_x),y(_y){}
  Point():x(0.0),y(0.0){}
};
typedef Point Vec;
void showPoint(Point A) {
  printf("(%.6f, %.6f)\n", A.x, A.y);
}
const Vec operator + (Vec A, Vec B) {
  return Vec(A.x+B.x, A.y+B.y);
}
const Vec operator - (Vec A, Vec B) {
  return Vec(A.x-B.x, A.y-B.y);
}
const double operator * (Vec A, Vec B) {
  return A.x*B.x + A.y*B.y;
}

// A*B = |A|*|B|*sin(theta)
// theta为 A,B 向量的夹角
// 如果 A 在 B 的顺时针方向180度内，则theta取正值
// 向量叉乘
// 返回值为正时，表示 A 在 B 的右侧180度内
// 返回值的绝对值等于以A,B向量为邻边的平行四边型的面积
const double operator ^ (Vec A, Vec B) {
  return A.x*B.y - A.y*B.x;
}

Vec operator * (Vec A, double t) {
  return Vec(A.x*t, A.y*t);
}

struct Line {
  Point p, v;
  double ang;
  Line(){}
  Line(Point p, Point v):p(p),v(v) {
    ang = atan2(v.y, v.x);
  }
  bool operator < (const Line &L) const {
    return ang < L.ang;
  }
};

bool onLeft(Line L, Point p)
{
  return dcmp(L.v^(p-L.p)) >= 0;
}

Point lineIntersection(Line a, Line b)
{
  Point u = a.p-b.p;
  double t = (b.v^u)/(a.v^b.v);
  return a.p+a.v*t;
}

int halfPlaneIntersection(Line *L, int n, Point *poly)
{
  sort(L, L+n);
  int first, last;
  Point *p = new Point[n];
  Line *q = new Line[n];
  q[first=last=0] = L[0];
  for (int i = 1; i < n; i++) {
    while(first < last && !onLeft(L[i], p[last-1])) last--;
    while(first < last && !onLeft(L[i], p[first])) first++;
    q[++last] = L[i];
    if (fabs(q[last].v^q[last-1].v) < eps) {
      last--;
      if (onLeft(q[last],L[i].p)) q[last] = L[i];
    }
    if (first < last) p[last-1] = lineIntersection(q[last-1], q[last]);
  }
  while(first < last && !onLeft(q[first], p[last-1])) last--;
  // 删除无用平面
  if (last - first <= 1) return 0; // empty
  p[last] = lineIntersection(q[last], q[first]);
  int m = 0;
  for (int i = first; i <= last; i++) poly[m++] = p[i];
  return m;
}

Point p[maxn], poly[maxn];
Line L[maxn], LL[maxn];

double area(Point *poly, int n)
{
  double ret = 0;
  for (int i = 2; i < n; i++)
  {
    Point v1 = poly[i]-poly[0];
    Point v2 = poly[i-1]-poly[0];
    ret += v2^v1;
  }
  return fabs(ret/2.0);
}

int main()
{
  int T, n;
  scanf("%d", &T);
  while(scanf("%d", &n) != EOF)
  {
    if (n == 0) break;
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y);
    for (int i = 0; i < n; i++)
    {
      L[i] = Line(p[i], p[(i+1)%n]-p[i]);
      LL[i] = Line(p[(i+1)%n],p[i]-p[(i+1)%n]);
      //printf("(%.2f,%.2f) (%.2f,%.2f)\n", LL[i].p.x,LL[i].p.y,LL[i].v.x,LL[i].v.y);
    }
    int cnt = 0;
    double ans = 0.0;
    cnt = halfPlaneIntersection(L, n, poly);
    ans = max(ans, area(poly, cnt));
    cnt = halfPlaneIntersection(LL, n, poly);
    ans = max(ans, area(poly, cnt));
    printf("%.2f\n", ans);
  }
  return 0;
}
