#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 120;
const int oo = 1e9+7;

typedef long long ll;
typedef pair<int,int> pii;

int h[maxn][maxn];
int n, m;
int mx[4] = {0,0,-1,1};
int my[4] = {1,-1,0,0};

int main()
{
  int T;
  scanf("%d", &T);

  while(T--)
  {
    scanf("%d%d", &n,&m);
    memset(h, 0, sizeof(h));
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        scanf("%d", &h[i][j]);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) if (h[i][j])
      {
        ans++;
        for (int k = 0; k < 4; k++)
          ans += max(0, h[i][j] - h[i+mx[k]][j+my[k]]);
      }

    printf("%I64d\n", ans);

  }

  return 0;
}
