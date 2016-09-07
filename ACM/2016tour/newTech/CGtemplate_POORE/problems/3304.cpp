#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int maxn = 102;
const double eps = 1e-7;
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
    if (dcmp(l1.A*l2.C - l2.A*l1.C) == 0 &&
        dcmp(l1.B*l2.C - l2.B*l1.C) == 0)
      return make_pair(Point(), 2);
    return make_pair(Point(), 0);
  }
  else {
    double x = (l2.B*l1.C - l1.B*l2.C) / det;
    double y = (l1.A*l2.C - l2.A*l1.C) / det;
    return make_pair(Point(x,y), 1);
  }
}

int n;
Point p[maxn*2];
Line ll[maxn];
bool check(int i, Line L)
{

  //cout << tl.A << " " << tl.B << " " << tl.C << endl;
  //cout << L.A << " " << L.B << " " << L.C << endl;

  pair<Point, int> tmp = intersectPoint(ll[i], L);

  if (tmp.Y == 2) return true;
  if (tmp.Y == 0) return false;

  if (dcmp(tmp.X.x - min(p[i*2].x, p[i*2+1].x))>=0 && dcmp(max(p[i*2].x,p[i*2+1].x)-tmp.X.x) >= 0 &&
      dcmp(tmp.X.y - min(p[i*2].y, p[i*2+1].y))>=0 && dcmp(max(p[i*2].y,p[i*2+1].y)-tmp.X.y) >= 0)
    return true;
  return false;
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
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%lf%lf%lf%lf", &p[i*2].x, &p[i*2].y, &p[i*2+1].x, &p[i*2+1].y);
      ll[i] = getLineFromPoints(p[i*2], p[i*2+1]);
    }
    bool ok = false;

    //Line l = getLineFromPoints(p[4],p[5]);
    //cout << check(p[4], p[5], l) << endl;

    //return 0;

    for (int i = 0; i < n*2 && !ok; i++)
    {
      for (int j = i+1; j < n*2 && !ok; j++) 
      if (!(dcmp(p[i].x-p[j].x) ==0 && dcmp(p[i].y-p[j].y)==0))
      {
        Line l = getLineFromPoints(p[i], p[j]);
        bool tok = true;
        for (int k = 0; k < n && tok; k++)
        {
          if (check(k, l) == false)
            tok = false;
        }
        /*
        if (tok)
        {
          showPoint(p[i]);
          showPoint(p[j]);
        }
        */
        if (tok) ok = true;
      }
    }
    
    if (ok) printf("Yes!\n");
    else printf("No!\n");
  }
  return 0;
}
