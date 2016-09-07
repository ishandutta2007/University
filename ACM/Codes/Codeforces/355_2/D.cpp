#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
const int oo = (int)1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, pii> pip;


int mp[maxn][maxn];
vector<pii> key[maxn*maxn];
vector<pip> cost[maxn*maxn];
int n, m, p;
int dist[maxn][maxn], vis[maxn][maxn];
deque<pip> qu;
int mx[4] = {0,0,-1,1};
int my[4] = {1,-1,0,0};

bool check(pii tmp)
{
	if (tmp.first > 0 && tmp.first <= n && tmp.second > 0 && tmp.second <= m && dist[tmp.first][tmp.second] == -1)
		return true;
	return false;
}

int delta(pii &a, pii &b)
{
  return abs(a.first - b.first) + abs(a.second - b.second);
}

pip mkp(int a, int b, int c)
{
  return pip(c, pii(a, b));
}

void bfs(int st, int ed)
{
  memset(dist, -1, sizeof(dist));
  qu.clear();
  sort(cost[st].begin(), cost[st].end());
  qu.push_back(cost[st][0]);
  int pos = 1;
  int len = cost[st].size();
  pip now, tmp;
  pii nowcell, tmpcell;
  dist[cost[st][0].second.first][cost[st][0].second.second] = cost[st][0].first;
  while(!qu.empty())
  {
    now = qu.front();
    qu.pop_front();
    nowcell = now.second;
    //dist[cost[st][pos].second.first][cost[st][pos].second.second] == -1 && 
    while(cost[st][pos].first <= now.first && pos < len)
    {
      qu.push_back(cost[st][pos]);
      dist[cost[st][pos].second.first][cost[st][pos].second.second] = cost[st][pos++].first;
    }
    for (int i = 0; i < 4; i++)
    {
      tmpcell.first = nowcell.first + mx[i];
      tmpcell.second = nowcell.second + my[i];
      if (check(tmpcell))
      {
        dist[tmpcell.first][tmpcell.second] = now.first + 1;
        qu.push_back(mkp(tmpcell.first, tmpcell.second, now.first + 1));
      }
    }
  }

  for (int i = 0, ll = key[ed].size(); i < ll; i++)
  {
    cost[ed].push_back(mkp(key[ed][i].first, key[ed][i].second, dist[key[ed][i].first][key[ed][i].second]));
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &p);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      scanf("%d", &mp[i][j]);
      key[mp[i][j]].push_back(pii(i, j));
    }
  cost[0].push_back(mkp(1, 1, 0));
  for (int i = 1; i <= p; i++)
  {
    if (key[i-1].size() * key[i].size() > m*n)
    {
      bfs(i-1, i);
      continue;
    }
    for (int j = 0, len = key[i].size(); j < len; j++)
    {
      pii &tmp = key[i][j];
      int tmpcost = oo;
      for (int k = 0, ll = cost[i-1].size(); k < ll; k++)
        tmpcost = min(tmpcost, cost[i-1][k].first + delta(cost[i-1][k].second, tmp));
      dist[tmp.first][tmp.second] = tmpcost;
      cost[i].push_back(mkp(tmp.first, tmp.second, tmpcost));
    }
  }
  cout << cost[p][0].first << endl;
  return 0;
}
