#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define X first
#define Y second
#define next nextz

using namespace std;
typedef long long ll;
typedef pair<char, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> TP;
typedef pair<TP, int> TP1;



const int maxn = 1000020;
const int oo = 1e9+7;

set<TP> vis;
deque<TP1> Q;

int n;
char bf[10];

bool check(TP now)
{
  for (int i = 0; i < n; i++) if (now[i].size())
  {
    if (now[i].size() != 7) return false;
    
    for (int j = 1; j < 7; j++)
    {
      if (now[i][j].X != now[i][j-1].X || now[i][j].Y != now[i][j-1].Y-1)
        return false;
    }
  }
  return true;
}

bool move(TP &now, TP &next, int i, int j)
{
  int topi = now[i].size() - 1;
  int boti = now[i].size() - 1;
  int topj = now[j].size() - 1;
  if (topi < 0) return false;
  
  char ch = now[i][topi].X;
  while(boti > 0 && 
        now[i][boti-1].X == now[i][boti].X &&
        now[i][boti-1].Y == now[i][boti].Y+1
       )
  boti--;
  
  if (topj < 0 || (now[j][topj].X == ch && now[j][topj].Y > now[i][boti].Y))
  {
    next = now;
    for (int k = boti; k <= topi; k++)
      next[j].push_back(next[i][k]);
    for (int k = boti; k <= topi; k++)
      next[i].pop_back();
    return true;
  }
  return false;
}
void output(TP tmp)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0, len = tmp[i].size(); j < len; j++)
      printf("%c%d ", tmp[i][j].X, tmp[i][j].Y);
    printf("\n");
  }
}



int bfs(TP tmp)
{
  int mx = 0;
  vis.clear();
  Q.clear();
  vis.insert(tmp);
  Q.push_back(TP1(tmp, 0));
  
  TP1 nowp;
  TP now, next;
  while(!Q.empty())
  {
    nowp = Q.front();
    now = nowp.X;
    Q.pop_front();

    cout << "========================" << endl;
    output(now);
    system("pause");

    if (nowp.Y > mx)
    {
      mx = nowp.Y;
      printf("%d\n", mx);
    }
    if (check(now)) return nowp.Y;
    for (int i = 0 ; i < n; i++)
    {
      for (int j = 0; j < n; j++) if (i != j)
      {
        if (move(now, next, i, j))
        {
          vis.insert(next);
          Q.push_back(TP1(next, nowp.Y+1));
        }
      }
    }
  }
}
int main()
{
  #ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
  #endif
  
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d",&n);
    TP tmp = TP(8);
    /*
    for (int i = 0; i < n; i++)
      printf("%d ", tmp[i].size());
      */
    for (int i = 0; i < n; i++)
    {
      int x;
      scanf("%d", &x);
      for (int j = 0; j < x; j++)
      {
        scanf("%s", bf);
        char ch = bf[0];
        int te = bf[1]-'0', ts = bf[strlen(bf)-1]-'0';
        for (int k = ts; k >= te; k--)
          tmp[i].push_back(pii(ch, k));
      }
    }
    output(tmp);
    printf("Case #%d: %d\n", ka, bfs(tmp));
  }
}
