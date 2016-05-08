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

const int maxN = 1000020;
const int oo = 0x3f3f3f3f;

int a[200];
int ans;

int main()
{
  scanf("%d", &T);
  while(T--)
  {
    ans = 0;
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; i++)
      {
        int tmp = a[i] ^ a[j];
        

      }


  }


  return 0;
}