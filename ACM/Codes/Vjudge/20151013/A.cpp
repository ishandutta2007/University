#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;


int dev[1002000];


int main()
{

	int n;
	scanf("%d", &n);

	int ans = 0;
	int x;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		int len = sqrt(x);
		for(int i = 1; i <= len; i++)
		{
			if(x % i == 0)
			{
				dev[i]++;
				if(dev[i] >= 2)
					ans = max(i, ans);
				if(i*i != x) 
				{
					dev[x/i]++;
					if(dev[x/i] >= 2)
						ans = max(ans, x/i);
				}
			}
		}

	}

	printf("%d\n", ans);

	return 0;
}