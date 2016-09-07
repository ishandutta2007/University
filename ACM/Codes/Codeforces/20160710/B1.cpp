#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 100;
const int oo = 0x3f3f3f3f;

char mp[maxn][maxn];
int a[maxn][maxn];
int tmp[maxn][maxn];
int n;

void inc(int x, int y)
{
  tmp[x][y]++;
  tmp[x][y+1]++;
  tmp[x+1][y]++;
  tmp[x+1][y+1]++;
}


bool check(int x1, int y1, int x2, int y2)
{
  memset(tmp, 0, sizeof(tmp));
  inc(x1, y1);
  inc(x1, y2);
  inc(x2, y2);
  inc(x2, y1);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      if (tmp[i][j] != a[i][j]) return false;
    }
  return true;
}

int main()
{
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    scanf("%s", mp[i] + 1);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = mp[i][j] - '0';


  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= n; j++)
  //   {
  //     printf("%d", a[i][j]);
  //   }
  //   printf("\n");    
  // }

  for (int x1 = 0; x1 <= n; x1++)
    for (int y1 = 0; y1 <= n; y1++)
      for (int x2 = 0; x2 <= n; x2++)
        for (int y2 = 0; y2 <= n; y2++)
        {
          if (check(x1, y1, x2, y2))
          {
            printf("Yes\n");
            return 0;
          }
        }
  printf("No\n");
  return 0;
}
