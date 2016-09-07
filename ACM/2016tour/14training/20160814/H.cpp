#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int maxn = 240;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

set<piii> st;

struct point {
  int x, y, z;
  point(int x , int y, int z):x(x),y(y),z(z){}
  point():x(0),y(0),z(0){}
  void show()
  {
    printf("(%d %d %d)\n", x, y, z);
  }
};

point operator - (point a, point b)
{
  return point(a.x-b.x, a.y-b.y, a.z-b.z);
}

point operator + (point a, point b)
{
  return point(a.x+b.x, a.y+b.y, a.z+b.z);
}

point operator / (point a, int f)
{
  return point(a.x/f, a.y/f, a.z/f);
}

int operator * (point a, point b)
{
  return a.x*b.x + a.y*b.y + a.z*b.z;
}

point operator * (int a, point b)
{
  return point(a*b.x, a*b.y, a*b.z);
}

piii mp(point a)
{
  return piii(a.x, pii(a.y, a.z));
}


point p[maxn], mid, ver;
vector<int> dis;
int n;
int ans1, ans2;

int solve(int u, int v)
{
  //printf("(%d %d):", u, v);
  int ans = 0;
  mid = (p[u] + p[v]) / 2;
  ver = p[u]-p[v];
  dis.clear();
  for (int i = 0; i < n; i++) if (i != u && i != v)
  {
    point tmp = p[i] - mid;
    if (tmp * ver == 0)
    {
      int dis2 = tmp*tmp;
      if (dis2 > 0)
      {
        dis.push_back(dis2);
        if (st.count(mp(2*mid - p[i])))
          ans1++;
      }
    }
  }
  sort(dis.begin(), dis.end());
  if (dis.size() < 2)
  {
    //printf("0\n");
    return 0;
  }
  int pre = dis[0];
  int tmp = 1;
  for (int i = 1, len = dis.size(); i < len; i++)
  {
    if (dis[i] == pre)
      tmp++;
    else
    {
      if (tmp > 1)
        ans += tmp*(tmp-1)/2;
      pre = dis[i];
      tmp = 1;
    }
  }
  if (tmp > 1)
    ans += tmp*(tmp-1)/2;
  //printf("%d\n", ans);
  return ans;
}

bool check1(int i, int j, int k)
{
  int len1 = (p[i]-p[j])*(p[i]-p[j]);
  int len2 = (p[j]-p[k])*(p[j]-p[k]);
  int len3 = (p[k]-p[i])*(p[k]-p[i]);
  return len1 == len2 && len2 == len3;
}

bool check2(int i, int j, int k, int l)
{
  int len = (p[i]-p[j])*(p[i]-p[j]);
  int len1 = (p[i]-p[l])*(p[i]-p[l]);
  int len2 = (p[j]-p[l])*(p[j]-p[l]);
  int len3 = (p[k]-p[l])*(p[k]-p[l]);

  return len == len1 && len == len2 && len == len3;
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
    st.clear();
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
      p[i].x *= 2;
      p[i].y *= 2;
      p[i].z *= 2;
      st.insert(mp(p[i]));
//      p[i].show();
    }
    int ans = 0;
    ans1 = ans2 = 0;
//    printf("%d %d %d\n", ans, ans1, ans2);
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) 
      {
        ans += solve(i, j);
      }
    
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        for (int k = j+1; k < n; k++) if (check1(i, j, k))
        {
          for (int l = k+1; l < n; l++)
            if (check2(i, j, k, l))
              ans2++;
        }

//    printf("%d %d %d\n", ans, ans1, ans2);
    printf("Case #%d: %d\n", ka, (ans-ans1/2-ans2*4) / 2);
  }
  return 0;
}

