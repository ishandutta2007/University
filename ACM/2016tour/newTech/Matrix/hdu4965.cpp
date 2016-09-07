#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int SZ = 13;
const ll oo = 6;

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
int n, k;
int a[15];
int A[1020][10], B[10][1020];
int ans1[1020][1020];
int ans2[1020][1020];

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif


  while(scanf("%d%d", &n, &k)!=EOF)
  {
    if (n == 0 && k == 0) break;
    SZ = k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < k; j++)
      {
        scanf("%d", &A[i][j]);
        A[i][j] %= 6;
      }
    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++)
      {
        scanf("%d", &B[i][j]);
        B[i][j] %= 6;
      }
    per.clear();
    for (int l = 0; l < n; l++)
      for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
          (per.m[i][j] += B[i][l]*A[l][j])%=oo;
        }

    //per.show();
    per = per^(n*n-1);
    //per.show();

    memset(ans1, 0, sizeof(ans1));
    memset(ans2, 0, sizeof(ans2));

    for (int l = 0; l < k; l++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          (ans1[i][j] += A[i][l]*per.m[l][j])%=oo;
    for (int l = 0; l < k; l++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          (ans2[i][j] += ans1[i][l]*B[l][j])%=oo;

    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        ans += ans2[i][j];

    printf("%d\n", ans);
  }
  return 0;
}
