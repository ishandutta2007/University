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

const int maxn = 100;
const int oo = 998244353;
ll ans[maxn][maxn][maxn];
vector<int> G[maxn];

int n, m, K, q;
int w[maxn];

ll dfs(vector<int> A)
{
  sort(A.begin(), A.end());
  int a = A[0], b = A[1], c = A[2];
  if (ans[a][b][c] == -1)
  {
    ans[a][b][c] = 1;
    for (int i1 = 0, l1 = G[a].size(); i1 < l1; i1++)
      for (int i2 = 0, l2 = G[b].size(); i2 < l2; i2++)
        for (int i3 = 0, l3 = G[c].size(); i3 < l3; i3++)
        {
          int na = G[a][i1], nb = G[b][i2], nc = G[c][i3];
          vector<int> AA;
          AA.push_back(na);
          AA.push_back(nb);
          AA.push_back(nc);
          if (abs(w[na]-w[nb])<= K && abs(w[na]-w[nc]) <= K && abs(w[nb]-w[nc]) <= K)
          {
            ans[a][b][c] = (ans[a][b][c]+dfs(AA))%oo;
          }
        }
  }
  return ans[a][b][c];
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  #endif

  int T;
  scanf("%d", &T);
  while (T--)
  {
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i <= 50; i++)
      G[i].clear();
    scanf("%d%d%d%d",&n, &m, &K, &q);
    for (int i = 1; i <= n; i++)
      scanf("%d", &w[i]);
    for (int i = 0; i < m; i++)
    {
      int tx, ty;
      scanf("%d%d", &tx, &ty);
      G[tx].push_back(ty);
    }

    vector<int> a;
    for (int i = 0; i < q; i++)
    {
      a.clear();
      for (int i = 0; i < 3; i++)
      {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
      }
      printf("%I64d\n", dfs(a));
    }
  }
  return 0;
}
