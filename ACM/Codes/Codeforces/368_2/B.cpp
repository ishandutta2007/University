#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000020;
const int oo = 2*(1e9) + 7;

int n, m, k;

int u[maxn], v[maxn], l[maxn];
bool isk[maxn];

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  
  int ans = oo;

  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &u[i], &v[i], &l[i]);
  }
  
  for (int i = 0; i < k; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    isk[tmp] = 1;
  }

  for (int i = 0; i < m; i++)
  {
    if (isk[u[i]] + isk[v[i]] == 1)
      ans = min(ans, l[i]);
  }

  if (ans == oo) ans = -1;

  cout << ans << endl;

  return 0;
}
