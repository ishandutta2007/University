#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;


double dp[2][1502][1502];
double p;


int main()
{

	int T;
	scanf("%d", &T);

	while(T--)
	{
		memset(dp, 0, sizeof(dp));

		dp[1][1][1] = 1.0;
		int n, x, y;

		scanf("%d%d%d", &n, &x, &y);
		p = 1.0*y/x;
		
		for(int i = 1; i <= n; i++)
		{
			memset(dp[(i+1)&1], 0, sizeof(dp[(i+1)&1]));
			for(int j = 1; j <= i; j++)
			{
				for(int k = 1; k <= j; k++)
				{
					if(j == k)
					{
						dp[(i+1)&1][j+1][k+1] += dp[i&1][j][k]*p;
					}
					else
					{
						dp[(i+1)&1][j][k+1] += dp[i&1][j][k]*p;
					}
					dp[(i+1)&1][j][1] += dp[i&1][j][k]*(1-p);
				}

			}

		}
		double ans = 0.0;
		for(int i = 1; i <= n+1; i++)
			for(int j = 1; j <= i; j++)
			{
				ans += dp[(n+1)&1][i][j]*i;
			}


		printf("%.3lf\n", ans);
	}





	return 0;
}