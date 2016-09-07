#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int vis[12];

int update(int x)
{
  int tmp = 0;
  do
  {
    int d = x%10;
    x/=10;
    if (vis[d] == 0)
    {
      vis[d] = 1;
      tmp++;
    }
  }while(x);
  return tmp;
}


int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  int T;
  cin >> T;
  int mm = 500;
  for (int ka = 1; ka <= T; ka++)
  {
    cin >> n;
    int cnt = 0;
    int now;
    memset(vis,0,sizeof(vis));
    for (int i = 1; i <= mm; i++)
    {
      now = i*n;
      cnt += update(now);
      if (cnt == 10) 
      break;

    }
    if (cnt == 10)
    {
      printf("Case #%d: %d\n", ka,now);
    }
    else
      printf("Case #%d: INSOMNIA\n", ka);

  }
  return 0;
}
