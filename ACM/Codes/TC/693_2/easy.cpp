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
typedef long long LL;
typedef pair<int, int> pii;

const int maxN = 1000020;
const int oo = 0x3f3f3f3f;

int G[51][51];

class TriangleEasy
{
public:
  int find(int n, vector <int> x, vector <int> y)
  {
    for (int i = 0, len = x.size(); i < len; i++)
      G[x[i]][y[i]] = G[y[i]][x[i]] = 1;
    int ret = 0;
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        for (int k = j+1; k < n ; k++)
        {
          ret = max(ret, G[i][j] + G[j][k] + G[k][i]);
        }
    return 3 - ret;
  }
};
