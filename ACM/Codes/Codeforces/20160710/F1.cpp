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
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 10020;
const int oo = 0x3f3f3f3f;

vector<int> G[maxn];
int vis[maxn];
int c[maxn];
int n;
ll ans = 0;


void dfs(int now)
{
  vis[now] = true;
  c[now] = 0;
  ll tmp = 0;
  for (int i = 0, len = G[now].size(); i < len; i++) if (!vis[G[now][i]])
  {
    c[now]++;
    dfs(G[now][i]);
    tmp += c[G[now][i]];
  }
  ans += (c[now] * (c[now]-1)) / 2;
  ans += tmp;
}


int main()
{
  scanf("%d", &n);
  int u, v;
  for (int i = 1; i < n; i++)
  {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1);

  cout << ans << endl;
  return 0;
}
