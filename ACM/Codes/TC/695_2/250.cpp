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

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1000020;
const int oo = 0x3f3f3f3f;

double xx, yy;

class BearNSWE
{
public:
  double totalDistance(vector <int> a, string dir)
  {
    int n = a.size();
    double ans = 0.0;
    xx = yy = 0.0;
    for (int i = 0; i < n; i++)
    {
      if (dir[i] == 'N')
      {
        yy = yy + a[i];
      }
      else if (dir[i] == 'S')
      {
        yy = yy - a[i];
      }
      else if (dir[i] == 'W')
      {
        xx = xx - a[i];
      }
      else if (dir[i] == 'E')
      {
        xx = xx + a[i];
      }
      ans = ans + a[i];
    }
    return ans + sqrt(xx*xx + yy*yy);
  }
};

