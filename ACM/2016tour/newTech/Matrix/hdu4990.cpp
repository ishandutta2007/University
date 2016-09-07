#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int SZ = 13;
int oo = 10000007;

struct matrix {
  ll m[20][20];
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
int n, m;
int a[15];


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif

  while(scanf("%d%d", &n,&oo) != EOF)
  {
    SZ = 3;
    per.clear();

    per.m[0][0] = 4;
    per.m[0][2] = 2;
    per.m[1][0] = 2;
    per.m[1][2] = 1;
    per.m[2][2] = 1;
    
    a[0] = 2;
    a[1] = 1;
    a[2] = 1;

    if (n == 0)
    {
      printf("0\n");
      continue;
    }

    int m = (n-1)/2;

    per = per^(m);

    //per.show();

    int od = n%2;
    ll ans = 0;
    for (int i = 0; i < 3; i++)
      ans = (ans + per.m[od][i]*a[i])%oo;
    printf("%d\n", ans);
  }
  return 0;
}
