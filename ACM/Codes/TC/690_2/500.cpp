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

class GerrymanderEasy
{
public:
  double getmax(vector <int> A, vector <int> B, int K)
  {
    double ans = 0.0;
    double x, y;
    int len = A.size();

    for (int i = 0; i < len; i++)
    {
      x = y = 0.0;
      for (int j = i; j < len; j++)
      {
        x += B[j];
        y += A[j];

        if (x / y > ans && j - i + 1 >= K)
        {
          ans = x / y;
        }

      }
    }

    return ans;

  }
};