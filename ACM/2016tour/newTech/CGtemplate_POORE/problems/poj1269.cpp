#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define X first
#define Y second

using namespace std;

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
typedef Point point;

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
struct Line {
  // Ax + By = C
  double A, B, C;
  Line(double _A, double _B, double _C):A(_A),B(_B),C(_C){}
  Line():A(0.0),B(0.0),C(0.0){}
};

Line getLineFromPoints(Point p1, Point p2) {
  double A = p2.y-p1.y;
  double B = p1.x-p2.x;
  double C = A*p1.x + B*p1.y;
  return Line(A,B,C);
}

pair<Point, int> intersectPoint(Line l1, Line l2) {
  double det = l1.A*l2.B - l2.A*l1.B;
  if (dcmp(det) == 0) {
    // 两直线平行
    if (dcmp(l1.A*l2.C-l1.C*l2.A) == 0 && dcmp(l1.B*l2.C-l1.C*l2.B) == 0) return make_pair(Point(), 1);
    return make_pair(Point(), 0);
  }
  else {
    double x = (l2.B*l1.C - l1.B*l2.C) / det;
    double y = (l1.A*l2.C - l2.A*l1.C) / det;
    return make_pair(Point(x,y), 2);
  }
}

point p[4];

void init(point &p)
{
  scanf("%lf%lf", &p.x, &p.y);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  printf("INTERSECTING LINES OUTPUT\n");
  while(T--)
  {
    for (int i = 0; i < 4; i++)
      init(p[i]);
    Line l1 = getLineFromPoints(p[0], p[1]);
    Line l2 = getLineFromPoints(p[2], p[3]);
    pair<point, int> tmp = intersectPoint(l1, l2);
    if (tmp.Y == 0)
      printf("NONE\n");
    else if (tmp.Y == 1)
      printf("LINE\n");
    else
      printf("POINT %.2f %.2f\n", tmp.X.x, tmp.X.y);
  }
  printf("END OF OUTPUT\n");
  return 0;
}
