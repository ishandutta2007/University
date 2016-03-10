#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


int dp[10020][10020];
int a[10020];


int main()
{

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);


	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dp[i][j] += dp[i][j^a[i]];
		}
	}


	int ans = 0;
	for(int i = 1; i <= n; i++)
	{	
		if(dp[i][0] > 0)
			ans += pow(2, dp[i][0]);


	}




	return 0;
}
