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
  sort(enup+1, enup+nu+1);
  for (int i = 1; i <= nu; i++)
  {
    if (h > enup[i].X)
      h += enup[i].Y;
    else
      skp++;
  }
}

ll dp[maxn][maxn];
ll mem[maxn][maxn];

bool cmp(pii &a, pii &b)
{
  return a.Y > b.Y;
}
bool solvedown()
{
  sort(endown+1, endown + nd+1, cmp);
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= k; i++)
    dp[0][i] = h;

  for (int i = 1; i <= nd; i++)
    for (int j = 0; j <= k; j++)
    {
      if (dp[i-1][j] > endown[i].X)
        dp[i][j] = max(dp[i][j], dp[i-1][j]+endown[i].Y-endown[i].X);
      if (j > 0)
        dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
    }

  /*
  for (int i = 0; i <= nd; i++)
  {
    for (int j = 0; j <= k; j++)
      printf("%d ", dp[i][j]);
    printf("\n");
  }
  */
  return dp[nd][k] >= 0;
  /*
  for (int i = 0; i < nd; i++)
  {
    if (h >= endown[i].Y)
    {
      h -= endown[i].Y;
      h += endown[i].X;
    }
    else
      skp++;
  }
  */
}

ll solve(int i, int k)
{
  if (i == nd) return 0;
  ll &m = mem[i][k];
  if (m != -1) return m;
  m = endown[i].X-endown[i].Y + solve(i+1, k);
  if (k) m = min(m, solve(i+1, k-1));
  return m;
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
        enup[++nu].X = x;
        enup[nu].Y = y-x;
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
    if (solvedown())
      printf("Y\n");
    else
      printf("N\n");
  }
  return 0;
}

