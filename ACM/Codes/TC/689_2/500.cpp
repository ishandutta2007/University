#include <bits/stdc++.h>
using namespace std;

map<long long , int> mp;

class NonDeterministicSubstring
{
public:
  string a, b;

  int check(int s, int e)
  {
    long long mask = 0;

    for (int i = s, j = 0, len = b.length(); i <= e && j < len; i++, j++)
    {
      if (a[i] == b[j] || b[j] == '?') mask = mask * 2 + a[i] - '0';
      else return 0;
    }
    if (mp.find(mask) == mp.end())
    {
      mp[mask] = 1;
      return 1;
    }
    else return 0;
  }


  long long ways(string A, string B)
  {
    long long ret = 0;
    int la = A.length(), lb = B.length();
    a = A, b = B;
    for (int s = 0, e = lb - 1; e < la; s++, e++)
    {
      ret += check(s, e);
    }
    return ret;
  }
};
