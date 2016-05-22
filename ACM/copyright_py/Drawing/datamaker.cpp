#include <bits/stdc++.h>
using namespace std;

char mp[100][100];
char s[10020];


int main()
{
  // freopen("data.source", "r", stdin);
  freopen("tmp.out", "w", stdout);

  // int n;
  // scanf("%d", &n);


  // for (int i = 0; i < n; i++)
  //   scanf("%s", mp[i]);
  // int x = 0, y = 0;
  // for (int i = 0, len = n*n; i < len; i++)
  // {
  //   s[i] = mp[x][y];
  //   if(y >= x && x + y < n - 1) y++;
  //   else if(y > x && x + y >= n - 1) x++;
  //   else if(y <= x && x + y > n - 1) y--;
  //   else if(y < x && x + y <= n - 1)
  //   {
  //     x--;
  //     if(x == y)
  //     {
  //       x++;
  //       y++;
  //     }
  //   }
  // }

  // s[n*n] = '\0';

  for (int ka = 0; ka < 47; ka++)
  {
    int n = rand() % 50 + 1, len = rand()%3000 + 1;
    printf("%d\n", n);

    for (int i = 0; i < len; i++)
      printf("%c", rand()%26 + 'A');

    printf("\n");
  }


  // printf("%d\n", n);
  // printf("%s",s);

  return 0;
}