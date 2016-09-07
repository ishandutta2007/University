#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100002;
const ll oo = (int)1e9+7;
const double eps = 1e-8;

int n, t;

double a[20][20];

int dcmp(double a)
{
  if (fabs(a) < eps) return 0;
  return a < 0 ? -1:1;
}


int main()
{
  cin >> n >> t;
  a[1][1] = t;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) if (dcmp(a[i][j] - 1.0) >= 0)
    {
      ans ++;
      a[i+1][j] += (a[i][j] - 1) / 2;
      a[i+1][j+1] += (a[i][j] - 1) / 2;
    }
  
  cout << ans << endl;
}
