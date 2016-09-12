#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e4+20;

const double eps = 1e-6;

int dcmp(double x)
{
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1:1;
}

struct point {
  double x,y;
  point(double x, double y):x(x),y(y){}
  point(){}
}p[maxn], p1[maxn];

typedef point Point;

double operator * (point a, point b) {
  return a.x*b.x + a.y*b.y;
}

double operator ^ (point a, point b) {
  return a.x*b.y - a.y*b.x;
}

point operator + (point a, point b) {
  return point (a.x+b.x, a.y+b.y);
}

point operator - (point a, point b) {
  return point (a.x-b.x, a.y-b.y);
}

bool cmpxy(point a, point b) {
  if (dcmp(a.x -b.x)==0) return dcmp(a.y-b.y)<0;
  return dcmp(a.x-b.x)<0;
}
void show(Point p) {
  printf("(%.2f, %.2f)\n", p.x, p.y);
}

double linePointDist(Point A, Point B, Point C, bool isSeg) {
  /*
  cout << "--------" << endl;
  show(A);
  show(B);
  show(C);
  */
  double dist = ((B-A)^(C-A)) / sqrt((B-A)*(B-A));
  if (isSeg) {
    double dot1 = (C-B)*(B-A);
    if (dot1 > 0) return sqrt((B-C)*(B-C));
    double dot2 = (C-A)*(A-B);
    if (dot2 > 0) return sqrt((A-C)*(A-C));
  }
  return fabs(dist);
}

// s 为保存有序的凸包点的下标的栈
double rotatingCaliper(Point *p, Point *p1, int n, int m, int *s, int *s1) {
  int q = 1;
  double ans = 1e18;
  s[n] = s1[m] = 0;
  for (int i = 0; i < n; i++)
  {
    while( dcmp(((p[s[i+1]]-p[s[i]])^(p1[s1[q]]-p1[s1[q+1]]))) < 0)
    {
      //cout <<q << endl;
      q = (q+1)%m;
    }
/*
    while( ((p[s[i+1]]-p[s[i]])^(p1[s1[q+1]]-p[s[i]])) <
           ((p[s[i+1]]-p[s[i]])^(p1[s1[q]]  -p[s[i]])) )
      q = (q+1)%m;

    while( ((p[s[i+1]]-p[s[i]])^(p1[s1[(q-1+m)%m]]-p[s[i]])) <
           ((p[s[i+1]]-p[s[i]])^(p1[s1[q]]  -p[s[i]])) )
      q = (q-1+m)%m;
*/
    //cout << linePointDist(p[s[i]], p[s[i+1]], p1[s1[q]], true) << endl;
    //cout << linePointDist(p[s[i]], p[s[i+1]], p1[s1[q+1]], true) << endl;
    ans = min(ans, linePointDist(p[s[i]], p[s[i+1]], p1[s1[q]], true));
    ans = min(ans, linePointDist(p[s[i]], p[s[i+1]], p1[s1[q+1]], true));
    //ans = min(ans, linePointDist(p[s[i]], p[s[i+1]], p1[s1[(q-1+m)%m]], true));
    //ans = min(ans, linePointDist(p[s[i]], p[s[(i-1+n)%n]], p1[s1[q]], true));
    //ans = min(ans, linePointDist(p[s[i]], p[s[(i-1+n)%n]], p1[s1[q+1]], true));
    //ans = min(ans, linePointDist(p[s[i]], p[s[(i-1+n)%n]], p1[s1[(q-1+m)%m]], true));

    //ans = min(ans, linePointDist(p[s[i]], p[s[(i-1+n)%n]], p1[s1[q]], true));
  }
  //cout << ans << endl;
  return ans;
  /*
  int q = 1;
  int ans = 0;
  s[top] = 0;
  for (int i = 0; i < top; i++)
  {
    while( ((p[s[i+1]]-p[s[i]])^(p[s[q+1]]-p[s[i]])) > 
           ((p[s[i+1]]-p[s[i]])^(p[s[q]]  -p[s[i]])) )
      q = (q+1)%top;
    ans = max(ans, (p[s[i]]-p[s[q]])*(p[s[i]]-p[s[q]]));
    ans = max(ans, (p[s[i+1]]-p[s[q+1]])*(p[s[i+1]]-p[s[q+1]]));
  }
  return ans;
  */
}
int s1[maxn], s2[maxn];
// 包含边上的点就将 <= 改为 <
int convexHull(Point *p, int n, int *s) {
  sort(p, p + n, cmpxy);
  int top = 0;
  for (int i = 0; i < n; i++) {
    while(top>1 && dcmp(((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]]))) <= 0) top--;
    s[top++] = i;
  }
  int k = top;
  for (int i=n-2;i>=0;i--) {
    while(top>k && dcmp(((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]]))) <= 0) top--;
    s[top++] = i;
  }
  if (n > 1) top--;
  return top;
}

int main()
{
  #ifndef ONLINE_JUDGE
  //freopen("data.in", "r", stdin);
  //freopen("test.out", "w", stdout);
  #endif
  int n, m;
  while(scanf("%d%d", &n, &m) == 2)
  {
    if (n==0 && m==0) break;
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &p[i].x, &p[i].y);
    for (int i = 0; i < m; i++)
      scanf("%lf%lf", &p1[i].x, &p1[i].y);
    n = convexHull(p, n, s1);
    m = convexHull(p1, m, s2);

    printf("%.5f\n", min(rotatingCaliper(p, p1, n, m, s1, s2),
                          rotatingCaliper(p1, p, m, n, s2, s1)));
  }
  return 0;
}
