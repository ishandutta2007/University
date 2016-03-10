#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int a, b, c, d, p, m;

LL GCD(LL a, LL b)
{
	if(a % b == 0LL) return b;
	return GCD(b, a % b);
}


int main()
{

	int T;
	scanf("%d", &T);
	for(int ka = 1; ka <= T; ka ++)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&p, &m);



		if(b-a<d-c)
		{
			swap(a, c);
			swap(b, d);
		}


		int mm = ((LL)(m-c)%p + p)%p;

		int l = (a/p)*p +mm;
		int r = (b/p)*p +mm;
		if(l < a) l+=mm;
		if(r > b) r-=mm;
		// printf("%d, %d\n", l, mm);

		LL ans = 0LL;
		
		LL i;
		for(i = l; i <= b; i+=p)
		{
			if(i-a+1 >= d - c + 1)
				break;

			ans+=i-a+1;
		}

		if(r >= i)
			ans += (d-c+1)*((r-i)/3 + 1);

		for(i = r + p - b; i+c <= d; i+=p)
		{
			ans += d-c - i + 1;
		}

		// for(int i = l; i <= b + d - c; i += p)
		// {
		// 	int tmp;
		// 	if(i > b)
		// 	{
		// 		tmp = min(d - c - (i - b) + 1, b - a + 1);
		// 	}
		// 	else 
		// 	{
		// 		tmp = min(i - a + 1, d - c + 1);
		// 	}

		// 	// printf("%d %d\n",i, tmp);
		// 	ans += tmp;
		// }

		if(ans == 0)
			printf("Case #%d: 0/1\n", ka);
		
		else
		{
			LL tmp = (LL)(b-a+1)*(d-c+1);
			LL gcd = GCD(tmp, ans);
			printf("Case #%d: %I64d/%I64d\n",ka, ans/gcd, tmp / gcd);
		}
		// printf("%I64d %I64d\n", ans, (LL)(b-a+1)*(d-c+1));

	}



	return 0;
}