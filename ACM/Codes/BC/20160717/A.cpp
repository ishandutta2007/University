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

const int maxn = 12000000;
const int oo = 0x3f3f3f3f;

char str[maxn];
int ans[maxn];
int cnt[11];
int len;


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
  #endif

  int T;
  scanf("%d", &T);
  while(T--)
  {
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    scanf("%s", str);
    len = strlen(str);

    for (int i = 0; i < len; i++)
    {
      cnt[str[i] - '0']++;
    }
    int add = 1;
    while(cnt[add] <= 0 && add < 9) add++;
    cnt[add]--;

    if (len - cnt[0] < 2)
    {
      printf("Uncertain\n");
    }
    else
    {
      int pos = 9;
      for (int i = len-2; i >= 0; i--)
      {
        while(cnt[pos] <= 0) pos--;
        ans[i] = pos;
        cnt[pos]--;
      }
      
      ans[0] += add;
      
      for (int i = 0; i < len; i++)
      {
        if (ans[i] >= 10)
        {
          ans[i] -= 10;
          ans[i+1] += 1;
        }
      }
      if (ans[len-1] != 0) printf("%d",ans[len-1]);
      for (int i = len - 2; i >= 0; i--)
        printf("%d", ans[i]);
      printf("\n");
    }

  }
  return 0;
}
