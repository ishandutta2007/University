#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int SZ = 13;
ll oo;
struct matrix {
  ll m[5][5];
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
  friend matrix operator *(matrix a, matrix b) {
    matrix c;
    for (int k = 0; k < SZ; k++)
      for (int i = 0; i < SZ; i++) if (a.m[i][k])
        for (int j = 0; j < SZ; j++)
          (c.m[i][j]+=a.m[i][k]*b.m[k][j]%oo)%=oo;
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
int n, m, a, b;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  SZ = 2;
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d%d%d", &a, &b, &n, &m);

    oo = 1;
    for (int i = 1; i <= m; i++)
      oo*=10;

    if (n == 0)
    {
      printf("%d\n", a%oo);
      continue;
    }
    per.clear();
    per.m[0][0] = 1;
    per.m[0][1] = 1;
    per.m[1][0] = 1;
    //per.show();
    per = per^(n-1);
    //per.show();

    printf("%d\n", (per.m[0][0]*b + per.m[0][1]*a)%oo);

  }
  return 0;
}
