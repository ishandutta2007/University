#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int oo = 1e9+7;
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
bool pointOnSeg(point s1, point s2, point p, bool includeEnd) {
  if ((s1 == p || s2 == p) && !includeEnd) return false;
  s2 = s2-s1;
  p = p-s1;
  return dcmp(s2^p)== 0 && dcmp(s2*p)>=0;
}

void circle_cross_seg(Point a,Point b,Point o,double r,Point ret[],int &num) {  
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
    if (dcmp(t1-1.0) <= 0 && dcmp(t1) >= 0) {
      ret[num++] = Point(x1+t1*dx,y1+t1*dy);  
    }
    if (dcmp(t2-1.0) <= 0 && dcmp(t2) >= 0) {
      ret[num++] = Point(x1+t2*dx,y1+t2*dy);  
    }
    if (num == 2 && dcmp(t1-t2) > 0) swap(ret[0], ret[1]);
  }
}

Point p[3], o;
double r;

double Angle(point a, Point b) {
  if (dcmp(a*a)==0 || dcmp(b*b) == 0 || dcmp((a-b)*(a-b))==0 ) return 0.0;
  return acos(max(-1.0, min(1.0, a*b/Lenth(a)/Lenth(b))));
}


double areaTriangleCircle(point a, point b, double r) {
  double ans = 0.0;
  point O = point(0.0,0.0);
  if (a == O || b == O) return 0.0;
  bool ina = dcmp(Lenth(a)-r) <= 0;
  bool inb = dcmp(Lenth(b)-r) <= 0;
  double opr;
  if (dcmp(a^b) >= 0) opr=1.0;
  else opr = -1.0;
  if (ina&&inb) {
    //cout << "tp1" << endl;
    ans += opr*fabs(a^b)*0.5;
  }
  else if (!ina && !inb) {
    //cout << "tp2" << endl;
    int num = 0;
    point ret[2];
    circle_cross_seg(a, b, O, r, ret, num);
    if (num == 2) {
      ans += opr*fabs(ret[0]^ret[1])*0.5;
      ans += opr*r*r*0.5*(Angle(a, ret[0])+Angle(ret[1], b));
    }
    else {
      ans += opr*r*r*0.5*Angle(a, b);
    }
  }
  else {
    //cout << "tp3" << endl;
    int num = 0;
    point ret[2];
    circle_cross_seg(a, b, O, r, ret, num);
    if (num == 2) {
      ans += opr*fabs(ret[0]^ret[1])*0.5;
      ans += opr*r*r*0.5*(Angle(a, ret[0])+Angle(ret[1], b));
    }
    else if (ina) {
      ans += opr*fabs(ret[0]^a)*0.5;
      ans += opr*r*r*0.5*Angle(ret[0], b);
    }
    else {
      ans += opr*fabs(ret[0]^b)*0.5;
      ans += opr*r*r*0.5*Angle(ret[0], a);
    }
  }
  return ans;
}



int main() {
  //freopen("in.txt", "r", stdin);
  //freopen("data.in", "r", stdin);
  //freopen("out.txt", "w", stdout);
  int ka = 1;
  while(scanf("%lf%lf", &p[0].x, &p[0].y) != EOF) {
    for (int i = 1; i < 3; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y);
    scanf("%lf%lf", &o.x, &o.y);
    scanf("%lf", &r);
    double ans = 0.0;
    for (int i = 0; i < 3; i++) {
      double tmp = areaTriangleCircle(p[i]-o, p[(i+1)%3]-o, r);
      //printf("tmp = %.4f\n", tmp);
      ans += tmp;
    }
    ans = fabs(ans);
    printf("%.2f\n", ans);
  }
  return 0;
}

