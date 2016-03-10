#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define ll long long
using namespace std;


void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
     if(!b) {d = a, x = 1, y = 0;}
     else {ext_gcd(b, a % b, d, y, x), y -= x * (a / b);}
}
int main()
{
    
    ll a, b, c;
    ll X,Y,g;
    ll lx,ly,hx,hy;
    while(scanf("%I64d %I64d %I64d",&a,&b,&c)!=EOF)
    {
    	scanf("%I64d%I64d%I64d%I64d",&lx,&hx,&ly,&hy);
		g = X = Y = 0;
		c = -c;
		if(b == 0)
		{
			swap(a, b);
			swap(lx,ly);
			swap(hx,hy);
		}
		if(b == 0)
		{
			if(c == 0)
			{
				printf("%I64d\n", (hx-lx+1)*(hy-ly+1));
			}
			else printf("0\n");
			continue;
		}
		if(a < 0)
		{
			a = -a;
			swap(hx, lx);
			lx = -lx;
			hx = -hx;
		}
		if(b < 0)
		{
			b = -b;
			swap(hy, ly);
			hy = -hy;
			hx = -hx;
		}
		ext_gcd(a, b, g, X, Y);
		if(c%g!=0)
			printf("0\n");
		else
		{
			X=X*c/g;
			Y=Y*c/g;

			// prllf("%d %d\n", X, Y);

			ll d = (lx - X) / b;
			X = X + d*b;
			Y = Y - d*a;
			// prllf("%d %d\n", X, Y);
			while(X < lx)
			{
				X+=b;
				Y-=a;
			}
			ll ans = 0;
			for(ll i = X, j = Y; i <= hx; i+=b, j-=a)
			{
				// prllf("check %d %d\n", i, j);
				// system("pause");
				if(i>=lx && i <= hx && j >= ly && j <= hy)
					ans++;
				if(j < ly) break;
			}
			printf("%I64d\n", ans);
		}
	}
    return 0;
}