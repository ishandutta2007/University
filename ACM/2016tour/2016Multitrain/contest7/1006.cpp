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
typedef unsigned long long ull;

const int maxn = 100020;
const int oo = 1e9+7;
char str[maxn];

set<int> st[maxn];

int bad[maxn];
int q;


const ull xxx = 131;
ull H[maxn], xl[maxn];
void prepre()
{
  xl[0] = 1;
  for (int i = 1; i < maxn; i++)
    xl[i] = xxx * xl[i-1];
}
void pre(char *str, ull *H)
{
  memset(H, 0, sizeof(H));
  int len = strlen(str);
  H[len] = 0;  
  for (int i = len-1; i >= 0; i--)
  {
    H[i] = H[i+1]*xxx + str[i];
  }
}

ull getH(int s, int l, ull *H)
{
  return H[s] - H[s+l] * xl[l];
}


bool check(int s1, int s2, int len)
{
  ull hs1 = getH(s1, len, H);
  ull hs2 = getH(s2, len, H);
  return hs1 == hs2;
}

int cal(int l, int r, int len, int d)
{
  //cout << l << " " << r << " " << len << " " << d << endl;
  for (int i = 1; i*i <= d; i++) if (d%i == 0)
    if (check(l, l+i, len-l-i))
      return i;
  return d;
}
int solve(int l, int r)
{
  int len = r - l + 1;
  int tmp = cal(l, r, len, len);
  if (tmp == 1) return tmp;
  for (int i = len-1; i >= 1; i--) if (!bad[i])
  {
    if (i*2 <= len) continue;
    if (check(l, l+i, len-l-i))
    {
      tmp = min(cal(l, r, len, i), tmp);
      break;
    }
    else
    {
      for (int j = 1; j * j <= i; j++) if (i%j == 0)
      {
        bad[j] = q;
        bad[i/j] = q;
      }
    }
  }
  return tmp;
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  prepre();
  for (int ka = 1; ka <= T; ka++)
  {
    memset(bad, 0, sizeof(bad));
    printf("Case #%d:\n", ka);
    scanf("%s", str);
    pre(str, H);
    int Q;
    scanf("%d", &Q);
    for (int q = 1; q <= Q; q++)
    {
      int l, r;
      memset(bad, 0, sizeof(bad));
      scanf("%d%d", &l, &r);
      printf("%d\n", solve(l-1, r-1));
    }
  }
  return 0;
}
