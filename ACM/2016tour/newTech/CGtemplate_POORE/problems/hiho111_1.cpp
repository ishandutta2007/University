#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

double x, y, r;
double mx = 0.0;
int ansx = 0, ansy = 0;

void update(double tmp, int x, int y)
{
  if (tmp > r+eps) return;
  if (tmp > mx+eps)
  {
    mx = tmp;
    ansx = x;
    ansy = y;
  }
  else if (tmp > mx-eps)
  {
    if (x > ansx || (x==ansx && y > ansy))
      ansx = x, ansy = y, mx = tmp;
  }
}

double cal(int xx, int yy)
{
  double x1 = xx*1.0-x;
  double y1 = yy*1.0-y;
  return sqrt(x1*x1 + y1*y1);
}

int main()
{
  cin >> x >> y >> r;
  for (int i = x-r - 100; i <= x+r+100; i++)
  {
    double dy = sqrt((r*r)-(i*1.0-x)*(i*1.0-x));
    double hy = y+dy;
    double ly = y-dy;
//    printf("%d : %.2f %.2f\n", i, hy, ly);
    double tmp;
    tmp = cal(i, (int)hy);
    update(tmp, i, (int)hy);
    tmp = cal(i, (int)hy+1);
    update(tmp, i, (int)hy+1);
    tmp = cal(i, (int)hy-1);
    update(tmp, i, (int)hy-1);
    tmp = cal(i, (int)ly);
    update(tmp, i, (int)ly);
    tmp = cal(i, (int)ly+1);
    update(tmp, i, (int)ly+1);
    tmp = cal(i, (int)ly-1);
    update(tmp, i, (int)ly-1);
  }
  
  printf("%d %d\n", ansx, ansy);

  return 0;
}
