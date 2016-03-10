#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
using namespace std;


typedef long long LL;

LL array[5000200];



int main()
{

	int T;
	scanf("%d", &T);

	LL a, b;
	int n;


	// cout << LONG_LONG_MIN << endl;

	for(int ka = 1; ka <= T; ka++)
	{
		scanf("%d%I64d%I64d", &n, &a, &b);


		for(int i = 0; i < n; i++)
			scanf("%I64d", &array[i]);


		printf("Case #%d: ", ka);
		sort(array, array + n);

		if(a == 0 && b == 0)
		{
			printf("0\n");
			continue;
		}

		if(a == 0)
		{
			if(b > 0)
			{
				printf("%I64d\n", b * array[n-1]);
				continue;
			}
			else
			{
				printf("%I64d\n", b * array[0]);
				continue;
			}
		}

		if(b == 0)
		{
			if(a > 0)
			{
				printf("%I64d\n",a * max(array[0]*array[0], array[n-1]*array[n-1]));
				continue;
			}
			else
			{	
				LL tmp = 1000200;
				for(int i = 0; i < n; i++)
					if(abs(array[i]) < tmp)
						tmp = abs(array[i]);

				printf("%I64d\n", tmp*tmp*a);
				continue;
			}
		}


		if(a > 0 && b > 0)
		{
			LL tmp1 = array[n-1], tmp2 = array[n-2], tmp3 = array[0];

			LL ans = a*tmp1*tmp1 + b*tmp2;

			if(ans < a*tmp2*tmp2 + b*tmp1)
			{
				ans = a*tmp2*tmp2 + b*tmp1;
			}
			if(ans < a*tmp3*tmp3 + b*tmp1)
			{
				ans = a*tmp3*tmp3 + b*tmp1;
			}
		}


		if(a > 0 && b < 0)
		{
			
		}


	}

	return 0;
}