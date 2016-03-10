#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;


typedef long long LL;

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

	LL a, b, p;
	LL ans;
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld", &p);
		int n;
		scanf("%d", &n);
		ans = 0LL;
		while(n--)
		{
			scanf("%lld%lld", &a, &b);
			ans = (ans + pow_mod(a, b, p))%p;
		}

		printf("%lld\n", ans);
	}


	return 0;
}