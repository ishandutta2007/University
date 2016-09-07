#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 100;

int G[maxn][maxn]; 
int vis[maxn], visr[maxn];
int n;
vector<int> Ha;
deque<int> Q;

bool bfs(int low, int high)
{
  memset(vis, 0, sizeof(vis));
  int cnt = 1;
  vis[0] = 1;
  Q.clear();
  Q.push_back(0);
  while(!Q.empty())
  {
    int now = Q.front();
    Q.pop_front();
    for (int i = 0; i < n; i++) 
    {
      if (!vis[i] && G[now][i] >= low && G[now][i] <= high)
      {
        Q.push_back(i);
        vis[i] = 1;
        cnt++;
        if (cnt == n) return true;
      }
    }
  }
  return false;
}
bool bfsr(int low, int high)
{
  memset(vis, 0, sizeof(vis));
  int cnt = 1;
  vis[0] = 1;
  Q.clear();
  Q.push_back(0);
  while(!Q.empty())
  {
    int now = Q.front();
    Q.pop_front();
    for (int i = 0; i < n; i++) 
    {
      if (!vis[i] && G[i][now] >= low && G[i][now] <= high)
      {
        Q.push_back(i);
        vis[i] = 1;
        cnt++;
        if (cnt == n) return true;
      }
    }
  }
  return false;
}

bool check(int d)
{
  for (int i = 0, len = Ha.size(); i < len; i++)
  {
    if (bfs(Ha[i], Ha[i]+d) && bfsr(Ha[i], Ha[i]+d))
      return true;
  }
  return false;
}

int solve()
{
  int ans = 150000, low = 0, high = 150000;
  int mid;
  while(low <= high)
  {
    mid = (low + high) / 2;
    if (check(mid))
    {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
}
class HardProof
{
public:
  int minimumCost(vector<int> vec)
  {
    n = sqrt(vec.size());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        G[i][j] = vec[i*n+j];
    sort(vec.begin(), vec.end());
    Ha.push_back(vec[0]);
    for (int i = 1, len = vec.size(); i < len; i++)
      if (vec[i] != vec[i-1])
        Ha.push_back(vec[i]);
    return solve();
  }
};
