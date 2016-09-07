#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int SZ = 13;
const ll oo = 1000;
struct matrix {
  ll m[52][52];
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
int n, r;
int a[60];

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif

  int T;
  scanf("%d", &T);
  while(T--)
  {
    
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      a[i] %= oo;
    }

    SZ = n+1;

    per.clear();

    for (int i = 0; i < n; i++)
    {
      int tmp, x;
      scanf("%d", &tmp);
      while(tmp--)
      {
        scanf("%d", &x);
        per.m[i][x] = 1;
      }
    }

    //per.show();
    per = per^r;
    //per.show();
    for (int i = 0; i < n; i++)
    {
      int ans = 0;
      for (int k = 0; k < n; k++)
        (ans+=per.m[i][k]*a[k])%=oo;
      printf("%d%c", ans, i==n-1? '\n':' ');
    }
  }
  return 0;
}
