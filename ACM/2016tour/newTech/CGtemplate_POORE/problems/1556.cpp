#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>

#define X first
#define Y second

using namespace std;

const double eps = 1e-6;
const int maxn = 1000;
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
double pos[maxn];
int n;
typedef pair<Point, Point> seg;

vector<seg> d[maxn];
vector<Point> p;
int id[maxn];
double dis[maxn];

bool check(int a, int b)
{
  for (int i = id[a]+1; i < id[b]; i++)
  {
    if (!(lineCrossSeg(d[i][0].X, d[i][0].Y, p[a], p[b]) ||
          lineCrossSeg(d[i][1].X, d[i][1].Y, p[a], p[b])
         ))
    return false;
  }
  return true;
}

double caldis(int a, int b)
{
  return sqrt((p[b]-p[a])*(p[b]-p[a]));
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif

  while(scanf("%d", &n) != EOF)
  {
    if (n == -1) break;
    p.clear();
    for (int i = 0; i <= n; i++)
      d[i].clear();
    p.push_back(Point(0.0,5.0));
    id[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      scanf("%lf", &pos[i]);
      for (int j = 0; j < 2; j++)
      {
        double tlow, thigh;
        scanf("%lf%lf", &tlow, &thigh);
        p.push_back(Point(pos[i], tlow));
        p.push_back(Point(pos[i], thigh));
        id[p.size()-1] = i;
        id[p.size()-2] = i;
        d[i].push_back(seg(p[p.size()-2], p[p.size()-1]));
      }
    }
    p.push_back(Point(10.0, 5.0));
    id[p.size()-1] = n+1;
    for (int i = 0; i < maxn; i++)
      dis[i] = 1e9;

    dis[0] = 0.0;

    //printf("size = %d\n", p.size());

    for (int i = 1, len = p.size(); i < len; i++)
    {
      //showPoint(p[i]);
      for (int j = 0; j < i; j++)
        if (check(j, i))
          dis[i] = min(dis[i], dis[j] + caldis(j, i));
    }
    printf("%.2f\n", dis[p.size()-1]);
  }
  return 0;
}
