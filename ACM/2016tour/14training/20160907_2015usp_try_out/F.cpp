#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int maxn = 2e3+20;
typedef pair<int,int> pii;
typedef long long ll;

int n, k;
ll h;
int nu, nd;
int skp;
pii enup[maxn], endown[maxn];

void solveup()
{
  sort(enup, enup+nu);
  for (int i = 0; i < nu; i++)
  {
    if (h > enup[i].X)
      h += enup[i].Y;
    else
      skp ++;
  }
}

ll dp[maxn][maxn];

bool cmp(pii &a, pii &b)
{
  return a.Y > b.Y;
}

void solvedown()
{
  sort(endown+1, endown + nd+1, cmp);
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= k; i++)
    dp[0][i] = h;
  for (int i = 1; i <= nd; i++)
    for (int j = 0; j <= k; j++)
    {
      if (dp[i-1][j] > endown[i].X)
        dp[i][j] = max(dp[i-1][j] - endown[i].X + endown[i].Y, dp[i][j]);
      if (j > 0)
        dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%I64d%d", &n,&h,&k);
    int x, y;
    skp = nu = nd = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &x,&y);
      if (x <= y)
      {
        enup[nu].X = x;
        enup[nu++].Y = y-x;
      }
      else
      {
        endown[++nd].X = x;
        endown[nd].Y = y;
      }
    }
    solveup();
    k -= skp;
    if (k < 0)
    {
      printf("N\n");
      continue;
    }
    solvedown();
    if (dp[nd][k] >= 0)
    //if (skp <= k)
      printf("Y\n");
    else
      printf("N\n");
  }
  return 0;
}

