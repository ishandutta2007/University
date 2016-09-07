#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int SZ;
int oo;
const int maxn = 501;


int n, mm, d, k;
int m[maxn];
struct matrix {
  ll m[maxn];
  matrix() {
    memset(m, 0, sizeof(m));
  }
  /*
  matrix(int x) {
    memset(m, 0, sizeof(m));
    for (int i = 0; i < SZ; i++) m[i][i] = x;
  }
  */
  void clear() {
    memset(m, 0, sizeof(m));
  }
  friend matrix operator *(matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < SZ; i++)
      for (int j = 0; j < SZ; j++)
        c.m[i] = (c.m[i]+a.m[j]*b.m[(i-j+n)%n])%oo;
    return c;
  }
  
  friend matrix operator ^(matrix e, int k) {
    matrix tmp = e;
    while(k) {
      if (k&1) tmp = tmp*e;
      k>>=1;
      e=e*e;
    }
    return tmp;
  }
};

matrix per;
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  while(scanf("%d%d%d%d", &n,&mm,&d,&k) == 4)
  {
    for (int i = 0; i < n; i++)
      scanf("%d", &m[i]);
    SZ = n;
    per.clear();
    for (int x = -d; x <= d; x++)
    {
      int p = (x+n)%n;
      per.m[p] = 1;
    }
    oo = mm;
    per = per^(k-1);

    for (int i = 0; i < n; i++)
    {
      ll tmp = 0;
      for (int j = 0; j < n; j++)
      {
        tmp = (tmp+per.m[(i-j+n)%n]*m[j])%oo;
      }
      printf("%lld%c", tmp, i==n-1? '\n':' ');
    }
  }
  return 0;
}

