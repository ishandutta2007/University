#include <cstdio>
#include <iostream>
#include <cstring>


typedef long long LL;


void EXT_GCD(LL a, LL b, LL &d, LL &x, LL &y){
     if(!b) {d = a, x = 1, y = 0;}
     else {EXT_GCD(b, a % b, d, y, x), y -= x * (a / b);}
}

LL ext_gcd(LL a, LL b, LL& x, LL& y)
{
	LL x1=0LL, y1=1LL, x0=1LL, y0=0LL;
	LL r = (a%b + b) % b;
	LL q = (a-r) / b;
	x = 0LL,y = 1LL;
	while(r)
	{
		x = x0-q*x1;
		y = y0-q*y1;
		x0=x1;
		y0=y1;
		x1=x;
		y1=y;
		a=b;
		b=r;
		r=a%b;
		q=(a-r)/b;
	}
	return b;
}
int main()
{
	LL X,Y,g;
    LL a,c;
    LL x,y,m,n,l;


    a = 0, c = 0;

    // g = ext_gcd(a, c, X, Y);
    EXT_GCD(a, c, g, X, Y);
    printf("%lld %lld %lld\n", X, Y, g);


    while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)!=EOF)
    {
		a=m-n;c=y-x;
        if(a<0)
		{
			a=-a;c=-c;
		}
		g = X = Y = 0;
		g = ext_gcd(a, l, X, Y);
		// EXT_GCD(a, l, g, X, Y);
		// gcd(a,l);
		if(c%g!=0)
			printf("Impossible\n");
		else
		{
			X=X*c/g;
			Y=Y*c/g;
			l=l/g;
			if(X>=0)
				X=X%l;
			else
				X=X%l+l;
			printf("%lld\n",X%l);
		}
	}
    return 0;
}