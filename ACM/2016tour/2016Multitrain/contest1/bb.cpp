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

int n, m;
int cnt;
int sg[1 << 21];

void outputmask(int mask)
{
  for (int i = 0; i < 20; i++)
  {
    if (mask&(1<<i)) printf("1");
    else printf("0");
  }
  printf("\n");
}

void dfs(int mask)
{
  if (sg[mask] != -1) return;

  // printf("mask : ");
  // outputmask(mask);
  int tmp = 0;
  int vis[50] = {0};
  // memset(vis, 0, sizeof(vis));
  for (int pos1 = 0; pos1 < 20; pos1++) if(mask & (1<<pos1))
  {
    for (int pos0 = pos1 + 1; pos0 < 20; pos0++) if (!(mask & (1<<pos0)))
    {
      int tmpmask = mask - (1<<pos1) + (1 << pos0);
      dfs(tmpmask);
      // outputmask(tmpmask);
      // printf("[%d]\n", sg[tmpmask]);
      vis[sg[tmpmask]] = 1;
      while(vis[tmp] == 1) tmp++;
      // tmp = min(tmp, sg[tmpmask]);
      break;
    }
  }

  sg[mask] = tmp;

  // if (tmp == 0) sg[mask] = 1;
  // else sg[mask] = 0;
}


int solve()
{
  int x;
  int mask = 0;
  // cout << cnt << endl;
  for (int i = 0; i < cnt; i++)
  {
    scanf("%d", &x);
    mask |= (1<<(x-1));
  }

  dfs(mask);
  // outputmask(mask);
  // printf("[%d]\n", sg[mask]);
  return sg[mask];
}

void test()
{
  int x;
  int mask = 0;
  // cout << cnt << endl;
  
  for (int i = 0; i < (1 << 20); i++)
    dfs(i);
  // outputmask(mask);
  // printf("[%d]\n", sg[mask]);
  // return sg[mask];
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
  #endif
  // for (int i = 10000; i < (1 << 21); i++)
  //   sg[i] = -1;

  memset(sg, -1, sizeof(sg));

  int T;
  scanf("%d", &T);

  int ans;
  while(T--)
  {
    scanf("%d", &n);
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &cnt);
      ans ^= solve();
    }
    printf("%s\n", ans ? "YES":"NO");
  }
  return 0;
}
