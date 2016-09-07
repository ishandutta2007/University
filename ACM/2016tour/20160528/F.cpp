#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair< int, string > pis;

const ll mod = 1000000007;
int n, tot;

map<string, int> ha;
map<int, string> rha;
int dist[400][400];
vector<pis> ans;

bool cmp(pis &a, pis &b)
{
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}


int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    tot = 0;

    memset(dist, 0x3f, sizeof(dist));
    ha.clear();
    rha.clear();
    string ss[3];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        cin >> ss[j];
        if (ha.count(ss[j]) == 0)
        {
          tot++;
          ha[ss[j]] = tot;
          rha[tot] = ss[j];
        }
        for (int k = 0; k < j; k++)
          dist[ha[ss[k]]][ha[ss[j]]] = dist[ha[ss[j]]][ha[ss[k]]] = 1;
      }
    }

    for (int k = 1; k <= tot; k++)
      for (int i = 1; i <= tot; i++)
        for (int j = 1; j <= tot; j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    ans.clear();
    int aid = ha["Ahmad"];
    for (int i = 0; i < n; i++)
      ans.push_back(pis(i,dist[aid][i]));

    sort(ans.begin(), ans.end(), cmp);
    for (pis x : ans)
    {
      cout << x.first << " " << x.second << endl;
    }
  }

  return 0;
}
