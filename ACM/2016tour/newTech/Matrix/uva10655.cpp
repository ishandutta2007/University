#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int SZ = 2;
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
  friend matrix operator *(matrix a, matrix b) {
    matrix c;
    for (int k = 0; k < SZ; k++)
      for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++)
          c.m[i][j]+=a.m[i][k]*b.m[k][j];
    return c;
  }
  friend matrix operator ^(matrix e, int k) {
    matrix tmp = matrix(1);
    while(k) {
      if (k&1) tmp = tmp*e;
      k>>=1;
      e=e*e;
    }
    return tmp;
  }
};

matrix per;

ll p,q;
int n;
ll m[3];


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  while(scanf("%lld%lld", &p, &q) == 2)
  {

    if (scanf("%d", &n) == 1)
    {
      per.m[0][0] = p;
      per.m[0][1] = 1;
      per.m[1][0] = -q;
      per.m[1][1] = 0;

      if (n > 0)
      {
        per = per^(n-1);
        ll ret = per.m[0][0]*p + per.m[1][0]*2;
        printf("%lld\n", ret);
      }

      else
      {
        printf("2\n");
      }
    }
    else
      break;


    /*

    if (p==0 && q==0) break;

    if(scanf("%d", &n) != 1) break;
    
    if (n > 0)
    {
      per.m[0][0] = p;
      per.m[0][1] = 1;
      per.m[1][0] = -q;
      per.m[1][1] = 0;
      per = per^(n-1);
      ll ret = per.m[0][0]*p + per.m[1][0]*2;
      printf("%lld\n", ret);
    }
    else
    {
      printf("2\n");
    }
     
    
    //===== 
     
    scanf("%lld", &n);
    SZ = 2;
    per.m[0][0] = p;
    per.m[0][1] = -1;
    per.m[1][0] = q;
    per.m[1][1] = 0;
    m[0] = p;
    m[1] = 2*q;
    if (n <= 0)
    {
      printf("2\n");
      continue;
    }
    //per.show();
    per = per^(n-1);
    //per.show();
    printf("%lld\n", per.m[0][0] * m[0] + per.m[0][1]*m[1]);
    */
  }
  return 0;
}

