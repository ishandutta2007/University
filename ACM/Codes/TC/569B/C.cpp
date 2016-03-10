#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long cnt[1020];
int dp[1020][120];
const int maxn = 10000;
const int mod = 1000000009;
bool isprime[maxn];
int prime[maxn];
void doprime(int N)
//prime[] 储存质数。从 1 based;
{
	int nprime = 0;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for(int i = 2; i <= N; i++)
	{
		if(isprime[i])
		{
			prime[++nprime] = i;
			for(int j = i*i; j <= N; j+=i)
				isprime[j] = false;
		}
	}
}

class MegaFactorialDiv2
{
public:

	int calcnt(int n, int k, int p)
	{
		memset(dp, 0, sizeof(dp));


		for(int i = 1; i <= n; i++)
		{	
			int tmp = i;
			while(tmp % p == 0)
			{
				dp[i][0] ++;
				tmp /= p;
			}

			for(int j = 1; j <= k; j++)
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
		}
		return dp[n][k];
	}


	int countDivisors(int N, int K)
	{

		doprime(1000);
		int M = max(N, K);
		long long ret = 1;
		for(int i = 2; i <= M; i++)if(isprime[i])
			ret = (ret * (calcnt(N, K, i) + 1)) % mod;
		return (int)ret;
	}
}MF;

int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF)
	{

		cout << MF.countDivisors(n, k) << endl;

	}



	return 0;
}

