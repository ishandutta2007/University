#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>


using namespace std;


typedef long long LL;

const int maxn = 100000;
bool isprime[maxn];
LL prime[maxn];
int doprime(LL N)
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



LL slow_mul(LL a, LL b, LL p)
{
	// cout << a << " " << b << endl;
    LL ret = 0;  
    while(b) {  
        if(b & 1) ret = (ret + a) % p;  
        a = (a + a) % p;
        b >>= 1;  
    }  
    return ret % p;  
}  
  
LL pow_mod(LL a, LL b, LL p)
//快速幂   
{
    LL ret = 1;  
    while(b) {  
        if(b & 1) ret = (ret*a)%p;  
        a = (a*a)%p;  
        b >>= 1;  
    }  
    return ret%p;  
}  

int n;

bool primetest(LL p)
{
	// cout << 1 << endl;
	for(int i = 1; i <= n; i++)
	{
		// cout << prime[i] << endl;
		if(prime[i] >= p) return true;
		if(p % prime[i] == 0) return false;
	}
	return true;
}

bool solve(LL a, LL p)
{
	// cout << 2 << endl;
	if(pow_mod(a, p, p) == a%p)
		return true;
	return false;
}


int main()
{


	LL p, a;
	n = doprime(100000);
	while(scanf("%lld%lld", &p, &a) != EOF)
	{
		if(p == 0 && a == 0) break;
		if(!primetest(p) && solve(a, p))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}