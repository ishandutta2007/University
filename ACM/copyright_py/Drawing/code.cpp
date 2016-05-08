#include <bits/stdc++.h>
using namespace std;

char s[10020];
char mp[100][100];

int main()
{
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int T;
  scanf("%d", &T);
  int n;
  while(T--)
  {
    scanf("%d", &n);
    scanf("%s", s);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        mp[i][j] = '.';
      mp[i][n] = '\0';
    }

    for (int i = 0, len = min(n*n, (int)strlen(s)); i < len; i++)
    {
      mp[x][y] = s[i];
      if(y >= x && x + y < n - 1) y++;
      else if(y > x && x + y >= n - 1) x++;
      else if(y <= x && x + y > n - 1) y--;
      else if(y < x && x + y <= n - 1)
      {
        x--;
        if(x == y)
        {
          x++;
          y++;
        }
      }
    }
  
    for (int i = 0; i < n; i++)
      printf("%s\n", mp[i]);
    printf("\n");
  }
  return 0;
}