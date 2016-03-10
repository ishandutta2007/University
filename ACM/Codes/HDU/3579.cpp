#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>

typedef long long LL;


using namespace std;


LL r[20], a[20];
LL n;

void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y)
//a , b 任意
{
     if(!b) {d = a, x = 1, y = 0;}
     else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}


LL mega_mod(LL n)
//解 n 个一元线性同于方程组
//x ≡ r (mod a)
{
	LL a1, a2, r1, r2, d, c, x, y, x0,s;
	bool flag = true;
	// scanf("%lld%lld", &a1, &r1);
	a1 = a[1];
	r1 = r[1];
	for(int i = 2; i <= n; i++)
	{
		// scanf("%lld%lld", &a2, &r2);
		a2 = a[i];
		r2 = r[i];
		if(!flag) continue;
		c = r2 - r1;
		EXT_GCD(a1, a2, d, x, y);
		if(c%d!=0)
		{
			flag = false;
			continue;
		}
		x0 = x*c/d;
		s = a2/d;
		x0 = (x0%s+s)%s;
		r1=r1+x0*a1;
		a1=a1*a2/d;
	}
	if(flag && r1) return r1;
	if(flag) return a1;
	else return -1LL;
}

int main()
{

	int T;
	scanf("%d", &T);

	for(int ka = 1; ka <= T; ka++)
	{
		scanf("%I64d", &n);
		for(int i = 1; i <= n; i++)
		 	scanf("%I64d", &a[i]);
		for(int i = 1; i <= n; i++)
			scanf("%I64d", &r[i]);


		printf("Case %d: %I64d\n",ka,  mega_mod(n));

	}

	return 0;
}