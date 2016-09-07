#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const double eps = 1e-8;
const int maxn = 240;


struct point {
  double x, y, z;
  point(double x , double y, double z):x(x),y(y),z(z){}
  point():x(0.0),y(0.0),z(0.0){}
  void show()
  {
    printf("(%.2f %.2f %.2f)\n", x, y, z);
  }
};

typedef pair<double, point> pdp;


bool operator < (point a, point b)
{
  return a.x < b.x;
}

point operator - (point a, point b)
{
  return point(a.x-b.x, a.y-b.y, a.z-b.z);
}

point operator + (point a, point b)
{
  return point(a.x+b.x, a.y+b.y, a.z+b.z);
}

point operator / (point a, double f)
{
  return point(a.x/f, a.y/f, a.z/f);
}

double operator * (point a, point b)
{
  return a.x*b.x + a.y*b.y + a.z*b.z;
}
int dcmp(double x)
{
  if (fabs(x) < eps) return 0;
  return x > 0? 1:-1;
}

bool operator == (point a, point b)
{
  return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0 && dcmp(a.z-b.z);
}

typedef point vec;

point p[maxn], mid, ver;
vector<pdp> dis;
int n;
int ans1, ans2;

int solve(int u, int v)
{

  printf("(%d %d):", u, v);
  int ans = 0;
  mid = (p[u] + p[v]) / 2;
  ver = p[u]-p[v];
  double basedis = sqrt(ver*ver);
  dis.clear();
  for (int i = 0; i < n; i++) if (i != u && i != v)
  {
    point tmp = p[i] - mid;

    if (dcmp(tmp * ver) == 0)
    {
      printf("%d,", i);
      double tdis = sqrt(tmp*tmp);
      //if (dcmp(tdis) > 0)
        dis.push_back(pdp(tdis, tmp));
    }
  }

  sort(dis.begin(), dis.end());

  if (dis.size() < 2)
  {
    printf("0\n");
    return 0;
  }

  int l = 0;
  double pre = dis[0].X;
  int tmp = 1;
  for (int i = 1, len = dis.size(); i < len; i++)
  {
    if (dcmp(dis[i].X - pre) == 0)
    {
      tmp++;
    }
    else
    {
      if (tmp > 1)
      {
        pre = dis[i].X;
        ans += tmp*(tmp-1)/2;
        
        for (int j = l; j < i; j++)
          for (int k = l+1; k < i; k++)
          {
            point tv1 = dis[j].Y - dis[k].Y;
            double tdis1 = sqrt(tv1*tv1);
            point v1 = p[u] - dis[j].Y - mid;
            point v2 = p[v] - dis[j].Y - mid;
            double v12 = v1*v2/(sqrt(v1*v1)*sqrt(v2*v2));
            if (dcmp(basedis-tdis1)==0 && dcmp(v12-0.5) == 0)
              ans1++;
          }

        l = i;
      }
      tmp = 1;
    }
  }
  if (tmp > 1)
  {
    ans += tmp*(tmp-1)/2;
    int i = dis.size();
    for (int j = l; j < i; j++)
      for (int k = l+1; k < i; k++)
      {
        point tv1 = dis[j].Y - dis[k].Y;
        double tdis1 = sqrt(tv1*tv1);
        point v1 = p[u] - dis[j].Y - mid;
        point v2 = p[v] - dis[j].Y - mid;
        double v12 = v1*v2/(sqrt(v1*v1)*sqrt(v2*v2));
//        printf("[%.2f]\n", v12);
        if (dcmp(basedis-tdis1)==0 && dcmp(v12-0.5) == 0)
          ans1++;
        if (dcmp(tdis1-dis[j].X*2)==0)
          ans2++;
      }
  }
  printf("%d\n", ans);
  return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
   
    int ans = 0;
    ans1 = 0;
    ans2 = 0;
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) 
      {
        ans += solve(i, j);
      }
    printf("%d %d %d\n", ans, ans1, ans2);
    printf("Case #%d: %d\n", ka, (ans-ans1*4/6) / 2);
  }

  return 0;
}
