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

const int maxn = 1020;
const int oo = 0x3f3f3f3f;

int a[maxn], b[maxn];
int l[maxn], r[maxn];
int p[maxn];
int sum[maxn];
int n, m;
int cnt[maxn];


int main()
{
//  freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  while(T--)
  {
    memset(cnt, 0, sizeof(cnt));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &b[i]);
      cnt[b[i]]--;
    }
    bool ok = true;
    for (int i = 0; i <= n; i++)
    {
      if (cnt[i] != 0)
        ok = false;
    }


    for (int i = 1; i <= m; i++)
      scanf("%d%d", &l[i], &r[i]);
    
    memset(sum, 0, sizeof(sum));
      
    for (int i = 1; i <= n; i++)
    {
      sum[a[i]] ++;
      int tmp = 0;
      for (int j = 1; j <= n; j++)
      {
        if (b[j] == a[i]) tmp++;
        if (tmp == sum[a[i]])
        {
          p[i] = j;
          break;
        }
      }
    }
    for (int i = 1; i <= m; i++)
      sort(p + l[i], p + r[i]+1);
    for (int i = 1; i <= n; i++)
    {
      if (p[i] != i)
      ok = false;
    }
    printf("%s\n", ok ? "Yes":"No"); 
      
  }
  return 0;
}
