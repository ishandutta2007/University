#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 1e5+10;
const int oo = 1e9+7;

double eps = 1e-8;

typedef long long ll;

int n;
double a[10][10], v[10];

void gauss(int n)
{
    int k=1;
    for (int i=1;i<=n;i++)
    {
        int p=0;
        for (int j=k;j<=n;j++)
            if (fabs(a[j][i])>eps) {    p=j; break;    }
        if (!p) continue;
        for (int l=1;l<=n+1;l++) swap(a[p][l],a[k][l]);
        for (int j=k+1;j<=n;j++)
        {
            double rate=a[j][i]/a[k][i];
            for (int l=1;l<=n+1;l++) 
                a[j][l]-=a[k][l]*rate;
        }
        k++;
    }
    for (int i=n;i;i--)
    {
        v[i]=a[i][n+1];
        for (int j=i+1;j<=n;j++)
            v[i]-=v[j]*a[i][j];
        v[i]/=a[i][i];
    }
}

double h, w;
double px[4], py[4];
double PI = acos(-1.0);

bool onright(double x1, double y1, double x2, double y2)
{
  return (x1*y2-x2*y1) > 0;
}

int main()
{
#ifndef ONLINE_JUDGE
  //freopen("data.in", "r", stdin);
#endif


  cin >> h >> w;

  for (int i = 0; i < 4; i++)
    cin >> px[i] >> py[i];
  
  double v1x, v2x, v1y, v2y;
  v1x = px[1]-px[0];
  v2x = px[2]-px[0];
  v1y = py[1]-py[0];
  v2y = py[2]-py[0];


  if (onright(v1x, v1y, v2x, v2y))
  {
    double theta = atan2(py[1]-py[0], px[1]-px[0]);
    double d = sqrt((px[1]-px[0])*(px[1]-px[0])+(py[1]-py[0])*(py[1]-py[0]));
    d = w / d;
    a[1][1] = 1.0 - 1.0/d*cos(theta);
    a[1][2] = 1.0/d*sin(theta);
    a[1][3] = px[0];
    a[2][1] = -1.0/d*sin(theta);
    a[2][2] = 1.0 - 1.0/d*cos(theta);
    a[2][3] = py[0];
    gauss(2);
  }
  else
  {
    double theta = atan2(py[1]-py[0], px[1]-px[0]);
    theta -= PI;
    double d = sqrt((px[1]-px[0])*(px[1]-px[0])+(py[1]-py[0])*(py[1]-py[0]));
    d = w/d;
    a[1][1] = 1.0 + 1.0/d*cos(theta);
    a[1][2] = 1.0/d*sin(theta);
    a[1][3] = px[0];
    a[2][1] = 1.0/d*sin(theta);
    a[2][2] = 1.0 - 1.0/d*cos(theta);
    a[2][3] = py[0];
    gauss(2);
  }
  printf("%.6lf %.6lf\n", v[1], v[2]);
  return 0;
}
