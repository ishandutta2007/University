#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL getans(LL x)
{
	LL ans = 0;
	while(x)
	{
		ans ^= (x%10);
		x /= 10;
	}
	return ans;
}


LL calans(LL n)
{

	LL start = 1;
	for(LL i = 1; i < n; i++)
		start *= 10;
	LL ans = 0;
	LL endd = start * 10;


	for(LL i = start; i < endd; i++)
	{
		ans += getans(i);
	}
	
	printf("%lld %lld %lld\n", start, endd, ans);
	return ans;
}

int tmp[100];

int main()
{

	LL n = 6;
	for(LL i = 1; i <= n;i++)
	{
		tmp[i] = calans(i);
	}


	for(int i = 2; i <= n; i++)
		printf("%lf\n", ((double)tmp[i]) / tmp[i-1]);


	return 0;
}