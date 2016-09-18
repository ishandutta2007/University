#include <bits/stdc++.h>

using namespace std;

double eps = 1e-6;

int dcmp(double x)
{
  if (fabs(x) < eps) return 0;
  if (x < 0) return -1;
  else return 1;
}

int main()
{
  
  int T;
  scanf("%d", &T);
  
  double a, b;

  for (int ka = 1; ka <= T; ka++)
  {
    printf("Case #%d: ", ka);
    cin >> a >> b;
    if (a == b)
    {
      printf("0\n");
      continue;
    }
    double ans;
    if (dcmp(b -0.01) == 0 && dcmp(a - 0.02)>0)
      ans = 0.02;
    else if (dcmp(b - 0.1) == 0 && dcmp(a - 0.2) > 0)
      ans = 0.02;
    else if (dcmp(b - 1.0) == 0 && dcmp(a - 2.0) > 0)
      ans = 0.02;
    else if (dcmp(b - 10.0) == 0 && dcmp(a - 20.0) > 0)
      ans = 0.02;
    else 
      ans = 0.01;
    printf("%.2f\n", ans);
  }
  return 0;
}
