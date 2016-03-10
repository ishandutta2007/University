#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;

long long dp[10020];


int main()
{
	
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	
	
	for(int i = 3; i <= 10000; i++)
		dp[i] = (i-1) *(dp[i-1] + dp[i-2]) % 1000000007;
	
	
	
	
	int T, n;
	
	cin >> T;
	while(T--)
	{
		cin >> n;
		cout << dp[n] << endl;
	}	
	return 0;
}