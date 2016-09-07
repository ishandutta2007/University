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

const int maxn = 100020;
const int oo = 1e9+7;

int n, k;
ll c[maxn], d[maxn];
ll tot, ans, catot;
int isca[maxn];



int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &c[i]);
    tot += c[i];
  }
  int pos;
  for (int i = 0; i < k; i++)
  {
    scanf("%d", &pos);
    pos--;
    isca[pos] = 1;
    catot += c[pos];
  }

  //cout << ans << endl;

  //cout << catot<< endl;
  for (int i = 0; i < n; i++)
  {
    if (isca[i]) ans += (tot - c[i]) * c[i];
    else
    {
      ll tmp = catot;
      if (!isca[(i-1+n)%n]) tmp += c[(i-1+n)%n];
      if (!isca[(i+1)%n]) tmp += c[(i+1)%n];
      ans += c[i] * tmp;
    }
    //cout << ans << endl;
  }

  printf("%I64d\n", ans / 2);

  return 0;
}
