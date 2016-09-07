#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e3+20;

int n;
double sg[maxn];

double area(double a, double b, double c)
{
  double p = (a+b+c)/2;
  return sqrt(p*(p-a)*(p-b)*(p-c));
}

double solve(int p1, int p2)
{
  int low = max(p2+1, (int)(lower_bound(sg+1,sg+n+1,sg[p2]-sg[p1])-sg));
  int high = lower_bound(sg+1, sg+n+1, sg[p2]+sg[p1])-sg-1;
  if (low > high || low > n) return 1e20;
  //cout << p1 << " " << p2 << " " << low << " : " << high << endl;
  return min(area(sg[p1],sg[p2],sg[low]), area(sg[p1],sg[p2],sg[high]));
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%lf", &sg[i]);

    sort(sg+1, sg+n+1);
    double ans = 1e20;
    for (int i = 1; i <= n; i++)
      for (int j = i+1; j <= n; j++)
        ans = min(ans, solve(i, j));
    if (ans > 1e19)
      printf("-1\n");
    else
      printf("%.10f\n", ans);
  }
  return 0;
}

