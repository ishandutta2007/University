#include <cstdio>
#include <iostream>
#include <cstring>
#define ll long long



void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
     if(!b) {d = a, x = 1, y = 0;}
     else {ext_gcd(b, a % b, d, y, x), y -= x * (a / b);}
}
int main()
{
    ll a,c;
    ll s,e,m;
    ll X,Y,g;
    while(scanf("%lld %lld %lld %lld",&s,&e,&a,&m)!=EOF)
    {
    	if(s+e+a+m == 0) break;
    	m = 1LL<<m;
		c=e-s;
		g = X = Y = 0;
		ext_gcd(a, m, g, X, Y);
		if(c%g!=0)
			printf("FOREVER\n");
		else
		{
			X=X*c/g;
			Y=Y*c/g;
			m=m/g;
			if(X>=0)
				X=X%m;
			else
				X=X%m+m;
			printf("%lld\n",X%m);
		}
	}
    return 0;
}