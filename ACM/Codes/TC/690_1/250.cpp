#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> sti;

int vis[101];
int found, N, kk;
sti st;
vector<int> ans;

void dfs(int pre, int k, sti has)
{
//  cout << "dfs : " << k << endl;
  if (k >= kk)
  {
    found = 1;
    for (int i = 1; i <= 100; i++) if (vis[i] == 1 && i != N)
    	ans.push_back(i);
    return;
  }
  sti tmphas;
  for (int i = pre + 1; i <= 100 && !found; i++)
  {
    tmphas = has;
    int ok = 1;
    for (int x : has)
    {
      int tmp = x + i;
      if (tmp == N)
      {
        ok = 0;
        break;
      }
      tmphas.insert(tmp);
      tmp = x - i;
      if (tmp == N)
      {
        ok = 0;
        break;
      }
      tmphas.insert(tmp);
    }
    if (ok)
    {
      vis[i] = 1;
      dfs(i, k+1, tmphas);
      vis[i] = 0;
    }
  }

}

class WolfCardGame
{
public:
  vi createAnswer(int tN, int tK)
  {
    N = tN, kk = tK;
    vis[N] = 1;
    sti has;
    has.insert(0);
    found = 0;
    dfs(0, 0, has);
    return ans;
  }
};
