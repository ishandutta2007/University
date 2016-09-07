#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 120;

int n;
char bf[maxn];
int a[maxn];

int solve()
{
  int ret = 0;
  int now = a[1];
  for (int i = 2; i <= n; i++)
  {
    if (a[i] == now) continue;
    now = a[i];
    ret++;
  }
  if (now != 1) ret++;
  return ret;
}

int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int T;
  cin >> T;
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%s", bf);
    n = strlen(bf);
    for (int i = 0; i < n; i++)
      a[i+1] = bf[i]=='+'? 1:0;
    printf("Case #%d: %d\n", ka, solve());
  }
  return 0;
}
