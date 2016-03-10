#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;


int a[100020];
int dp[100020];


int main()
{
	int n;
	scanf("%d", &n);

	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);

		if(a[i] >= a[i-1])
		{
			dp[i] = dp[i-1] + 1;
			ans = max(ans, dp[i]);
		}

		else
			dp[i] = 1;
	}

	printf("%d\n", ans);

	return 0;
}
