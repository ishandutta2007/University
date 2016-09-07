#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int maxn = 1000;

class DivisibleSetDiv1
{
public:
  string isPossible(vector<int> b)
  {
    int n = b.size();
    for (int i = 0; i < n; i++)
    {
      if (b[i] < n-1)
        return "Impossible";
    }
    return "Possible";
  }

};
