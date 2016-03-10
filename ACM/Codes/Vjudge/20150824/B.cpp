#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int dp[11][2][13];
int m[20];
int w[11] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void prepro()
{
	dp[0][0][0] = 1;
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			for(int k = 0; k < 13; k++)
			{
				int rem = (j * m[i] + k) % 13;
				if(j == 3)
					dp[i][1][rem] += dp[i - 1][0][k] + dp[i - 1][1][k];
				else
					dp[i][0][rem] += dp[i - 1][0][k] + dp[i - 1][1][k] * (j!=1);
			}
		}
	}
	// cout << 999/13 - dp[3][0][0] << endl;
	// dp[0][0][0] = 0;
}

int geth(int x)
{
	int ans = 0;
	while(x){
		x /= 10;
		ans++;
	}
	return ans;
}
int calcnt(int x)
{
	// printf("%d : \n", x);
	
	int pre = 0;
	int dig1 = 0;
	int high = geth(x);
	int ans = 0;
	while(high)
	{
		int dig = x / w[high];
		int r = dig;
		if(high == 1) r++;
		for(int i = 0; i < r; i++)
		{
			// printf("pre = %d\n", pre);
			if(i == 3 && dig1 == 1) continue;
			for(int j = 0; j < 13; j++)
			{
				if((i * m[high] + j + pre) % 13 == 0)
				{

					// printf("mod is zero : %d %d %d %d %d\n", i, j, pre, high, m[high]);
					// // printf("i = %d j = %d, high = %d\n", i, j, high);
					// if(dp[high - 1][0][j])
					// {
					// 	printf("dp[%d][%d][%d] = %d\n",high-1,0,j, dp[high - 1][0][j]);
					// }
					// if(dp[high - 1][1][j]*(i!=1))
					// {
					// 	printf("dp[%d][%d][%d] = %d\n",high-1,1,j, dp[high - 1][1][j]);
					// }
					ans += dp[high - 1][0][j] + dp[high - 1][1][j] * (i != 1);
					// printf("ans = %d\n", ans);
				}
			}
		}
		if(dig == 3 && dig1 == 1)
		{
			// printf("return %d\n", ans - 1);
 			return ans - 1;
		}
		x %= w[high];
		pre = (pre + dig * m[high]) % 13;
		high--;
		dig1 = dig;
	}
	// printf("return %d\n", ans - 1);
	return ans - 1;
}



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	m[0] = m[1] = 1;
	for(int i = 2; i <= 10; i++)
	{
		m[i] = (10 * m[i - 1]) % 13;
	}
	prepro();
	// for(int i = 0; i < 13; i++)
	// 	printf("%d\n", dp[1][0][i]);
	// printf("%d\n", dp[1][0][6]);
	int n;
	// for(int i = 1; i <= 100; i++)
	// 	printf("%d %d\n",i,  i/13 - calcnt(i + 1));
	// printf("%d\n", 13/13 - calcnt(13));
	while(cin >> n)
	{
		// printf("%d - %d = %d\n",n / 13 + 1, calcnt(n), n / 13 + 1 - calcnt(n));
		printf("%d\n", n/13 - calcnt(n));
	}


	return 0;
}