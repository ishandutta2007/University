#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 1e5+10;
const int oo = 1e9+7;

typedef pair<int,int> pii;
typedef long long ll;

pii sg[maxn];
int n;
int a[maxn], b[maxn];

void solve()
{
  sort(sg + 1, sg + n + 1);
  int pre = sg[1].X;
  int R = sg[1].Y;
  for (int i = 1; i <= n; i++)
  {
    if (sg[i].X > R)
    {
      printf("%d-%d ", pre, R);
      pre = sg[i].X;
      R = sg[i].Y;
    }
    else
    {
      R = max(R, sg[i].Y);
    }
  }
  printf("%d-%d\n", pre, R);
}

int main()
{
  int T;
  
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
      sg[i].X = oo;
      sg[i].Y = 0;
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
      sg[a[i]].X = min(sg[a[i]].X, i);
      sg[a[i]].Y = max(sg[a[i]].Y, i);
      sg[b[i]].X = min(sg[b[i]].X, i);
      sg[b[i]].Y = max(sg[b[i]].Y, i);
    }
    solve();
  }
  return 0;
}
