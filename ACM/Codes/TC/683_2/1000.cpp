#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100;

char str[maxn];

class EqualSubstrings2
{
  public:
    int get(string s)
    {
      int ret = 0;
      int n = s.length();
      for (int i = 0; i < n; i++)
        str[i] = s[i];

      for (int s1 = 0; s1 < n; s1++)
        for (int e1 = s1; e1 < n; e1++)
          for (int s2 = e1 + 1; s2 < n; s2++)
          {
            int tmp = 1;
            for (int i = s1, j = s2; i <= e1; i++, j++)
            {
              if (str[i] != str[j]) tmp = 0;
            }
            ret += tmp;
          }
      return ret;
    }

};
