#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5+7;
const ull xxx = 1315;

ull H[maxn], xl[maxn];
char str[maxn];
ll ans1, ans2;
int ps, pe, s, e;
int len;

void pre()
{
  xl[0] = 1;
  for (int i = 1; i <= len; i++)
    xl[i] = xxx * xl[i-1];
  memset(H, 0, sizeof(H));
  H[len] = 0;  
  for (int i = len-1; i >= 0; i--)
  {
    H[i] = H[i+1]*xxx + str[i];
  }
}

int getnumlen(ll x)
{
  if (x == 0) return 1;
  int ret = 0;
  while(x)
  {
    ret ++;
    x /= 10;
  }
  return ret;
}


ull getH(int s, int l)
{
  return H[s] - H[s+l] * xl[l];
}

bool check(int s1, int s2, int l)
{
  return getH(s1, l) == getH(s2, l);
}

int getpre()
{
  if (ps == -1) return 0;
  int ans = 0;
  int l = 0, r = min(pe-ps, e-s), mid;
  while(l <= r)
  {
    mid = (l+r)/2;
    if (check(ps, s, mid))
    {
      ans = mid;
      l = mid + 1;
    }
    else
      r = mid - 1;
  }
  // printf("[%d]\n", ans);
  
  ans -= getnumlen(ans) - 1;
  return ans;
}

int main()
{
  int n;
  while(scanf("%s", str) != EOF)
  {
    len = strlen(str);
    ans1 = ans2 = 0;
    ps = pe = -1;
    pre();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d", &s, &e);
      ans1 += e - s + 1;
      ans2 += e - s + 1 - getpre() + 2;

      // printf("(%I64d, %I64d)\n", ans1, ans2);

      ps = s;
      pe = e;
    }
    printf("%I64d %I64d\n", ans1, ans2);
  }
  return 0;
}
