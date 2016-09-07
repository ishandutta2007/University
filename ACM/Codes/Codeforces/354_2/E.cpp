#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100002;
const ll oo = (int)1e9+7;
const double eps = 1e-8;


int n, k;
char nums[maxn][10];
int cntques;
double a[maxn];
double b[maxn];

int dcmp(double x)
{
  if (fabs(x) < eps) return 0;
  return x > 0? 1:-1;
}


bool check()
{
  for (int i = 0; i <= n; i++)
    a[i] = atof(nums[i]);
  b[0] = a[0]/(-5.0);
  for (int i = 1; i < n; i++)
    b[i] = (b[i-1] - a[i]) / 5.0;

  for (int i = 0; i <= n; i++)
  {
    printf("%f %f\n", a[i], b[i]);

  }


  return dcmp(b[n-1] - a[n]) == 0 ? true:false;
}

int main()
{
  scanf("%d%d", &n, &k);
  for (int i = n; i >= 0; i--)
  {
    scanf("%s", nums[i]);
    if (nums[i][0] == '?')
      cntques++;
  }
  if (cntques == 0)
  {
    printf("%s\n", check()? "Yes" : "No");
    return 0;
  }

  return 0;
}
