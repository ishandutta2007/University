#include <bits/stdc++.h>
#define first X
#define second Y

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 200002;
const ll oo = 1e9+7;

char str[100];

int main()
{
  int n, len;
  scanf("%s", str);
  n = strlen(str);
  if (str[0] == '-') len = n-1;
  else len = n;
  int cnt2 = 0;
  for (int i = 0; i < n; i++)
  {
    if (str[i] == '2') cnt2++;
  }
  double ans = cnt2*1.0 / len;
  if (n != len) ans *= 1.5;
  if ((str[n-1] - '0') % 2 == 0)
    ans *= 2;
  printf("%.2f%%\n", ans * 100);
  return 0;
}
