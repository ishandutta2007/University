#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

#define ll long long

int n;
bool prime[5000020];


void init()
{
	prime[1] = true;
	for(int i = 2; i <= 5000000;i++)
	{
		if(prime[i] == false)
		{
			for(int j = i*2; j <= 5000000;j+=i)
				prime[j] = true;
		}
	}
}



int main()
{

	// init();
	int x;
	scanf("%d", &x);


	// int ans = 0;
	// for(int i = 5; i <= x; i+=2)
	// 	if(prime[i] == false && prime[i-2]==false && prime[i-4]==false)
	// 		ans++;

	// printf("%d\n", ans);

	if(x >= 7)
		printf("3 5 7\n");
	else printf("No triple\n");

	return 0;
}