#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 15020;
inline void ou(int x){ if (x>=10) ou(x/10);putchar(x%10+'0');}
struct point {
  ll x,y;
  int id;
  point(ll x, ll y, int id):x(x),y(y),id(id){}
  point(ll x, ll y):x(x),y(y){}
  point(){}
}p[maxn];
struct ans {
  int a, b, c;
  ans(int a, int b, int c):a(a),b(b),c(c){}
  ans(){}
  void out() {
    ou(a);
    putchar(' ');
    ou(b);
    putchar(' ');
    ou(c);
    putchar('\n');
    //printf("%d %d %d\n", a, b, c);
  }
}va[maxn*10];
typedef point Point;
ll operator * (const point &a, const point &b) {
  return a.x*b.x + a.y*b.y;
}

ll operator ^ (const point &a, const point &b) {
  return a.x*b.y - a.y*b.x;
}

point operator + (const point &a, const point &b) {
  return point (a.x+b.x, a.y+b.y);
}

point operator - (const point &a, const point &b) {
  return point (a.x-b.x, a.y-b.y);
}
bool cmpxy(const point &a, const point &b)
{
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int n, s[maxn];
int vis[maxn];
int top;
int rest;

// 包含边上的点就将 <= 改为 <
int convexHull(Point *p, int n)
{
  //sort(p, p + n, cmpxy);
  int top = 0;
  for (int i=0;i<n;i++) if (!vis[i])
  {
    while(top>1 && ((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]])) <= 0) top--;
    s[top++] = i;
  }
  int k = top;
  for (int i=n-2;i>=0;i--) if (!vis[i])
  {
    while(top>k && ((p[s[top-1]]-p[s[top-2]])^(p[i]-p[s[top-2]])) <= 0) top--;
    s[top++] = i;
  }
  if (n > 1) top--;
  return top;
}

int outer[maxn];
int inner[maxn];
bool ok(const int &sg0, const int &sg1, const int &pp, const int &pc, const int &pn)
{
  point v1 = p[sg0]-p[pc];
  point v2 = p[sg1]-p[pc];
  point l1 = p[pp]-p[pc];
  point l2 = p[pn]-p[pc];
  /*
  show(v1);
  show(v2);
  show(l1);
  show(l2);
  */
  if ((l1^v1)>=0 && (v2^l2)>=0)
    return true;
  if ((v2^l2)>=0 && (v2^l1)>=0)
    return true;
  return false;
}

bool ok1(const int &a, const int &b, const int &c, const int &d)
{
  point v1 = p[b]-p[a], l1 = p[d]-p[a];
  point v2 = p[c]-p[b], l2 = p[d]-p[b];
  point v3 = p[a]-p[c], l3 = p[d]-p[c];
  return !((v1^l1)>=0 && (v2^l2)>=0 && (v3^l3)>=0);
}
int tot;
void add(const int &a, const int &b, const int &c)
{
  va[tot].a = p[a].id;
  va[tot].b = p[b].id;
  va[tot].c = p[c].id;
  tot++;
}

void solve()
{
  bool fst = 1;
  while(rest >= 3)
  {
    //cout << va.size() << endl;
    //printf("rest %d\n", rest);
    int cntout, cntin;
    if (fst)
    {
      cntout = convexHull(p, n);
      fst = 0;
    }
    else
      cntout = cntin;
    rest -= cntout;
    for (int i = 0; i < cntout; i++)
    {
      outer[i] = s[i];
      vis[s[i]] = 1;
    }
    cntin = convexHull(p, n);
    //cout << cntout << " " << cntin << endl;
    if (cntin <= 0)
    {
      for (int i = 2; i < cntout; i++)
        add(s[0], s[i-1], s[i]);
      continue;
    }
    if (cntin == 1)
    {
      for (int i = 0; i < cntout; i++)
      {
        add(outer[i], outer[(i+1)%cntout], s[0]);
      }
      continue;
    }
    if (cntin == 2)
    {
      int now = 0;
      if(!ok1(outer[0], outer[1%cntout], s[now], s[(now+1)%cntin])) now= (now+1)%cntin;
      int st = now;
      for (int i = 0; i < cntout; i++)
      {
        while(!ok1(outer[i], outer[(i+1)%cntout], s[now], s[(now+1)%cntin]))
        {
          add(s[now], s[(now+1)%cntin], outer[i]);
          now= (now+1)%cntin;
        }
        add(outer[i], outer[(i+1)%cntout], s[now]);
      }
      while(now != st)
      {
        add(s[now], s[(now+1)%cntin], outer[0]);
        now = (now+1)%cntin;
      }
      continue;
    }
    //cout << "here" << endl;
    int now = 0;
    while(!ok(outer[0], outer[1%cntout], s[(now-1+cntin)%cntin], s[now], s[(now+1)%cntin])) now = (now+1)%cntin;
    int st = now;
    for (int i = 0; i < cntout; i++)
    {
      while (!ok(outer[i], outer[(i+1)%cntout], s[(now-1+cntin)%cntin], s[now], s[(now+1)%cntin]))
      {
        add(s[now], s[(now+1)%cntin], outer[i]);
        now = (now+1)%cntin;
      }
      add(outer[i], outer[(i+1)%cntout], s[now]);
    }
    while(now != st)
    {
      add(s[now], s[(now+1)%cntin], outer[0]);
      now= (now+1)%cntin;
    }
  }
}
inline ll read() {
  ll x=0,f=1;char c=getchar();
  for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
  for(;isdigit(c);c=getchar()) x=x*10+c-'0';
  return x*f;
}
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  //scanf("%d", &n);
  n = read();
  for (int i = 0; i < n; i++)
  {
    //scanf("%I64d%I64d\n", &p[i].x, &p[i].y);
    p[i].x = read();
    p[i].y = read();
    p[i].id = i+1;
  }
  sort(p, p+n, cmpxy);
  rest = n;
  solve();

  printf("%d\n", tot);
  for (int i = 0; i < tot; i++)
    va[i].out();
  return 0;
}

