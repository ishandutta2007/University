#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;


int dp[2020];
int a[1000001];


int main()
{

	int n, m;
	int flag = 0;

	scanf("%d%d",&n,&m);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] %= m;
		if(a[i] == 0) flag = 1;
	}

	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int x = a[i];
		for(int j = m-1; j>=0; j--)
		{
			dp[j+x] += dp[j];
		}

		for(int j = 0; j < m; j++)
		{
			dp[j] += dp[j+m];
			// printf("%d ", dp[j]);
			dp[j+m] = 0;
		}
		// printf("\n");
		if(dp[0] > 1) flag = 1;
	}


	// for(int i = 0; i < m; i++)
	// 	printf("%d ", dp[pre][i]);
	// cout << endl;
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}