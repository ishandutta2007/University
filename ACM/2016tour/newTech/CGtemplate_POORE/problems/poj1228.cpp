#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int maxn = 10020;
struct point
{
  int x,y;
  point(int x, int y):x(x),y(y){}
  point(){}
}p[maxn];

bool operator == (const point &a, const point &b)
{
  return a.x == b.x && a.y == b.y;
}
int operator * (point a, point b)
{
  return a.x*b.x + a.y*b.y;
}

int operator ^ (point a, point b)
{
  return a.x*b.y - a.y*b.x;
}

point operator + (point a, point b)
{
  return point (a.x+b.x, a.y+b.y);
}

point operator - (point a, point b)
{
  return point (a.x-b.x, a.y-b.y);
}
int n, s[maxn];
int top;
bool cmpxy(point a, point b)
{
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

bool pointOnSeg(point s1, point s2, point p, bool includeEnd)
{
  if ((s1 == p || s2 == p) && !includeEnd) return false;
  s2 = s2-s1;
  p = p-s1;
  return (s2^p)==0 && (s2*p)>=0;

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

bool check(point a, point b)
{
  for (int i = 0; i < n; i++)
    if (pointOnSeg(a, b, p[i], 0))
      return true;
  return false;
}

// 包含边上的点就将 <= 改为 <
int convexHull()
{
  sort(p, p + n, cmpxy);
  int top = 0;
  for (int i = 0; i < n; i++)
  {
    while(top>1 && ((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]])) <= 0) top--;
    s[top++] = i;
  }
  int k = top;
  for (int i=n-2;i>=0;i--)
  {
    while(top>k && ((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]])) <= 0) top--;
    s[top++] = i;
  }
  if (n > 1) top--;
  return top;
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
      scanf("%d%d", &p[i].x, &p[i].y);
    int cnt = convexHull();
    long long area2 = 0;
    bool ok = true;
    for (int i = 0; i < cnt; i++)
    {
      if (!check(p[s[i]], p[s[(i+1)%cnt]])) ok = false;
      if (i > 0)
        area2 += (p[s[i]]-p[0])^(p[s[i-1]]-p[0]);
    }
    printf("%s\n", ok && area2 != 0? "YES":"NO");
  }
  return 0;
}

