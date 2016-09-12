#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+20;
char str[maxn];

int main()
{
  
  scanf("%s", str);

  int n = strlen(str);
  if (n%2)
  {
    printf("-1\n");
    return 0;
  }
  

  int x = 0, y = 0;

  for (int i = 0; i < n; i++)
  {
    if (str[i] == 'L') x--;
    if (str[i] == 'R') x++;
    if (str[i] == 'U') y++;
    if (str[i] == 'D') y--;
  }

  if (x < y) swap(x, y);
  ans = y + (x-y)/2;
  printf("%d\n", ans);

  return 0;
}
