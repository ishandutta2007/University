#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxN = 1000020;
const int oo = 0x3f3f3f3f;

int dcmp(double x)
{
  if(fabs(x) < 1e-8) return 0;
  return x > 0? 1:-1;
}


int main()
{
  double xx1, xx2, yy1, yy2;
  double vx, vy, tmp1, tmp2;
  double x, y;

  cin >> xx1 >> yy1 >> xx2 >> yy2;
  cin >> vx >> vy >> tmp1 >> tmp2;

  x = xx2 - xx1;
  y = yy2 - yy1;

  vx -= tmp1;
  vy -= tmp2;

  if (dcmp(vx * x + vy * y) <= 0)
  {
    printf("%.8f\n", sqrt((xx1-xx2)*(xx1-xx2) + (yy1-yy2)*(yy1-yy2)));
    return 0;
  }
  double costheta = (vx * x + vy * y) / sqrt(vx*vx + vy*vy) / sqrt(x*x + y*y);
  // cout << costheta << endl;
  double sintheta = sqrt(1.0 - costheta*costheta);
  // cout << sintheta << endl;
  printf("%.8f\n", sintheta * sqrt(x*x+y*y));
  return 0;
}
