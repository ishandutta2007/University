#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull xxx = 131;
const int maxn = 100020;


ull H[maxn], HR[maxn], xl[maxn];
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

int n, m, totlen;
char bf[maxn];
char str[maxn];

int main()
{
  int T;
  scanf("%d", &T);
  for (int ka = 1; ka <= T; ka++)
  {
    printf("Case #%d:\n", ka);
    scanf("%d%d", &n,&m);
    totlen = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%s", bf);
      int dlen = strlen(bf);
      strcpy(str+totlen, bf);
      totlen += dlen;
    }
    
    printf("[%s]\n", str);


  }


  return 0;
}
