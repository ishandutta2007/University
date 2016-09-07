#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 120;


typedef pair<int,int> pii;
map<pii, int> snkid;
int tot;
int n, m, sx,sy, ex, ey;
char mp[maxn][maxn];
int vis[maxn][maxn][1<<6][10];
int mx[4] = {0,0,-1,1};
int my[4] = {1,-1,0,0};

struct node
{
  int x, y, mask, k, t;
  node(){}
  node(int x, int y, int mask, int k, int t):x(x),y(y),mask(mask),k(k),t(t){}
};

typedef node nd;
deque<nd> Q, Qt;

void mark(nd &x)
{
  vis[x.x][x.y][x.mask][x.k] = 1;
}
void mark(int x, int y, int mask, int k)
{
  vis[x][y][mask][k] = 1;
}

bool check(nd &x)
{
  return vis[x.x][x.y][x.mask][x.k] == 1;
}

void show(nd &x)
{
  printf("(%d %d) %d %d %d\n", x.x, x.y, x.mask, x.k, x.t);
}

/*
(0 0) 0 0 0
(0 0) 0 0 0
(0 0) 0 0 0
(0 0) 0 0 0
(0 1) 0 0 1
(0 1) 0 0 1
(0 1) 0 0 1
(0 1) 0 0 1
*/

int bfs()
{
  memset(vis, 0, sizeof(vis));
  nd now, tmp;
  Qt.clear();
  Q.clear();
  Q.push_back(nd(sx, sy, 0, 0, 0));
  mark(sx, sy, 0, 0);
  while(!Q.empty())
  {
    now = Q.front();
    Q.pop_front();
    mark(now);
    //show(now);
    Qt.clear();
    for (int i = 0; i < 4; i++)
    {
      tmp = now;


      tmp.x += mx[i];
      tmp.y += my[i];
      if (!(tmp.x >= 0 && tmp.x < n && tmp.y >= 0 && tmp.y < n)) continue;
      char ch = mp[tmp.x][tmp.y];
      if (ch == '#') continue;
      tmp.t++;
      if (ch == 'T')
      {
        if (tmp.k == m)
          return tmp.t;
      }
      if (ch == 'S')
      {
        int sid = snkid[pii(tmp.x,tmp.y)];
        if ((tmp.mask >>sid & 1) == 0)
        {
          tmp.mask |= (1<<sid);
          tmp.t++;
        }
      }
      if (ch >= '1' && ch <= '9')
      {
        if (ch-'0' == tmp.k + 1)
          tmp.k++;
      }
      if (check(tmp)) continue;
      if (tmp.t == now.t + 1)
      {
        mark(tmp);
        Q.push_back(tmp);
      }
      else
      {
        mark(tmp);
        Qt.push_back(tmp);
      }
    }

    while(!Qt.empty())
    {
      Q.push_back(Qt.front());
      Qt.pop_front();
    }
  }
  return 0;
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  while(scanf("%d%d", &n, &m) != EOF)
  {
    if (n==0 && m==0) break;
    snkid.clear();
    tot = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%s", mp[i]);
      for (int j = 0; j < n; j++)
      {
        if (mp[i][j] == 'S')
        {
          snkid[pii(i, j)] = tot++;
        }
        else if (mp[i][j] == 'K')
        {
          sx=i;sy=j;
        }
        else if (mp[i][j] == 'T')
        {
          ex=i;ey=j;
        }
      }
    }
    int ans = bfs();
    if (ans == 0)
      printf("impossible\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
