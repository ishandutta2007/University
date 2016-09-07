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
Point p[maxn], poly[maxn];
Line L[maxn], LL[maxn];
int main()  
{  
  freopen("data.in", "r", stdin);
  int i;  
  double x1, y1, x2, y2;
  double x3, y3, x4, y4; 
  while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) != EOF)
  { 
    scanf("%lf%lf%lf%lf", &x3, &y3, &x4, &y4);
    int n = 0;
    if ((x2 > x1 && y2 > y1) || (x2 < x1 && y2 < y1))
    {
      L[n++] = Line(Point(x1, y2), Point(x1-x1, y1-y2));
      L[n++] = Line(Point(x2, y1), Point(x1-x2, y2-y1));
      L[n++] = Line(Point(x1, y1), Point(x2-x1, y1-y1));
    }
    else
    {
      L[n++] = Line(Point(x1, y1), Point(x1-x1, y2-y1));
      L[n++] = Line(Point(x1, y2), Point(x2-x1, y1-y2));
      L[n++] = Line(Point(x2, y1), Point(x1-x2, y1-y1));
    }
    L[n++] = Line(Point(x3, y3), Point(x4-x3, y3-y3));
    L[n++] = Line(Point(x4, y3), Point(x4-x4, y4-y3));
    L[n++] = Line(Point(x4, y4), Point(x3-x4, y4-y4));
    L[n++] = Line(Point(x3, y4), Point(x3-x3, y3-y4));
    n = halfPlaneIntersection(L, 7, poly);
    double area = 0.0;
    for (int i = 2; i < n; i++)
    {
      Point v1 = poly[i]-poly[0], v2 = poly[i-1]-poly[0];
      area += v2^v1;
    }
    printf ("%.9lf\n", area/2.0);  
  }  
  return 0;  
}

