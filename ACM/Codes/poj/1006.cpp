#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;

void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y)
//a , b 任意
{
     if(!b) {d = a, x = 1, y = 0;}
     else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}

LL CRT(LL *a, LL *m, int n)
{
	LL M = 1, Mi, x0, y0, d, ret = 0;
	for(int i = 0; i < n; i++)
		M *= m[i];
	for(int i = 0; i < n; i++)
	{
		Mi = M/m[i];
		EXT_GCD(Mi, m[i], d, x0, y0);
		ret = (ret+Mi*x0*a[i]) % M;
	}
	if(ret < 0)
		ret += M;
	return ret;
}


int main()
{
	int ka = 0;
	LL m[5] = {23, 28, 33}, a[5], p;
	LL M = 23*28*33;
	while(true)
	{
		scanf("%lld%lld%lld%lld", &a[0], &a[1], &a[2], &p);
		if(p == -1) break;

		LL ans = (CRT(a, m, 3) - p)%M;

		// LL ans = CRT(a, m, 3);
		// while(ans <= p) ans += M;

		// int k = (p-M)/M;

		// ans += (k+1) * M;

		if(ans <= 0) ans+=M;
		printf("Case %d: the next triple peak occurs in %lld days.\n", ++ka, ans);
	}


	return 0;
}