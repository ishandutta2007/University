#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define LL long long
#define mod 100003


LL Pow(LL M, LL N)
{
	if(N == 0) return 1;
	if(N == 1) return M%mod;\
	LL tmp = Pow(M, N/2);
	if(N&1) return (tmp*tmp*M)%mod;
	else return (tmp*tmp)%mod;
}


LL calans(LL M, LL N)
{

	LL tmp = M % mod;
	tmp = tmp * Pow(M-1, N-1);
	return tmp%mod;
}


int main()
{

	LL N, M;

	scanf("%lld%lld",&M,&N);

	printf("%lld\n", (Pow(M, N) - calans(M,N) + mod) % mod);

	return 0;
}