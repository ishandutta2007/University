#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long  LL;


const int maxn = 10000;
bool isprime[maxn];
LL prime[maxn];
int doprime(LL N)
//prime[] 储存质数。从 1 based;
{
	int nprime = 0;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for(LL i = 2; i < N; i++)
	{
		if(isprime[i])
		{
			prime[++nprime] = i;
			for(LL j = i*i; j < N; j+=i)
				isprime[j] = false;
		}
	}
	
	return nprime;
	
}




int main()
{

	doprime(200);

	LL tmp = 1LL;
	int pos = 1;
	LL m = 1000000000000000000;
	cout << m << endl;
	while(tmp < m)
	{
		tmp *= prime[pos++];
	}

	cout << tmp << ' ' << pos << endl;

	return 0;
}