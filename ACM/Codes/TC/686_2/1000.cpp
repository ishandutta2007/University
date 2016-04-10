#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1000000007;

class BracketSequenceDiv2
{
public:
	LL ans;
	LL dp[200][200];
	int count(string s)
	{
		int len = s.length();
		ans = 0;
		dp[0][0] = 1;
		for (int i = 0; i <= len; i++)
			for (int j = 0; j <= len; j++)
			{
				if(j == 0) (ans+=dp[i][j])%=mod;
				for (int k = i + 1; k <= len; k++)
					if(s[k-1] == '(')
					{
						(dp[k][j+1] += dp[i][j])%=mod;
						break;
					}
				if(j != 0) for (int k = i + 1; k <= len; k++)
					if(s[k-1] == ')')
					{
						(dp[k][j-1] += dp[i][j])%=mod;
						break;
					}
			}
		return ans - 1;
	}
};
