#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
const int maxn = 10000;
bool isprime[maxn];
int prime[maxn];
int doprime(int N)
{
	int nprime = 0;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for(int i = 2; i < N; i++)
	{
		if(isprime[i])
		{
			prime[++nprime] = i;
			for(int j = i*i; j < N; j+=i)
				isprime[j] = false;
		}
	}
	
	return nprime;
	
}



vector<int>ans;
int main()
{

	doprime(1020);


	// for(int i = 1; i <= 10; i++)
	// 	cout << prime[i] << endl;
	int n;
	scanf("%d", &n);


	for(int i = 1; prime[i] <= n ; i++)
	{
		for(int j = prime[i]; j <= n; j*=prime[i])
			ans.push_back(j);
	}

	printf("%d\n", (int)ans.size());

	for(int i = 0, len = ans.size(); i < len; i++)
		printf("%d%c", ans[i], i == len-1? '\n' : ' ');

	return 0;
}