#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SZ = 3;

struct matrix {
  double m[SZ][SZ];
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
          c.m[i][j]+=a.m[i][k]*b.m[k][j];
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
        printf("%.2f%c", m[i][j], j == SZ-1? '\n':' ');
    printf("============\n");
  }
};

matrix per;

double m[3];

const double pi = acos(-1.0);

int main()
{
  int T;
  scanf("%d", &T);
  int n;
  double a, l;
  while(T--)
  {
    scanf("%lf%lf%d", &a,&l,&n);
    double theta = a/180.0*pi;

    //cout << pi << endl;
    //cout << a/180.0*pi << endl;
    m[0] = m[1] = 0;
    m[2] = l*1.0;

    //cout << theta << endl;

    per.m[0][0] = cos(theta);
    per.m[0][1] = -sin(theta);
    per.m[0][2] = 1.0;
    per.m[1][0] = sin(theta);
    per.m[1][1] = cos(theta);
    per.m[2][0] = per.m[2][1] = per.m[1][2] = 0.0;
    per.m[2][2] = 1.0;

    //per.show();
    per = per^(n);
    //per.show();
    double ansx=0.0, ansy=0.0;
    for (int i = 0; i < 3; i++)
    {
      ansx += per.m[0][i]*m[i];
      ansy += per.m[1][i]*m[i];
    }
    printf("%.6f %.6f\n", ansx, ansy);
  }
  return 0;
}
