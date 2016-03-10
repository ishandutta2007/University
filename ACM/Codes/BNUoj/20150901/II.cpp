#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;


void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
     if(!b) {d = a, x = 1, y = 0;}
     else {ext_gcd(b, a % b, d, y, x), y -= x * (a / b);}
}



ll calans(ll a, ll b, ll c, ll lx, ll rx, ll ly, ll ry)
{
	if(lx > rx || ly > ry) return 0LL;
	if(a == 0 && b == 0)
	{
		if(c == 0) return (rx-lx+1)*(ry-ly+1);
		else return 0;
	}
	if(a == 0)
	{
		if(c>=ly && c <= ry) return rx-lx+1LL;
		else return 0;
	}
	if(b == 0)
	{
		if(c>=lx && c <= rx) return ry-ly+1LL;
	}

	if(a < 0)
	{
		swap(lx, rx);
		lx = -lx;
		rx = -rx;
		a = -a;
	}
	if(b < 0)
	{
		swap(ly, ry);
		ly = -ly;
		ry = -ry;
		b = -b;
	}

	ll X=0LL, Y=0LL, g=0LL;
	ext_gcd(a, b, g, X, Y);
	if(c%g != 0) return 0LL;

	X=X*c/g;
	Y=Y*c/g;
	a=a/g;
	b=b/g;
	
	ll low, high;
	low = max(ceil((lx-X)*1.0/b), ceil((Y-ry)*1.0/a));
	high = min(floor((rx-X)*1.0/b), floor((Y-ly)*1.0/a));



	return (high - low) + 1LL;

}


int main()
{
    
	ll a, b, c;
	ll rx, ry, lx, ly;

	while(scanf("%lld%lld%lld", &a,&b,&c) != EOF)
	{
		scanf("%lld%lld%lld%lld",&lx,&rx,&ly,&ry);



		printf("%lld\n", calans(a,b,-c,lx,rx,ly,ry));



	}




    return 0;
}