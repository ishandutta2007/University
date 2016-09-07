#include <bits/stdc++.h>
using namespace std;

const int maxn = 50020;
const double eps = 1e-10;
const double oo = 1e20;

int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  else return x > 0 ? 1:-1;
}
struct Point {
  double x, y;
  Point(double _x, double _y):x(_x),y(_y){}
  Point():x(0.0),y(0.0){}
}p[maxn];
typedef Point Vec;
typedef Point point;

Vec operator + (Vec A, Vec B) {
  return Vec(A.x+B.x, A.y+B.y);
}
const Vec operator - (Vec A, Vec B) {
  return Vec(A.x-B.x, A.y-B.y);
}
const double operator * (Vec A, Vec B) {
  return A.x*B.x + A.y*B.y;
}

point operator / (Vec A, double d) {
  return Vec(A.x/d, A.y/d);
}

bool operator < (Vec A, Vec B) {
  if (dcmp(A.x-B.x) < 0 || (dcmp(A.x-B.x)==0 && dcmp(A.y-B.y) < 0)) return true;
  else return false;
}

const double operator ^ (Vec A, Vec B) {
  return A.x*B.y - A.y*B.x;
}

double linePointDist(Point A, Point B, Point C, bool isSeg) {
  double dist = ((B-A)^(C-A)) / sqrt((B-A)*(B-A));
  if (isSeg) {
    double dot1 = (C-B)*(B-A);
    if (dot1 > 0) return sqrt((B-C)*(B-C));
    double dot2 = (C-A)*(A-B);
    if (dot2 > 0) return sqrt((A-C)*(A-C));
  }
  return abs(dist);
}
void circle_cross_line(Point a,Point b,Point o,double r,Point ret[],int &num) {  
  double x0 = o.x ,y0 = o.y;  
  double x1 = a.x, y1 = a.y;  
  double x2 = b.x, y2 = b.y;  
  double dx = x2-x1, dy = y2-y1;  
  double A = dx*dx+dy*dy;  
  double B = 2*dx*(x1-x0) + 2*dy*(y1-y0);  
  double C = (x1-x0)*(x1-x0) + (y1-y0)*(y1-y0)-(r)*(r);  
  double delta = B*B-4*A*C;  
  num = 0;  
  if( dcmp(delta) >= 0) {  
    double t1 = (-B - sqrt(delta)) / (2*A);  
    double t2 = (-B + sqrt(delta)) / (2*A);  
    ret[num++] = Point(x1+t1*dx,y1+t1*dy);  
    ret[num++] = Point(x1+t2*dx,y1+t2*dy);  
  }  
}

point pp, po;
double Ts, Vr, Vs;
double mincost;
int n, id1, id2;
double dist[maxn];

double caltime(point &p1, point &p2, point &p3)
{
  return sqrt((p2-p1)*(p2-p1))/Vr + sqrt((p2-p3)*(p2-p3))/Vs;
}

bool cmp1(point &a, point &b)
{
  double tmp = (a-po)^(b-po);
  double dis1 = (a-po)*(a-po);
  double dis2 = (b-po)*(b-po);
  if (dcmp(tmp) > 0 ||
      (dcmp(tmp) == 0 && dcmp(dis2 - dis1)>0)) return true;
  return false;
}
bool cmp2(point &a, point &b)
{
  double tmp = (a-po)^(b-po);
  double dis1 = (a-po)*(a-po);
  double dis2 = (b-po)*(b-po);
  if (
    dcmp(tmp) < 0
    || (dcmp(tmp) == 0 
        && dcmp(dis1-dis2)>0
       )
     ) return true;
  return false;
}

void pre(int s, int t, int d)
{
  dist[s] = min(dist[s]/Vr, sqrt((p[s]-po)*(p[s]-po))/Vr);
  int ps = s;
  s = (s+d+n)%n;
  while(s != t)
  {
    dist[s] = min(dist[s], dist[ps] + sqrt((p[s]-p[ps])*(p[s]-p[ps]))/Vr);
    ps = s;
    s = (s+d+n)%n;
  }
}

