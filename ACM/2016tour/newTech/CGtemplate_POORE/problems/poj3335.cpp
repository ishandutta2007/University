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


/*
struct Line {
  // Ax + By = C
  double A, B, C,ang;
  Line(double _A, double _B, double _C, double ang):A(_A),B(_B),C(_C),ang(ang){}
  Line():A(0.0),B(0.0),C(0.0),ang(0.0){}
  bool operator < (const Line &L) const {
    return ang < L.ang;
  }
};

Line getLineFromPoints(Point p1, Point p2) {
  double A = p2.y-p1.y;
  double B = p1.x-p2.x;
  double C = A*p1.x + B*p1.y;
  double ang = atan2(p2.y-p1.y, p2.x-p1.x);
  return Line(A,B,C,ang);
}

// int = 0 无交点
// int = 1 一个交点
// int = 2 两直线重合
pair<Point, int> intersectPoint(Line l1, Line l2) {
  double det = l1.A*l2.B - l2.A*l1.B;
  if (dcmp(det) == 0) {
    // 两直线平行 重合
	if (dcmp(l1.A*l2.C - l2.A*l1.C) == 0 &&
        dcmp(l1.B*l2.C - l2.B*l1.C) == 0)
	return make_pair(Point(), 2);
    else
	  return make_pair(Point(), 0);
  }
  else {
    double x = (l2.B*l1.C - l1.B*l2.C) / det;
    double y = (l1.A*l2.C - l2.A*l1.C) / det;
    return make_pair(Point(x,y), 1);
  }
}
*/

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

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif
  int T, n;
  scanf("%d", &T);
  while(scanf("%d", &n) != EOF)
  {
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y);
    for (int i = 0; i < n; i++)
    {
      L[i] = Line(p[i], p[(i+1)%n]-p[i]);
      LL[i] = Line(p[(i+1)%n],p[i]-p[(i+1)%n]);
      //printf("(%.2f,%.2f) (%.2f,%.2f)\n", LL[i].p.x,LL[i].p.y,LL[i].v.x,LL[i].v.y);
    }
    int cnt = 0;
    cnt += halfPlaneIntersection(L, n, poly);
    cnt += halfPlaneIntersection(LL, n, poly);
    if (cnt) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
