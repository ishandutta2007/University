#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

const double eps = 1e-6;
const int maxn = 100020;


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

// 判断线段的两个端点是否在直线的两侧
bool lineCrossSeg(Point p1, Point p2, Point ls, Point le)
{
  Vec ver = ls-le, v1 = p1-ls, v2 = p2-ls;
  return dcmp((ver^v1)*(ver^v2)) <= 0;
}

typedef pair<Point, Point> sg;
bool segCrossSeg(sg a, sg b, bool includeEnd)
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

deque<int> top;
sg seg[maxn];
int n;

void insert(int x)
{
  int cnt = 0;
  for (int i = 0, len = top.size(); i < len; i++)
  {
    if (segCrossSeg(seg[x], seg[top[i]], 0))
    {
      swap(top[cnt++], top[i]);
    }
  }
  for (int i = 0; i < cnt; i++)
    top.pop_front();
  top.push_back(x);
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif

  while(scanf("%d", &n) != EOF)
  {
    if (n == 0) break;
    top.clear();
    for (int i = 1; i <= n; i++)
    {
      scanf("%lf%lf%lf%lf", &seg[i].X.x, &seg[i].X.y, &seg[i].Y.x, &seg[i].Y.y);
      insert(i);
    }
    sort(top.begin(), top.end());
    printf("Top sticks:");
    for (int i = 0, len = top.size(); i < len; i++)
      printf(" %d%c", top[i], i==len-1? '.':',');
    printf("\n");
  }
  return 0;
}

