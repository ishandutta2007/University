#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

#define X first
#define Y second
using namespace std;

const double eps = 1e-10;
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

// 判断两条线段是否相交
// 两次跨立试验
typedef pair<Point, Point> seg;
bool segCrossSeg(seg a, seg b, bool includeEnd)
{
  Vec ver = b.X-b.Y, v1 = a.X-b.X, v2 = a.Y-b.X;
  int tmp1 = dcmp((ver^v1)*(ver^v2));
  ver = a.X-a.Y, v1 = b.X-a.X, v2 = b.Y-a.X;
  int tmp2 = dcmp((ver^v1)*(ver^v2));
  if (includeEnd)
    return tmp1 <= 0 && tmp2 <= 0;
  else
    return tmp1 < 0 && tmp2 < 0;
}
struct Line {
  // Ax + By = C
  double A, B, C;
  Line(double _A, double _B, double _C):A(_A),B(_B),C(_C){}
  Line():A(0.0),B(0.0),C(0.0){}
}l1, l2;

Line getLineFromPoints(Point p1, Point p2) {
  double A = p2.y-p1.y;
  double B = p1.x-p2.x;
  double C = A*p1.x + B*p1.y;
  return Line(A,B,C);
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
seg a, b;

void in(Point &p)
{
  scanf("%lf%lf", &p.x, &p.y);
}

double solve()
{
  if (dcmp(a.X.y-a.Y.y) == 0) return 0.0;
  if (dcmp(b.X.y-b.Y.y) == 0) return 0.0;
  if (!segCrossSeg(a, b, 1)) return 0.0;
  l1 = getLineFromPoints(a.X, a.Y);
  l2 = getLineFromPoints(b.X, b.Y);
  pair<Point, int> tmp = intersectPoint(l1, l2);
  if (tmp.Y != 1) return 0.0;
  if (a.X.y > a.Y.y) swap(a.X, a.Y);
  if (b.X.y > b.Y.y) swap(b.X, b.Y);
  Vec v1 = a.Y-tmp.X;
  Vec v2 = b.Y-tmp.X;
  double minh = min(v1.y, v2.y);
  Vec ver = Vec(0, minh);
  if (dcmp(v1^v2) > 0) swap(v1, v2);
  if (dcmp(ver^v2) > 0 && dcmp(v2.x-v1.x) <= 0) return 0.0;
  if (dcmp(v1^ver) > 0 && dcmp(v1.x-v2.x) >= 0) return 0.0;

  v1.x = v1.x*(minh/v1.y);
  v2.x = v2.x*(minh/v2.y);
  v1.y = minh;
  v2.y = minh;

  double ans = (ver^v1)/2 + (v2^ver)/2;
  return ans;
}



int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while(T--)
  { 
    in(a.X);in(a.Y);
    in(b.X);in(b.Y);
    double ans = solve();
    printf("%.2f\n", ans);

  }
  return 0;
}

