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
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1000020;
const int oo = 0x3f3f3f3f;

char p[maxn], s[maxn];
char tmp[maxn];
int n, m;

bool check(int st)
{
  if (st + m > n) return false;
  strcpy(tmp, p);
  bool swp = 0;
  for (int i = 0; i < m; i++)
  {
    if (s[i+st] != tmp[i])
    {
      if (s[i+st] != tmp[i+1] || swp == 1)
        return false;
      else
      {
        swp = 1;
        swap(tmp[i], tmp[i+1]);
      }
    }
    else swp = 0;
  }
  return true;
}


int main()
{
  #ifndef ONLINE_JUDGE
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d", &n, &m);
    scanf("%s%s", s, p);
    for (int i = 0; i < n; i++)
    {
      // if (i + m >= n)
      // {
      //   printf("0");
      //   continue;
      // }
      printf("%d", check(i));
    }
    printf("\n");
  }

  return 0;
}
