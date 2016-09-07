#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int SZ = 13;
const ll oo = 10000007;


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


  while(scanf("%d%d", &n,&m) != EOF)
  {
    SZ = n + 2;
    per.clear();
    a[0] = 23;
    a[n+1] = 3;
    for (int i = 1; i <= n; i++)
    {
      scanf("%d", &a[i]);
      a[i] %=oo;
    }

    for (int i = 0; i <= n+1; i++)
      for (int j = 0; j <= n+1; j++)
      {
        if (j == n+1) per.m[i][j] = 1;
        else if (j == 0 && i != n+1) per.m[i][j] = 10;
        else if (i <= n && i >= j) per.m[i][j] = 1;
      }
    per = per^(m);

    per.show();

    ll ans = 0;
    for (int i = 0; i < n+2; i++)
      (ans+=per.m[n][i]*a[i])%=oo;
    printf("%I64d\n", ans);
  }
  return 0;
}
