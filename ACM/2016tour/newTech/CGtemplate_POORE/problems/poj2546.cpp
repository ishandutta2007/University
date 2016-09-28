/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
const int oo = 1e9+7;
const int maxn = 1e4+20;

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

const double pi = acos(-1.0);
const double eps = 1e-8;

double areaCircle2(double x1, double y1, double r1, double x2, double y2, double r2) {
  double d = dist(x1, y1, x2, y2);
  if (r1+r2 < d-eps) return 0.0;
  if (fabs(r1-r2) > d-eps) {
    double tmp = min(r1, r2);
    return pi*tmp*tmp;
  }
  double ang1 = acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
  double ang2 = acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
  double ret = ang1*r1*r1+ang2*r2*r2-d*r1*sin(ang1);
  return ret;
}


int main()
{
  double x1, y1, x2, y2, r1, r2;
  while(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2) {
    printf("%.3f\n", areaCircle2(x1,y1,r1,x2,y2,r2));
  }
  return 0;
}

