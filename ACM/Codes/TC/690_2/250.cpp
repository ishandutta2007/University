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

class DoubleString
{
public:
  string check(string S)
  {
    if (S.length() % 2 == 1) return "not square";

    int len = S.length() / 2;

    for (int i = 0; i < len; i++)
    {
      if (S[i] != S[i + len]) return "not square";
    }

    return "square";
  }


};