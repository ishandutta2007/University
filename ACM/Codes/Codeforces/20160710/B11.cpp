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
int x1, y1, x2, y2;


vector<pii> vpii;


bool check()
{  
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      if (i >= x1-1 && i <= x2+1 && j >= y1-1 && j <= y2+1)
      {
        if (i >= x1 && i <= x2 && j >= y1 && j <= y2)
        {
          if (a[i][j] != 4) return false;
        }
        else if ((i == x1-1 && j == y1-1) || (i == x2+1 && j == y2+1) || (i == x1-1 && j == y2+1) || (i == x2+1 && j == y1-1))
        {
          if (a[i][j] != 1) return false;
        }
        else
        {
          if (a[i][j] != 2) return false;
        }
      }
      else
      {
        if (a[i][j] != 0) return false;
      }
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

  x1 = y1 = 100;
  x2 = y2 = -1;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) if (a[i][j] == 4)
    {
      x1 = min(x1, i);
      x2 = max(x2, i);
      y1 = min(y1, j);
      y2 = max(y2, j);
    }
  if (check()) printf("Yes\n");
  else printf("No\n");
  return 0;
}
