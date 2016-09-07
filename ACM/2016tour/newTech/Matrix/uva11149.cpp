#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int SZ = 13;
const ll oo = 10;
struct matrix {
  ll m[50][50];
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
        c.m[i][j] = (a.m[i][j]+b.m[i][j])%oo;
    return c;
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

matrix solve(matrix per, int k)
{
  if (k == 1) return per;
  if (k == 0) return matrix(1);

  if (k&1)
  {
    matrix tmp = solve(per, k/2);
    matrix tmpk = per^(k/2);
    matrix tmpkk = per^(k);
    return tmp+(tmp*tmpk)+tmpkk;
  }
  else
  {
    matrix tmp = solve(per, k/2);
    matrix tmpk = per^(k/2);
    return tmp + (tmp*tmpk);
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  while(scanf("%d%d", &n, &k)!=EOF)
  {
    if (n==0) break;
    
    SZ = n;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        scanf("%d", &per.m[i][j]);
        per.m[i][j] %= oo;
      }

    per = solve(per, k);

    //per.show();

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        //if (per.m[i][j] >= 10) printf("%d\n", 1/0);
        printf("%d%c", per.m[i][j], j==n-1? '\n':' ');
      }
    printf("\n");
  }
  return 0;
}
