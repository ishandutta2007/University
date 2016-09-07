#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<double, int> pdi;

const ll oo = 1e9+7;
const int maxn = 100020;
const double PI = acos(-1.0);
const double eps = 1e-8;

double dist(double a1, double b1, double a2, double b2)
{
  double xx = a1-a2, yy = b1-b2;
  return sqrt(xx*xx + yy*yy);
}

double dx, dy;
double V, T;
int n;
double R;
vector<pdi> seg;

int main()
{
  cin >> dx >> dy >> V >> T;
  scanf("%d", &n);
  double tx, ty, tr;
  R = V * T * 1.0;
  for (int i = 0; i < n; i++)
  {
    scanf("%lf%lf%lf", &tx,&ty,&tr);
    // c[i] = Circle(tx-dx, ty-dy, tr);
    double d = dist(tx, ty, dx, dy);
    // cout << d << " " << tr << endl;
    if ((tx-dx)*(tx-dx) + (ty-dy)*(ty-dy) < tr*tr + eps)
    {
      printf("%.2f\n", 1.0);
      return 0;
    }
    if (d > tr + R - eps)
    {
      continue;
    }
    double angMid = atan2(ty - dy, tx - dx);
    double angd;
    if (angMid < 0) angMid += 2*PI;

    if (d*d-tr*tr < R*R + eps)
    {
      angd = asin(tr / d);
    }
    else
    {
      angd = acos((R*R + d*d - tr*tr)/2.0/d/R);
    }
    double angL = angMid - angd;
    double angR = angMid + angd;

    if (angL < 0)
    {
      seg.push_back(pdi(angL + 2*PI, 1));
      seg.push_back(pdi(2*PI, -1));
      seg.push_back(pdi(0, 1));
      seg.push_back(pdi(angR, -1));
    }
    else if(angR > 2*PI)
    {
      seg.push_back(pdi(angL, 1));
      seg.push_back(pdi(2*PI,-1));
      seg.push_back(pdi(0, 1));
      seg.push_back(pdi(angR-2*PI, -1));
    }
    else
    {
      seg.push_back(pdi(angL, 1));
      seg.push_back(pdi(angR,-1));
    }
  }

  double ans = 0.0;
  sort(seg.begin(), seg.end());
  
  // for (int i = 0, len = seg.size(); i < len; i++)
  // {
  //   printf("%.2f %d\n", seg[i].X, seg[i].Y);
  // }


  double last = 0;
  int c = 0;

  for (int i = 0, len = seg.size(); i < len; i++)
  {
    if (c > 0)
    {
      ans += seg[i].X - last;
    }
    c += seg[i].Y;
    last = seg[i].X;
  }

  printf("%.6f\n", ans / (2*PI));

  return 0;
}
