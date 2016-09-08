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
 
/*
bool OnLeft(Line L,Point P){
    return (L.v^(P - L.p))>=0;          //如果线上的点不算就改成>
}
 
Point GetlineIntersection(Line a, Line b)
{
  Point u = a.p-b.p;
  double t = (b.v^u)/(a.v^b.v);
  return a.p+(a.v*t);
}
 
int HalfplaneIntersection(Line* L,int n,Point* poly){ //L数组是从0开始
    sort(L,L+n);
 
    int first,last;
    Point *p = new Point[n];
    Line *q = new Line[n];
    q[first = last = 0] = L[0];
    for(int i=1;i<n;i++){
        while(first<last && !OnLeft(L[i],p[last-1]))last--;
        while(first<last && !OnLeft(L[i],p[first]))first++;
        q[++last] = L[i];
        if(fabs((q[last].v^q[last-1].v))<eps){
            last--;
            if(OnLeft(q[last],L[i].p))q[last] = L[i];
        }
        if(first<last) p[last-1] = GetlineIntersection(q[last-1],q[last]);
    }
    while(first<last && !OnLeft(q[first],p[last-1]))last -- ;
    if(last-first<=1)return 0;
    p[last] = GetlineIntersection(q[last],q[first]);
    int m = 0;
    for(int i=first;i<=last;i++)poly[m++] = p[i];
    return m;
}
*/
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
  //删除无用平面
  if (last - first <= 1) return 0; // empty
  p[last] = lineIntersection(q[last], q[first]);
  int m = 0;
  for (int i = first; i <= last; i++) poly[m++] = p[i];
  return m;
}
Point p[maxn], poly[maxn];
Line L[maxn], LL[maxn];
typedef Point point;

bool cmpxy(point a, point b)
{
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int s[maxn];

// 包含边上的点就将 <= 改为 <
int convexHull(Point *p, int n)
{
  sort(p, p + n, cmpxy);
  int top = 0;
  for (int i = 0; i < n; i++)
  {
    while(top>1 && ((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]])) <= 0) top--;
    s[top++] = i;
  }
  int k = top;
  for (int i=n-2;i>=0;i--)
  {
    while(top>k && ((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]])) <= 0) top--;
    s[top++] = i;
  }
  if (n > 1) top--;
  return top;
}

int main()  
{  
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
    n = convexHull(poly, n);
    double area = 0.0;
    int x = s[0];
    for (int j = 2; j < n; j++)
    {
      int a = s[j];
      int b = s[j-1];
      Point v1 = poly[a]-poly[x], v2 = poly[b]-poly[x];
      area += v2^v1;
    }
    printf ("%.9lf\n", area/2.0);  
  }  
  return 0;  
}
