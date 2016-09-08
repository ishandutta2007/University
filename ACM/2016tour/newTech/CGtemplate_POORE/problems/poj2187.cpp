#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 5e4+20;
struct point
{
  int x,y;
  point(int x, int y):x(x),y(y){}
  point(){}
}p[maxn], poly[maxn];

typedef point Point;

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

bool cmpxy(point a, point b)
{
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int s[maxn];

// 包含边上的点就将 <= 改为 <
int convexHull(Point *p, int n)
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

// s 为保存有序的凸包点的下标的栈
int rotatingCaliper(Point *p, int top)
{
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
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &p[i].x, &p[i].y);
  int cnt = convexHull(p, n);
  printf("%d\n", rotatingCaliper(p, cnt));
  return 0;
}
