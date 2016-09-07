#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 520;
const int oo = 1e9+7;
typedef pair<int,int> pii;
typedef long long ll;

ll a[maxn][maxn];
ll sumrow[maxn];

int n, x, y, bs;

bool check()
{
  ll st = sumrow[bs];

  for (int i = 0; i < n; i++)
  {
    ll tmp = 0;
    for (int j = 0; j < n; j++)
    {
      tmp += a[j][i];
    }
    if (tmp != st) return false;
  }
  ll tmp = 0;
  for (int i = 0; i < n; i++)
  {
    tmp += a[i][i];
  }
  if (tmp != st) return false;

  tmp = 0;
  for (int i = 0; i < n; i++)
  {
    tmp += a[i][n-i-1];
  }
  if (tmp != st) return false;

  return true;

}



int main()
{
  cin >> n;

  if (n == 1)
  {
    printf("1\n");
    return 0;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == 0)
      {
        x=i, y=j;
      }
    }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      sumrow[i] += a[i][j];
  }
  
  if (x==0) bs = 1;
  else bs = 0;
  bool ok = true;
  for (int i = 0; i < n; i++) if (i != x)
  {
    if (sumrow[i] != sumrow[bs]) ok = false;
  }
  a[x][y] = sumrow[bs] - sumrow[x];
  if (!ok || a[x][y] <= 0 || !check())
    printf("-1\n");
  else
    printf("%I64d\n", a[x][y]);

  return 0;
}
