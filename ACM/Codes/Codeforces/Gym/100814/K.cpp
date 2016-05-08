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

using namespace std;
typedef unsigned long long LL;

const int maxN = 220;
const int oo = 0x3f3f3f3f;

LL cnt[220], cnttmp[220];
LL ans, a, b, tmp;
int n, p;
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    cin >> a >> b >> n >> p;
    memset(cnt, 0, sizeof(cnt));
    ans = 0;

    for (int i = 0; i < n; i++)
    {
      a *= 10;
      tmp = a / b;
      a = a % b;
      // cout << a << " " << b << endl;
      // cout << "tmp : " << tmp << endl;
      memset(cnttmp, 0, sizeof(cnttmp));
      for (int j = 0; j < p; j++) if (cnt[j] > 0)
      {
        cnttmp[(j*10 + tmp)%p] += cnt[j];
        // cnt[(j*10 + tmp)%p] += cnt[j];
      }
      cnttmp[tmp % p] ++;
      ans += cnttmp[0];
      // cout << ans << endl;
      for (int j = 0; j < p; j++)
        cnt[j] = cnttmp[j];
    }

    cout << ans << endl;
  }
  return 0;
}
