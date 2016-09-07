#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int oo = 1e9+7;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 120;
int n;
int s[maxn];
struct point
{
  int x,y;
  point(int x, int y):x(x),y(y){}
  point(){}
}p[maxn];

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


int check1(int a, int b, int c)
{
  point v1 = p[b]-p[a], v2 = p[c]-p[b];
  return v1*v2;
}

int cal(int a, int b, int c)
{
  point v1 = p[b]-p[a], v2 = p[c]-p[b];
  return v1^v2;
}

int check2(int a, int b)
{
  point v1 = p[b]-p[a];
  return v1*v1;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &p[i].x, &p[i].y);
    int cnt = convexHull();
    if (cnt != n || n < 3)
    {
      printf("NO\n");
      continue;
    }

    int base1 = check1(s[0], s[1], s[2]);
    int base2 = check2(s[0], s[1]);
    
    bool flag = true;
    ll area2 = 0;
    for (int i = 0; i < n; i++)
    {
      if (i > 0)
      {
        area2 += cal(s[i], s[(i+1)%n], s[(i+2)%n]);
      }
      int tmp1 = check1(s[i], s[(i+1)%n], s[(i+2)%n]);
      int tmp2 = check2(s[i], s[(i+1)]%n);
      if (tmp1 != base1 || tmp2 != base2)
        flag = false;
    }
    
    if (area2 == 0 || flag == false)
    {
      printf("NO\n");
    }
    else
    {
      printf("YES\n");
    }

  }
  return 0;
}
