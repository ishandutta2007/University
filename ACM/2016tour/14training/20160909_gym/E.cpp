#include <bits/stdc++.h>

using namespace std;

const int maxn = 60;
const double eps = 1e-7;

int dcmp(double x)
{
  if (fabs(x)<eps) return 0;
  return x < 0? -1:1;
}

struct Point {
  double x, y;
  Point(double _x, double _y):x(_x),y(_y){}
  Point():x(0.0),y(0.0){}
}c[maxn];
typedef Point Vec;
typedef Point point;

void showPoint(Point A) {
  printf("(%.6f, %.6f)\n", A.x, A.y);
}
const Vec operator + (Vec A, Vec B) {
  return Vec(A.x+B.x, A.y+B.y);
}
Vec operator - (Vec A, Vec B) {
  return Vec(A.x-B.x, A.y-B.y);
}
const double operator * (Vec A, Vec B) {
  return A.x*B.x + A.y*B.y;
}
Vec operator / (Vec A, double d)
{
  return Vec(A.x/d, A.y/d);
}
Vec operator * (Vec A, double d)
{
  return Vec(A.x*d, A.y*d);
}
const double operator ^ (Vec A, Vec B) {
  return A.x*B.y - A.y*B.x;
}
double Lenth(Vec v) {
	return sqrt(v*v);
}
double w, h;
double r[maxn];
int n;

point f(point p, point v, double d)
{
  v = v/sqrt(v*v) * d;
  return point(p.x+v.x, p.y+v.y);
}

double calR(point pp, int id)
{
  point v = c[id]-pp;
  return max(0.0, sqrt(v*v)-r[id]);
}

bool check(point p, double R)
{
  if (dcmp(p.x+R-w)>0) return false;
  if (dcmp(p.x-R)<0) return false;
  if (dcmp(p.y+R-h)>0) return false;
  if (dcmp(p.y-R)<0) return false;
  for (int i = 0; i < n; i++)
  {
    point v = p - c[i];
    double dis = sqrt(v*v);
    if (dcmp(dis-r[i]-R) < 0) return false;
  }
  return true;
}

double cal(point l, point r, int p1, int p2)
{
  double ans = 0.0;
  point mid;
  for(int tt = 0; tt < 120; tt++)
  {
    mid = (l + r)/2.0;
    double R = min(calR(mid, p1), calR(mid, p2));
    if (check(mid, R))
    {
      ans = max(R, ans);
      l = mid;
    }
    else
      r = mid;
  }
  return ans;
}

double solve(int p1, int p2)
{
  point v = c[p2]-c[p1];
  point v1 = point(-v.y, v.x);
  point v2 = point(v.y, -v.x);
  point mid = (c[p1]+c[p2])/2.0;
  point l = f(mid, v1 ,9e8);
  point r = f(mid, v2, 9e8);
  double ans = max(cal(mid, l, p1, p2), cal(mid, r, p1, p2));
  return ans;
}

Point ppp[4];

bool check1(double mid)
{
  ppp[0] = point(mid, mid);
  ppp[1] = point(w-mid, mid);
  ppp[2] = point(w-mid, h-mid);
  ppp[3] = point(mid, h-mid);
  for (int i = 0; i < 4; i++)
  {
    point v = ppp[i]-c[0];
    double dis = sqrt(v*v);
    if (dcmp(dis-r[0]-mid) >= 0)
      return true;
  }
  return false;
}

double solve1()
{
  double ret = 0.0;
  double low = 0.0, high = min(w, h)/2.0, mid;
  for (int tt = 0; tt < 1000; tt++)
  {
    mid = (low+high)/2.0;
    if (check1(mid))
    {
      ret = max(ret, mid);
      low = mid;
    }
    else
      high = mid;
  }
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
  //freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%lf%lf", &w, &h);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%lf%lf%lf", &c[i].x, &c[i].y, &r[i]);
    if (n == 0)
    {
      printf("%.8f\n", min(w,h)/2.0);
      continue;
    }
    else if (n == 1)
    {
      double ans = solve1();
      printf("%.8f\n", ans);
      continue;
    }
    double ans = 0.0;
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        ans = max(ans, solve(i, j));
    printf("%.12lf\n", ans);
  }
  return 0;
}

