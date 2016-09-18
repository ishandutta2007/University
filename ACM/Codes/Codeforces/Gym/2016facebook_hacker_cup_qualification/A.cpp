#include <bits/stdc++.h>
#define X first
#define Y second
#define P first
#define LEN second

using namespace std;
const int maxn = 2020;
const int oo = 1e9+7;
typedef long long ll;

typedef pair<int,int> point;
map<int,int> mp;


int n;
point star[maxn];
int dist[maxn];


int len(int a, int b)
{
  int dx = star[a].X-star[b].X;
  int dy = star[a].Y-star[b].Y;
  return dx*dx+dy*dy;
}


int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
      scanf("%d%d", &star[i].X, &star[i].Y);

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        dist[j] = len(i, j);
      sort(dist, dist + n);
      
      int pre = 0;
      int cnt = 1;
      for (int j = 1; j < n; j++)
      {
        if (dist[j] != pre)
        {
          ans += cnt*(cnt-1)/2;
          cnt = 1;
          pre = dist[j];
        }
        else
          cnt++;
      }
      ans += cnt*(cnt-1)/2;
    }
    printf("Case #%d: %I64d\n", ka, ans);
  }
  return 0;
}

