#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

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

double Lenth(const Vec &v) {
	return sqrt(v*v);
}

Point outerCircle(double x1, double y1, double x2, double y2, double x3, double y3) {
  double A1 = 2.0*(x2-x1);
  double B1 = 2.0*(y2-y1);
  double C1 = x2*x2+y2*y2-x1*x1-y1*y1;
  double A2 = 2.0*(x3-x2);
  double B2 = 2.0*(y3-y2);
  double C2 = x3*x3+y3*y3-x2*x2-y2*y2;
  double x=((C1*B2)-(C2*B1))/((A1*B2)-(A2*B1));
  double y=((A1*C2)-(A2*C1))/((A1*B2)-(A2*B1));
  return Point(x,y);
}

const int maxn = 520;

Point p[maxn];

const double eps = 1e-8;

void minCircleCover(int n, Point &c, double &r) {
  random_shuffle(p, p+n); c = p[0]; r = 0;
  for (int i = 1; i < n; i++) if (Lenth(p[i]-c) > r + eps) {
      c = p[i]; r = 0;
      for (int j = 0; j < i; j++) if (Lenth(p[j]-c) > r + eps) {
          c.x = (p[i].x+p[j].x)/2.0;
          c.y = (p[i].y+p[j].y)/2.0;
          r = Lenth(p[j]-c);
          for (int k = 0; k < j; k++) if (Lenth(p[k]-c) > r + eps) {
              c = outerCircle(p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y);
              r = Lenth(p[i]-c);
          }
      }
  }
}


int main() {

  int n;
  Point c;
  double r;
  while (scanf("%d", &n)) {
    if (n==0) break;
    double x, y;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &p[i].x, &p[i].y); 
    }
    minCircleCover(n, c, r);
    printf("%.2f %.2f %.2f\n", c.x, c.y, r);
  }
  return 0;
}

