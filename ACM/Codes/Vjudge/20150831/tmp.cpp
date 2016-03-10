#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;



int sg[10001][10001];


int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	// #endif
	

	// for(int i = 1; i <= 100; i ++)
	// {
	// 	for(int j = i; j <= 100; j++)
	// 	{
	// 		sg[i][j] = 1;
	// 		if(j % i == 0) continue;

	// 		for(int k = 1; k * i <= j; k++)
	// 		{
	// 			sg[i][j] = min(sg[i][j], sg[min(i, j - k * i)][max(i, j - k * i)]);
	// 		}
	// 		if(sg[i][j] == 0) sg[i][j] = 1;
	// 		else sg[i][j] = 0;

	// 	}
	// }

	// int cnt[100] = {0};
	// for(int i = 1; i <= 90; i++)
	// 	for(int j = i; j <= 90; j++)
	// 		if(sg[i][j] == 0) cnt[i]++;

	// for(int i = 1; i <= 90; i++)
	// 	printf("%d\n", cnt[i]);
	// printf("\n");
	long long n, m;
	while(scanf("%I64d%I64d",&n,&m) != EOF)
	{
		if(n + m == 0LL) break;
		if(n > m) swap(n, m);
		if(n == 0) printf("Ollie wins\n");
		long long tmp = n * (1 + sqrt(5.0))/2;
		if(m <= tmp && m > n) printf("Ollie wins\n");
		else printf("Stan wins\n");
	}


	return 0;
}