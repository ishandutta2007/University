#include <bits/stdc++.h>
#define maxn 120
#define maxm 5200
using namespace std;

struct point
{
  int x,y;
  point(int x, int y):x(x),y(y){}
  friend point operator +(point a, point b){ return point(a.x+b.x, a.y+b.y); }
};
const point dir[4]={point(0,1), point(1,0), point(0,-1), point(-1,0)};
int a[maxn][maxn], vis[maxn][maxn];
int x[maxm], y[maxm];
int n, m, tot;
char c;

void color(point st)
{
  deque<point> que;
  que.push_back(st);
  vis[st.x][st.y]=1;
  while (!que.empty())
  {
    point now=que.front();
    //cout<<now.x<<' '<<now.y<<endl;
    que.pop_front();
    for (int i=0;i<4;i++)
    {
      point tmp=now+dir[i];
      if (!vis[tmp.x][tmp.y] && a[tmp.x][tmp.y])
      {
        que.push_back(tmp);
        vis[tmp.x][tmp.y]=1;
      }
    }
  }
}

int judge()
{
  memset(vis,0,sizeof(vis));
  int tmp=0;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
      if (!vis[i][j] && a[i][j])
      {
        color(point(i,j));
        tmp++;
      }
  return tmp;
}

int main()
{
  memset(a,0,sizeof(a));
  scanf("%d%d",&n,&m);
  tot=0;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
      scanf(" %c",&c);
      if (c=='#') a[i][j]=0;
      else if (c=='.') a[i][j]=1;
      else
      {
        a[i][j]=0;
        x[++tot]=i;
        y[tot]=j;
      }
    }
  if (judge()==0)
  {
    if (tot>1) printf("Ambiguous\n");
    else
    {
      a[x[1]][y[1]]=1;
      for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
          if (a[i][j]) printf(j==m?".\n":".");
          else printf(j==m?"#\n":"#");
    }
  }
  else
  {
    for (int i=1;i<=tot;i++) a[x[i]][y[i]]=1;
    if (judge()==1)
    {
      int flag=1;
      for (int i=1;i<=tot;i++)
      {
        a[x[i]][y[i]]=0;
        if (judge()==1)
        {
          flag=0;
          break;
        }
        a[x[i]][y[i]]=1;
      }
      if (flag)
        for (int i=1;i<=n;i++)
          for (int j=1;j<=m;j++)
            if (a[i][j]) printf(j==m?".\n":".");
            else printf(j==m?"#\n":"#");
      else printf("Ambiguous\n");
    }
    else printf("Impossible\n");
  }
  return 0;
}