double thi(point l, point r, point s)
{
  point mid1, mid2;
  while(dcmp((r-l)*(r-l)) > 0)
  {
    mid1 = (r-l)/3 + l;
    mid2 = (mid1+r)/2;
    if (caltime(s, mid1, pp) < caltime(s, mid2, pp)) r = mid2;
    else l = mid1;
  }
  point tmp = (mid1+mid2)/2;
  return caltime(s, tmp, pp);
}

double solve()
{
  for (int i = 0; i < n; i++)
    dist[i] = oo;
  pre(id2, id1, 1);
  pre(id1, id2, -1);
  double ans = oo;
  point ret[2];
  int num;
  double R = (Ts-mincost)*Vs;
  for (int i = id1; i != id2; i = (i+1)%n)
  {
    point tp1 = p[i], tp2 = p[(i+1)%n];
    circle_cross_line(tp1, tp2, pp, R, ret, num);
    if (num == 0) continue;
    else if (num == 1 && dcmp((tp2-tp1)^(ret[0]-tp1))==0 && dcmp((tp2-tp1)*(ret[0]-tp1)) >= 0)
    {
      ans = min(ans, caltime(po, ret[0], pp));
    }
    else
    {
      if (ret[1] < ret[0]) swap(ret[0], ret[1]);
      if (tp2 < tp1) swap(tp1, tp2);
      if (tp1 < ret[0]) tp1 = ret[0];
      if (ret[1] < tp2) tp2 = ret[1];
      if (tp2 < tp1) continue;
      ans = min(ans, thi(tp1, tp2, po));
    }
  }
  for (int i = id2; i != id1; i = (i+1)%n)
  {
    point tp1 = p[i], tp2 = p[(i+1)%n];
    circle_cross_line(tp1, tp2, pp, R, ret, num);
    if (num == 0) continue;
    else if (num == 1 && dcmp((tp2-tp1)^(ret[0]-tp1))==0 && dcmp((tp2-tp1)*(ret[0]-tp1)) >= 0)
    {
      ans = min(ans, dist[i] + caltime(p[i], ret[0], pp));
      ans = min(ans, dist[(i+1)%n] + caltime(p[(i+1)%n], ret[0], pp));
    }
    else
    {
      if (ret[1] < ret[0]) swap(ret[0], ret[1]);
      if (tp2 < tp1) swap(tp1, tp2);
      if (tp1 < ret[0]) tp1 = ret[0];
      if (ret[1] < tp2) tp2 = ret[1];
      if (tp2 < tp1) continue;
      ans = min(ans, dist[i] + thi(tp1, tp2, p[i]));
      ans = min(ans, dist[(i+1)%n] + thi(tp1, tp2, p[(i+1)%n]));
    }
  }
  if (ans > oo/2)
    ans = -1.0;
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
    scanf("%lf%lf%lf", &Ts, &Vr, &Vs);
    scanf("%lf%lf", &po.x, &po.y);
    scanf("%lf%lf", &pp.x, &pp.y);
    scanf("%d", &n);
    id1 = id2 = 0;
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y);
    if (dcmp((p[2]-p[0])^(p[1]-p[0])) < 0)
      reverse(p, p + n);
    for (int i = 0; i < n; i++)
    {
      if (cmp1(p[i], p[id1])) id1 = i;
      if (cmp2(p[i], p[id2])) id2 = i;
    }
    double mindist = oo;
    for (int i = 0; i < n; i++)
      mindist = min(mindist, linePointDist(p[i], p[(i+1)%n], pp, 1));
    mincost = mindist*2/Vs;
    if (dcmp(Ts - mincost) < 0)
    {
      printf("-1\n");
      continue;
    }
    double ans = solve();
    if (ans < 0)
      printf("-1\n");
    else
      printf("%.2f\n", ans + mincost);
  }
  return 0;
}

