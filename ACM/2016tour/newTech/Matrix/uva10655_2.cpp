#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int SZ = 13;
struct matrix {
  ll m[3][3];
  matrix() {
    memset(m, 0, sizeof(m));
  }
  matrix(int x) {
    memset(m, 0, sizeof(m));
    for (int i = 0; i < SZ; i++) m[i][i] = x;
  }
  void clear() {
    memset(m, 0, sizeof(m));
  }
  friend matrix operator +(matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < SZ; i++)
      for (int j = 0; j < SZ; j++)
        c.m[i][j] = (a.m[i][j]+b.m[i][j]);
    return c;
  }
  friend matrix operator *(matrix a, matrix b) {
    matrix c;
    for (int k = 0; k < SZ; k++)
      for (int i = 0; i < SZ; i++) if (a.m[i][k])
        for (int j = 0; j < SZ; j++)
          (c.m[i][j]+=a.m[i][k]*b.m[k][j]);
    return c;
  }
  friend matrix operator ^(matrix e, ll k) {
    matrix tmp = matrix(1);
    while(k) {
      if (k&1) tmp = tmp*e;
      k>>=1;
      e=e*e;
    }
    return tmp;
  }
  void show() {
    printf("============\n");
    for (int i = 0; i < SZ; i++)
      for (int j = 0; j < SZ; j++)
        printf("%I64d%c", m[i][j], j == SZ-1? '\n':' ');
    printf("============\n");
  }
};

matrix per;

ll p,q,n;
ll m[3];


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  while(scanf("%lld%lld%lld", &p, &q, &n) == 3)
  {
    SZ = 2;
    per.clear();
    per.m[0][0] = p;
    per.m[0][1] = -1;
    per.m[1][0] = q;
    m[0] = p*p - 2*q;
    m[1] = p*q;
    if (n == 0)
    {
      printf("2\n");
      continue;
    }
    if (n == 1)
    {
      printf("%lld\n", p);
      continue;
    }
    //per.show();
    per = per^(n-2);
    //per.show();
    printf("%lld\n", per.m[0][0] * m[0] + per.m[0][1]*m[1]);
  }
  return 0;
}
