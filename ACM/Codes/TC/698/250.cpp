/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
const int oo = 1e9+7;
const int maxn = 1e4+20;
int dp[100][100];

int solve(string a, string b)
{
  memset(dp, 0x3f, sizeof(dp));
  
  int la = a.length();
  int lb = b.length();
  
  dp[0][0] = 0;
  for (int i = 0; i <= la; i++)
    dp[i][0] = i;
  for (int i = 0; i <= lb; i++)
    dp[0][i] = i;
  for (int i = 1; i <= la; i++)
    for (int j = 1; j <= lb; j++)
    {
      if (a[i-1] == b[j-1])
        dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
      dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
      dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
      dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
    }
  return dp[la][lb];
}

class RepeatString {
public:
  int minimalModify(string s)
  {
    int n = s.length();
    
    int ans = n;
    for (int i = 1; i < n-1; i++)
    {
      string a = s.substr(0, i);
      string b = s.substr(i, n-i);
      ans = min(ans, solve(a, b));
    }
    return ans;
  }
};

/*
int main()
{
  return 0;
}
*/
