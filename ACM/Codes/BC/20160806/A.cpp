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
const int oo = 1e9+7;


ll tot;
int n, m;

int main()
{
  #ifndef ONLINE_JUDGE
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
  #endif
  
  int T;
  scanf("%d", &T);
  while(T--)
  {
    tot = 0;
    scanf("%d%d", &n, &m);
    int x;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &x);
      tot += x;
    }
    ll tmp;
    for (int i = 0; i < m; i++)
    {
      scanf("%I64d", &tmp);
      printf("%d", tmp > tot);
    }
    printf("\n");
  }
  


  return 0;
}
