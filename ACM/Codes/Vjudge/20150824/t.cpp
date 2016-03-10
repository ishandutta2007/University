#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;



int dp[10][2];
int w[10] = {0, 1, 10, 100, 1000, 10000, 100000,1000000,10000000};
int dp1[1000200];

int __check(int x)
{
	while(x)
	{
		if(x % 10 == 4) return 0;
		if(x % 100 == 62) return 0;
		x /= 10;
	}
	return 1;
}

void init1()
{
	dp1[0] = 0;
	for(int i = 1; i <= 1000000; i++)
	{
		dp1[i] = dp1[i - 1] + __check(i);
	}
}
void dodp()
{
	dp[0][0] = 1;
	dp[0][1] = 0;


	for(int i = 1; i < 10; i++)
	{
		dp[i][0] = dp[i - 1][0] * 8 + dp[i - 1][1] * 7;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		// printf("%d %d\n", i, dp[i][0] + dp[i][1]);
	}
	

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
	if(x == 0) return 0;
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
			if(i == 4) continue;
			else if(i == 2 && dig1 == 6) continue;
			else if(i == 6) ans += dp[high - 1][0];
			else ans += dp[high - 1][0] + dp[high - 1][1];
		}
		// if(dig == 4) return ans - 1;
		if((dig == 4) || (dig == 2 && dig1 == 6)) return ans - 1;
		x %= w[high];
		high--;
		dig1 = dig;
	}
	return ans - 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
	#endif
	dodp();
	// init1();

	// for(int i = 0;;i++)
	// {
	// 	if(dp1[i] != calcnt(i))
	// 	{
	// 		printf("%d %d %d\n", i, dp1[i], calcnt(i));
	// 		return 0;
	// 	}
	// }
	// for(int i = 1; i <= 100; i++)
	// {
	// 	printf("%d %d\n", i, calcnt(i));
	// }
	int n, m;
	while(scanf("%d%d", &n, &m))
	{
		if(n + m == 0) break;


		printf("%d\n", calcnt(m) - calcnt(n - 1));


	}




	return 0;
}