#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp1[1000200];


int __check(int x)
{
	while(x)
	{
		if(x % 10 == 4) return 0;
		if(x % 100 == 62) return 0;
		x /= 10;
	}
	return 1;
}

void init1()
{
	dp1[0] = 0;
	for(int i = 1; i <= 1000000; i++)
	{
		dp1[i] = dp1[i - 1] + __check(i);
	}
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif


	init1();
	// for(int i = 1; i <= 100; i++)
	// 	printf("%d %d\n", i, dp1[i]);
	int n, m;
	while(scanf("%d%d", &n, &m))
	{
		if(n + m == 0) break;
		printf("%d\n", dp1[m] - dp1[n - 1]);
	}




	return 0;
}