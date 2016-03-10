#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


typedef long long LL;

LL C, k1, b1, k2;
LL ta, tb;

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


int main()
{

	int ka = 0;
	LL cnt;
	LL aa;
	while(scanf("%I64d%I64d%I64d%I64d", &C, &k1, &b1, &k2) != EOF)
	{
		printf("Case #%d:\n", ++ka);
		cnt = 0;
		for(LL a = 1; a < C; a++)
		{
			aa = pow_mod(a, k1+b1, C);
			LL b = C - aa;
			if(b < 1) continue;


			ta = pow_mod(a, k1, C);
			tb = pow_mod(b, k2, C);
			if(ta == tb || (ta == 0 && tb == 0))
			{
				cnt++;
				printf("%I64d %I64d\n", a, b);
			}
			// else if((aa * ta + b *tb) % C == 0)
			// {
			// 	printf("%I64d %I64d\n", a, b);
			// 	cnt ++;
			// }

		}


		if(cnt == 0)
		{
			printf("-1\n");
		}

	}
	return 0;
}