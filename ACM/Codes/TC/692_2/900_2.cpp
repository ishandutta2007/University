#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo = 1e9+9;
const int maxn = 60;

int isbad[maxn];
int nextp[maxn][maxn];
int dp[maxn][maxn][maxn];
int l;

int f(int p, int r, int k)
{
  int&ret = dp[p][r][k];
  if (ret == -1)
  {
    if (p == l) {ret = 0;}
    else
    {
      ret = 0;
      if (k == 0) ret = 1;
      if (r > 0)
      {
        for (char ch = 'a'; ch <= 'z'; ch++)
          ret = (ret+f(nextp[p][ch-'a'], r-1, k))%oo;
      }
      if (k > 0 && !isbad[p])
      {
        ret = (ret + f(0, r, k-1)) % oo;
      }
    }
  }
  return ret;
}


class LinenCenterEasy
{
public:
	int countStrings(string str, int n, int k)
	{
    memset(dp, -1, sizeof(dp));
    l = str.length();
    for (int i = 0; i < l; i++)
    {
      string tmp = (str.substr(0,i)+str).substr(0,l);
      isbad[i] = tmp == str? true : false;
      if (i == 0) isbad[i] = 0;
    }
    for (int i = 0; i < l; i++)
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      string tmp = str.substr(0, i) + ch;
      for (int j = tmp.size(); j >= 0; j--)
      {
        if (str.substr(0, j) == tmp.substr(tmp.size()-j, j))
        {
          nextp[i][ch-'a'] = j;
          break;
        }
      }
    }
    return f(0, n, k);
	}
};

