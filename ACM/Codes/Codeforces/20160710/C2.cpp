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

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 100020;
const int oo = 0x3f3f3f3f;

vector<int> G[maxn];
int n, m;
int ans = 0;
int vis[maxn];
int ss;

deque<pii> q;

void bfs(int st)
{
  memset(vis, 0, sizeof(vis));
  q.push_back(pii(st, 0));
  vis[st] = 1;
  while(!q.empty())
  {
    pii now = q.front();
    q.pop_front();
    int u = now.X, t = now.Y;
    ans = max(ans, t);
    ss = u;
    for (int i = 0, len = G[u].size(); i < len; i++) if (!vis[G[u][i]])
    {
      int v = G[u][i];
      q.push_back(pii(v, t+1));
      vis[v] = true;
    }
  }
}


int main()
{
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 1; i <= m; i++)
  {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bfs(1);


  bfs(ss);

  cout << ans << endl;

  return 0;
}
