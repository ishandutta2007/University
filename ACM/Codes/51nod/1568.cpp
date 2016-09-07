#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e18;

const int maxn = 10020000;

int cnt[maxn];

void dfs(int now)
{
  if (now == 0) return;
  cnt[now]++;
  dfs(now/2);
  if (now %2==0)
    dfs((now-1)/2);
  else
    dfs(now/2);
}

void showbit(int x)
{
  for (int i = 30; i>=0; i--)
  {
    printf("%d", (x>>i)&1);
  }
  printf("\n");
}

void table(int n)
{
  memset(cnt, 0, sizeof(cnt));
  dfs(n);
  //printf("table: %d\n", n);
  int tot = 0;
  for (int i = 1; i <= n; i++) if (cnt[i])
  {
    showbit(i);
    printf("%d:%d\n", i, cnt[i]);
    tot += cnt[i] != 0;
  }
  printf("\n%d\n", tot);
}


int main()
{
  freopen("data.out", "w", stdout);
  int n = 1000;
  //for (int i = 1; i <= n; i++)
  {
    table(n);
  }
  return 0;
}
