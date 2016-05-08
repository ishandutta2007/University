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
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxN = 200020;
const int oo = 0x3f3f3f3f;

char str[maxN];

int main()
{
  int ans = -1;

  scanf("%s", str);

  int l, r;
  for (l = 0, r = strlen(str) - 1; l < r; l++, r--)
  {
    if(str[l] != str[r])
    {
      if(ans == -1)
      {
        ans = l;
        r++;
      }
      else
      {
        ans = -1;
        break;
      }
    }
  }
  if(ans != -1)
  {
    printf("YES\n");
    printf("%d\n", ans + 1);
    return 0;
  }

  else if(l >= r)
  {
    printf("YES\n");
    printf("%d\n", r + 1);
    return 0;
  }


  for (l = 0, r = strlen(str) - 1; l < r; l++, r--)
  {
    if(str[l] != str[r])
    {
      if(ans == -1)
      {
        ans = r;
        l--;
      }
      else
      {
        ans = -1;
        break;
      }
    }
  }
  if(ans != -1)
  {
    printf("YES\n");
    printf("%d\n", ans + 1);
    return 0;
  }

  printf("NO\n");


  return 0;
}