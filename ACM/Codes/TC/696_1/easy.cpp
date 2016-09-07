#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 60;

int n, len;
int G[maxn][maxn], vis[maxn], Ha[maxn];
int dp[1<<23];
int cost[1<<23];
set<int> st;
vector<int> ans;

int calcost(int mask)
{
  int & ret = cost[mask];
  if (ret == -1)
  {
    ret = 0;
    for (int i = 0; i < len; i++) if (mask&(1<<i))
    {
      for (int j = i; j < len; j++) if (mask&(1<<j))
      {
        ret += G[Ha[i]][Ha[j]];
      }
    }
  }
  //printf("%d -- %d\n", mask, ret);
  return ret;
}
int cal(set<int> st)
{
  memset(Ha, 0, sizeof(Ha));
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  len = 0;

  for (int x : st)
  {
  	//printf("[%d]\n", x);
    Ha[len++] = x;
  }
  for (int i = 0; i < len; i++)
    for (int mask = 0; mask < (1<<len); mask++) if (__builtin_popcount(mask) == i)
      for (int j = 0; j < len; j++) if ((mask&(1<<j)) == 0)
      {
        dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask] + calcost(mask|(1<<j)));
      }
  //printf("cal : %d\n", dp[(1<<len)-1]);
  return dp[(1<<len) - 1];
}

int bfs(int s)
{
  //printf("bfs:%d\n", s);
  deque<int> Q;
  st.clear();
  vis[s] = 1;
  st.insert(s);
  Q.push_back(s);
  while(!Q.empty())
  {
    int now = Q.front();
    Q.pop_front();
    for (int i = 0; i < 50; i++) if (!vis[i] && G[now][i])
    {
      st.insert(i);
      vis[i] = 1;
      Q.push_back(i);
    }
  }
  //cout << "after bfs" << endl;
  int ret = cal(st);
  return ret;
}
class Gperm
{
public:
  int countfee(vector<int> x, vector<int> y)
  {
    n = x.size();
    for (int i = 0; i < n; i++)
    {
      G[x[i]][y[i]]++;
    //  if (x[i] != y[i])
	      G[y[i]][x[i]]++;
    }
    memset(cost, -1, sizeof(cost));
    for (int i = 0; i < 50; i++) if (vis[i] == 0)
    {
      ans.push_back(bfs(i));
      //cout << "22222" << endl;
    }
    
    //cout << "23333" << endl;
    
    sort(ans.begin(), ans.end());
    int ret = 0, sum = 0;
    for (int i = 0, l = ans.size(); i < l; i++)
    {
      sum += ans[i];
      ret += sum;
    }
    return ret;
  }
}Gp;



int main()
{
  vector<int> x, y;
  int t;
  while(scanf("%d", &t))
  {
    x.clear();
    y.clear();
    memset(G, 0, sizeof(G));
    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < t; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      x.push_back(tmp);
    }


    for (int i = 0; i < t; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      y.push_back(tmp);
    }

    cout << Gp.countfee(x, y) << endl;
  }


  return 0;
}

