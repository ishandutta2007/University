#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1002;
const ll oo = (int)1e9+7;

int vis[maxn][maxn][4];
char mp[maxn][maxn];
char door[maxn][maxn][4];
deque<pii> qu;
deque<int> ro;
deque<int> tq;
int n, m;
pii st, ed;

map< char, set<int> >indr;

int mx[4] = {-1,0,1,0};
int my[4] = {0,1,0,-1};

bool ck(pii now, int r, int d)
{
  int dr = (d - r + 4) % 4;
  if (indr[mp[now.first][now.second]].count(dr)) return true;
  return false;
}

bool check(pii now, pii to, int r, int d)
{
  if (now.first < 0 || now.second < 0 || now.first >= n || now.second >= m)
    return false;
  if (to.first < 0 || to.second < 0 || to.first >= n || to.second >= m)
    return false;
  
  if (vis[to.first][to.second][r] == 1) return false;
  if (mp[to.first][to.second] == '*')
    return false;

  if (ck(now, r, d) && ck(to, r, (d+2)%4)) return true;
  return false;
}

void go(pii now, int r, int t)
{
  if (vis[now.first][now.second][(r+1)%4] == 0)
  {
    qu.push_back(now);
    ro.push_back((r+1)%4);
    tq.push_back(t+1);
    vis[now.first][now.second][(r+1)%4] = 1;
  }
  pii tmp;
  for (int i = 0; i < 4; i++)
  {
    tmp.first = now.first + mx[i];
    tmp.second = now.second + my[i];
    if (check(now, tmp, r, i))
    {
      qu.push_back(tmp);
      ro.push_back(r);
      tq.push_back(t+1);
      vis[tmp.first][tmp.second][r] = 1;
    }
  }
}
int main()
{
  indr['+'].insert(0);
  indr['+'].insert(1);
  indr['+'].insert(2);
  indr['+'].insert(3);
  indr['-'].insert(1);
  indr['-'].insert(3);
  indr['|'].insert(0);
  indr['|'].insert(2);
  indr['^'].insert(0);
  indr['>'].insert(1);
  indr['<'].insert(3);
  indr['v'].insert(2);
  indr['L'].insert(0);
  indr['L'].insert(1);
  indr['L'].insert(2);
  indr['R'].insert(0);
  indr['R'].insert(2);
  indr['R'].insert(3);
  indr['U'].insert(1);
  indr['U'].insert(2);
  indr['U'].insert(3);
  indr['D'].insert(1);
  indr['D'].insert(3);
  indr['D'].insert(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%s", mp[i]);
  scanf("%d%d", &st.first, &st.second);
  scanf("%d%d", &ed.first, &ed.second);
  st.first --;
  st.second --;
  ed.first --;
  ed.second --;
  vis[st.first][st.second][0] = 1;
  qu.push_back(st);
  ro.push_back(0);
  tq.push_back(0);
  pii now;
  int nro, t;
  while(!qu.empty())
  {
    now = qu.front();
    qu.pop_front();
    nro = ro.front();
    ro.pop_front();
    t = tq.front();
    tq.pop_front();

    vis[now.first][now.second][nro] = 1;

    if (now == ed)
    {
      printf("%d\n", t);
      return 0;
    }
    go(now, nro, t);
  }
  printf("-1\n");
  return 0;
}
