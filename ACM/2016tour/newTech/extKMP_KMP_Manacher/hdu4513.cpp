#include <bits/stdc++.h>
using namespace std;

const int maxn = 600000;
const int oo = 1e9+7;
int Mp[maxn*2], Ma[maxn*2];
int a[maxn], n, up[maxn];

void manacher(int len)
{
  int l = 0;
  Ma[l++] = 1;
  Ma[l++] = 2;
  for(int i = 0; i <len; i++)
  {
    Ma[l++] = a[i];
    Ma[l++] = 2;
  }
  Ma[l] = 0;
  int mx = 0, id = 0;
  for(int i = 0; i < l; i++)
  {
    Mp[i] = mx>i? min(Mp[2*id-i],mx-i):1;
    while(Ma[i+Mp[i]] == Ma[i-Mp[i]]) Mp[i]++;
    if(i+Mp[i]>mx)
    {
      mx = i + Mp[i];
      id = i;
    }
  }
}

int solve()
{
  int ret = 0;
  for (int i = 2; i < n*2 + 2; i++)
    ret = max(ret, min(2*up[(i-2)/2], Mp[i]-1));
  return ret;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      if (i == 0 || a[i] < a[i-1])
        up[i] = 1;
      else
        up[i] = up[i-1] + 1;
    }
    manacher(n);
/*
    for (int i = 0; i < n; i++)
      printf("%d %d\n", up[i], Mp[i*2+2]);
*/
    printf("%d\n", solve());
  }
  return 0;
}

