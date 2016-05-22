#include <bits/stdc++.h>
using namespace std;

int dp[1020][1020];
char s1[1020], s2[1020];


int main()
{

	scanf("%s %s", s1+1, s2+1);
	s1[0] = s2[0] = '.';

	int len1 = strlen(s1) - 1;
	int len2 = strlen(s2) - 1;

	for (int i = 0; i <= len1; i++)
		for (int j = 0; j <= len2; j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = max(i, j);
				continue;
			}
			dp[i][j] = dp[i-1][j-1] + (s1[i] != s2[j]);
			dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1]) + 1);
		}


	cout << dp[len1][len2] << endl;


	return 0;
}