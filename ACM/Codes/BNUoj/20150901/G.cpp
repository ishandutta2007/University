#include <cstdio>
#include <iostream>
#include <cstring>
#define ll long long



// void gcd(ll a,ll b)
// {
//     if(b==0)
//     {
//         X=1;
//         Y=0;
//         g=a;
//     }
//     else
//     {
//         gcd(b,a%b);
//         ll x1;
//         x1=X;
//         X=Y;
//         Y=x1-(a/b)*Y;
//     }
// }
void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
     if(!b) {d = a, x = 1, y = 0;}
     else {ext_gcd(b, a % b, d, y, x), y -= x * (a / b);}
}
int main()
{
	ll X,Y,g;
    ll a,c;
    ll x,y,m,n,l;
    while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l)!=EOF)
    {
		a=m-n;c=y-x;
        if(a<0)
		{
			a=-a;c=-c;
		}
		g = X = Y = 0;
		ext_gcd(a, l, g, X, Y);
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