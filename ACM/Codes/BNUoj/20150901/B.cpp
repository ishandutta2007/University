#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

#define ll long long

int ans[1020];


int gcd(int a, int b)
{
	if(a % b == 0) return b;
	return gcd(b, a%b);
}



int main()
{
	int T;
	scanf("%d", &T);
	int x;
	ans[1] = 3;
	for(int i = 2; i <= 1000;i++)
	{
		for(int j = 1; j < i;j++)
			if(gcd(i, j) == 1)
				ans[i]++;

		ans[i] = ans[i]*2 + ans[i-1];
	}

	for(int ka = 1; ka <= T; ka++)
	{
		scanf("%d", &x);
		printf("%d %d %d\n",ka, x, ans[x]);
	}




	return 0;
}