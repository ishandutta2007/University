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


int n;
Point p[maxn*2];
bool check(int i, int j)
{
  if (dcmp(p[i].x-p[j].x) == 0 && dcmp(p[i].y-p[j].y) == 0) return false;

  Vec ver = p[i] - p[j];
  Vec v1, v2;
  for (int k = 0; k < n; k++)
  {
    v1 = p[k*2]-p[i];
    v2 = p[k*2+1]-p[i];
    if (dcmp((ver^v2)*(ver^v1)) > 0) return false;
  }
  return true;
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
      scanf("%lf%lf%lf%lf", &p[i*2].x, &p[i*2].y, &p[i*2+1].x, &p[i*2+1].y);
    bool ok = false;

    for (int i = 0; i < n*2 && !ok; i++)
    {
      for (int j = i+1; j < n*2 && !ok; j++) 
      {
        if (check(i, j) == true) ok = true;
      }
    }
    if (ok) printf("Yes!\n");
    else printf("No!\n");
  }
  return 0;
}
