#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 200020;

int n, m;
char bf[maxn];
int cnt[maxn];
int low[maxn][20];

int query(int s, int e)
{
  int k = log2(e - s + 1);
  return min(low[s][k], low[e - (1 << k) + 1][k]);
}

void rmqinit()
{
  int mxbit = 20;
  for (int i = 0; i <= n; i++)
    low[i][0] = cnt[i];
  for (int j = 1; j <= mxbit; j++)
    for (int i = 1; i <= n; i++) if (i + (1<<j) - 1 <= n)
      low[i][j] = min(low[i][j-1], low[i+(1<<(j-1))][j-1]);
}

int main()
{
  while(scanf("%d%d", &n,&m) == 2)
  {
    scanf("%s", bf+1);
    cnt[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      if (bf[i] == '(')
        cnt[i] = cnt[i-1] + 1;
      else
        cnt[i] = cnt[i-1] - 1;
    }
    rmqinit();
    int l, r;
    while(m--)
    {
      scanf("%d%d", &l, &r);
      if (l > r) swap(l, r);
      if (bf[l] == bf[r] || (bf[l] == ')' && bf[r] == '('))
      {
        printf("Yes\n");
        continue;
      }
      int tmp = query(l, r-1);
      if (tmp >= 2)
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}
