#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;

bool f[120][120];

set<int> en[120];
int n, m, q;


int main()
{
  
  scanf("%d%d%d", &n, &m, &q);
  
  int a, b, x;
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &a, &b, &x);
    if (x == 1)
    {
      f[a][b] = f[b][a] = 1;
    }
    else
    {
      en[a].insert(b);
      en[b].insert(a);
    }
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        f[i][j] = f[i][j] || (f[i][k] && f[k][j]);
  
  for (int i = 0; i < q; i++)
  {
    scanf("%d%d", &a, &b);
    if (en[a].count(b) == 0 && f[a][b])
      printf("No problem\n");
    else if (en[a].count(b) == 0 && f[a][b] == 0)
      printf("OK\n");
    else if (en[a].count(b) && f[a][b])
      printf("OK but...\n");
    else
      printf("No way\n");
  }



  return 0;
}
