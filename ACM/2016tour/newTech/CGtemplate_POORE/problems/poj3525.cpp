#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int maxn = 1020;
const double eps = 1e-8;

int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  else return x > 0 ? 1:-1;
}
struct Point {
  double x,y;
  Point(){}
  Point(double x, double y):x(x),y(y){}
}p[maxn], poly[maxn];

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
Vec operator / (Vec A, double d) {
  return Vec(A.x/d, A.y/d);
}
Vec operator * (Vec A, double d) {
  return Vec(A.x*d, A.y*d);
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

struct Line {
  Point p, v;
  double ang;
  Line(){}
  Line(Point p, Vec v):p(p),v(v) {
    ang = atan2(v.y, v.x);
  }
  bool operator < (const Line &L) const {
    return ang < L.ang;
  }
};
// 包含边上的点将 > 改为 >= 
bool onLeft(Line L, Point p)
{
  return (L.v^(p-L.p)) > 0;
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
int n;
Line L[maxn];
Line LL[maxn];
Line f(Line &l, double mid)
{
  Point dr = Point(-l.v.y, l.v.x);
  dr = (dr / sqrt(dr*dr))*mid;
  return Line(l.p+dr, l.v);
}

bool check(double mid)
{
  for (int i = 0; i < n; i++)
    LL[i] = f(L[i], mid);
  int tmp = halfPlaneIntersection(LL, n, poly);
  return tmp > 0;
  //cout << mid << " : " << tmp << endl;
  /*
  for (int i = 0; i < tmp; i++)
  {
    printf("(%.3f, %.3f)\n", poly[i].x, poly[i].y);
  }
  //return tmp > 0;
  double area2 = 0.0;
  for (int i = 2; i < tmp; i++)
  {
    area2 += (poly[i]-poly[0])^(poly[i-1]-poly[0]);
  }
  return dcmp(area2) != 0;
  */
}

double solve()
{
  int mx = 100;
  double ret = 0.0;
  double low = 0.0, high = 1e8, mid;
  for (int i = 0; i < mx; i++)
  {
    mid = (low + high)/2.0;
    if (check(mid))
    {
      ret = max(ret, mid);
      low = mid;
    }
    else
      high = mid;
  }
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  if (!n) break;
  for (int i = 0; i < n; i++)
    scanf("%lf%lf", &p[i].x, &p[i].y);
  for (int i = 0; i < n; i++)
    L[i] = Line(p[i], p[(i+1)%n]-p[i]);
  printf("%.7f\n", solve());
  return 0;
}

