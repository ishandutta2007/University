#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;


int mp[20][20], dp[20][20][1<<12];
int n, m;

int main()
{


	scanf("%d%d", &n, &m);
	// for(int i = 0; i < n; i++)
	// 	for(int j = 0; j < m; j++)
	// 		scanf("%d", &mp[i][j]);

	int maxbit = (1 << m) - 1;
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			for(int mask = 0; mask <= maxbit; mask++)
			{
				printf("%d %d %d %d\n", dp[i][j][mask], i, j, mask);
				if(j == m-1)
				{
					dp[i+1][0][mask&(1^maxbit)] = (dp[i+1][0][mask&(1^maxbit)] + dp[i][j][mask]) % 100000000;
					// printf("change : %d %d %d %d\n", dp[i+1][0][mask&(1^maxbit)], i+1, 0, mask&(1^maxbit));
					if(!(mask&1))
					{
						dp[i+1][0][mask^1] = (dp[i+1][0][mask^1] + dp[i][j][mask]) % 100000000;
						// printf("change : %d %d %d %d\n", dp[i+1][0][mask^1], i+1, 0, mask^1);
					}
				}

				else
				{
					dp[i][j+1][mask&(maxbit^(1<<(j+1)))] = (dp[i][j+1][mask&(maxbit^(1<<(j+1)))] + dp[i][j][mask]) % 100000000;
					// printf("change : %d %d %d %d\n", dp[i][j+1][mask&((1<<(j+1))^maxbit)], i, j+1, mask&((1<<(j+1))^maxbit));
					if(!(mask&(1<<(j+1))) && !(mask&(1<<j)))
					{
						dp[i][j+1][mask^(1<<(j+1))] = (dp[i][j+1][mask^(1<<(j+1))] + dp[i][j][mask]) % 100000000;
						// printf("change : %d %d %d %d\n", dp[i][j+1][mask^((1<<(j+1)))], i, j+1, mask^((1<<(j+1))));
					}
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i <= maxbit; i++)
	{
		ans += dp[n-1][m-1][i];
	}
	cout << ans << endl;
	return 0;
}