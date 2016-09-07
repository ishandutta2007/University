#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue> 
using namespace std;
const double eps = 1e-8;
const int maxn = 100;


int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  else return x > 0 ? 1:-1;
}

struct Point {
  int x, y;
  int id;
  Point(int _x, int _y):x(_x),y(_y){}
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
const int operator * (Vec A, Vec B) {
  return A.x*B.x + A.y*B.y;
}
// A*B = |A|*|B|*sin(theta)
// theta为 A,B 向量的夹角
// 如果 A 在 B 的顺时针方向180度内，则theta取正值
// 向量叉乘
// 返回值为正时，表示 A 在 B 的右侧180度内
// 返回值的绝对值等于以A,B向量为邻边的平行四边型的面积
const int operator ^ (Vec A, Vec B) {
  return A.x*B.y - A.y*B.x;
}

Point p[maxn];
int n, o;
vector<int> ans;

bool cmp(point a, point b)
{
  int tmp = (a-p[o])^(b-p[o]);
  int dis1 = (a-p[o])*(a-p[o]);
  int dis2 = (b-p[o])*(b-p[o]);
  if (tmp > 0 || (tmp == 0 && dis1 > dis2)) return true;
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
    int ti, tx, ty;
    ans.clear();
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &ti,&tx,&ty);
      p[i].x = tx;
      p[i].y = ty;
      p[i].id = ti;
      if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
        swap(p[i], p[0]);
    }
    for (int i = 0; i < n; i++)
    {
      o = i;
      sort(p+1+i, p+n, cmp);
      ans.push_back(p[i].id);
      if (!(i-1 < 0 || (((p[i]-p[i-1])^(p[i+1]-p[i])) > 0)))
        break;
    }

    printf("%d", (int)ans.size());
    for (int i = 0,len=ans.size(); i < len; i++)
      printf(" %d", ans[i]);
    printf("\n");
  }
  return 0;
}
