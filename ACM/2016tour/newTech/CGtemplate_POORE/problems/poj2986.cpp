/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int oo = 1e9+7;
const int maxn = 1e4+20;
const double eps = 1e-8;
const double pi = acos(-1.0);


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
const double operator ^ (Vec A, Vec B) {
  return A.x*B.y - A.y*B.x;
}

bool operator == (Vec A, Vec B) {
  return dcmp(A.x-B.x) ==0 && dcmp(A.y-B.y) == 0;
}

double Lenth(const Vec &v) {
	return sqrt(v*v);
}

bool cmpxy(Point a, Point b) {
  if (dcmp(a.x-b.x) == 0) return dcmp(a.y-b.y) < 0;
  return dcmp(a.x-b.x) < 0;
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
    if (ret[0] == ret[1]) num--;
  }  
}
Point p[3];
bool pointOnSeg(point s1, point s2, point p, bool includeEnd)
{
  if ((s1 == p || s2 == p) && !includeEnd) return false;
  s2 = s2-s1;
  p = p-s1;
  return dcmp(s2^p)== 0 && dcmp(s2*p)>=0;

  double minx = min(s1.x, s2.x);
  double maxx = max(s1.x, s2.x);
  double miny = min(s1.y, s2.y);
  double maxy = max(s1.y, s2.y);

  if ((s1 == p || s2 == p) && !includeEnd) return false;
  if (p.x-minx>=0 
      && maxx-p.x>=0 
      && p.y-miny>=0 
      && maxy-p.y>=0
      && ((s2-s1)^(p-s1)) == 0)
    return true;
  else
    return false;
}


double areaTriangleCircle(Point o, double r, Point a, Point b) {
  double area = 0;
  double dis1 = Lenth(a-o), dis2 = Lenth(b-o);
  if (dcmp(dis1-dis2) > 0) {
    swap(a,b);
    swap(dis1,dis2);
  }
  //cout << dis1 << " " << dis2 << endl;
  int cmp1 = dcmp(dis1-r), cmp2 = dcmp(dis2-r);
  // both inner
  if (cmp2 <= 0) {
    //cout << "tp1" << endl;
    return fabs((a-o)^(b-o))/2.0;
  }
  // one inner
  if (cmp1 < 0 && cmp2 > 0) {
    //cout << "tp2" << endl;
    Point ret[2], c;
    int num = 0;
    circle_cross_line(a, b, o, r, ret, num);

    if (num == 1 || ret[0] == a || !pointOnSeg(a, b, ret[0], true)) c = ret[1];
    else c = ret[0];

    /*
    if (pointOnSeg(a, b, ret[0], true)) c = ret[0];
    else c = ret[1];
    */

    //showPoint(c);
    /*
    showPoint(o);
    showPoint(a);
    showPoint(b);
    */
    area += fabs((a-o)^(c-o))*0.5;
    //cout << area << endl;
    /*
    double cb = Lenth(b-c), co = Lenth(c-o), bo = Lenth(b-o);
    if (fabs(co*bo) > eps) {
      //cout << co << " " << bo << " " << cb << endl;
      //cout << (co*co+bo*bo-cb*cb)/(2.0*co*bo) << endl;
      //cout << acos(1.0) << endl;
      double tmp = (co*co+bo*bo-cb*cb)/(2.0*co*bo);
      if (dcmp(1-tmp) > 0) {
        double theta = acos(tmp);
        area += theta*r*r*0.5;
      }
    }
    */
    //cout << area<< endl;
    /*
    cout <<"-----------" << endl;
    showPoint(b);
    showPoint(c);
    */
    area += areaTriangleCircle(o, r, c, b);
    return area;
  }
  if (cmp1 >= 0) {
    //cout << "tp3" << endl;
    Point ret[2], inter[2], c;
    int num = 0, cnt = 0;
    circle_cross_line(a, b, o, r, ret, num);
    /*
    printf("!!!num = %d\n", num);
    printf("~~~~~~~~~~~~~~~~~\n");
    showPoint(a);
    showPoint(b);
    showPoint(ret[0]);
    showPoint(ret[1]);
    printf("~~~~~~~~~~~~~~~~~\n");
    */
    for (int i = 0; i < num; i++) if (pointOnSeg(a, b, ret[i], true))
      inter[cnt++] = ret[i];
    //cout << cnt << endl;
    if (cnt <= 1) {
      double ao = Lenth(a-o), bo = Lenth(b-o), ab = Lenth(a-b);
      double tmp = (ao*ao+bo*bo-ab*ab)/(2.0*ao*bo);
      double theta;
      if (dcmp(1.0-fabs(tmp)) > 0)
        theta = acos(tmp);
      else theta = 0.0;
      //printf("theta = %.2f\n", theta);
      return theta*r*r*0.5;
    }
    else {
      if (!cmpxy(a, b)) swap(a, b);
      if (!cmpxy(ret[0], ret[1])) swap(ret[0], ret[1]);
      /*
      showPoint(a);
      showPoint(ret[0]);
      showPoint(ret[1]);
      showPoint(b);
      */
      area += fabs((ret[0]-o)^(ret[1]-o))/2.0;
      area += areaTriangleCircle(o, r, a, ret[0]);
      area += areaTriangleCircle(o, r, b, ret[1]);
      return area;
    }
  }
  return area;
}
double areaPolyCircle(Point *p, int n, Point o, double r) {
  double ret = 0.0;
  for (int i = 0; i < n; i++) {
    int j = (i+1)%n;
    /*
    showPoint(o);
    showPoint(p[i]);
    showPoint(p[j]);
    */
    //double tmparea = areaTriangleCircle(p[i]-o, p[j]-o, r);
    double tmparea = areaTriangleCircle(o, r, p[i], p[j]);
    /*
    printf("%.2lf\n", tmparea);
    showPoint(p[i]-o);
    showPoint(p[j]-o);
    */
    if (dcmp((p[i]-o)^(p[j]-o)) < 0) 
      tmparea = -tmparea;
    /*
      ret += tmparea;
    else
      ret -= tmparea;
      */
    //printf("tmparea = %.4f\n", tmparea);
    ret += tmparea;
  }
  return fabs(ret);
}
int main() {
  /*
  freopen("data.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  */
  double r;
  Point o;
  int ka = 1;
  while(scanf("%lf%lf", &p[0].x, &p[0].y) != EOF) {
    for (int i = 1; i < 3; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y);
    scanf("%lf%lf", &o.x, &o.y);
    scanf("%lf", &r);

    double ans = areaPolyCircle(p, 3, o, r);
    printf("%.2f\n", ans);
  }
  return 0;
}

