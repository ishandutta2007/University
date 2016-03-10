#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long LL;

void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y)
//a , b 任意
{
     if(!b) {d = a, x = 1, y = 0;}
     else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}


LL mega_mod(int n)
{
	LL a1, a2, r1, r2, d, c, x, y, x0,s;
	bool flag = true;
	scanf("%lld%lld", &a1, &r1);
	for(int i = 1; i < n; i++)
	{
		scanf("%lld%lld", &a2, &r2);
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
	if(flag) return r1;
	else return -1LL;
}



int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%lld\n", mega_mod(n));
	}

	return 0;
}