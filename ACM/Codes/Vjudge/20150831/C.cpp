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

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	

	for(int i = 1; i <= 2000; i ++)
	{
		for(int j = i; j <= 2000; j++)
		{
			sg[i][j] = 1;
			if(j % i == 0) continue;

			for(int k = 1; k * i <= j; k++)
			{
				sg[i][j] = min(sg[i][j], sg[min(i, j - k * i)][max(i, j - k * i)]);
			}
			if(sg[i][j] == 0) sg[i][j] = 1;
			else sg[i][j] = 0;

		}
	}
	for(int i = 1; i <= 30; i++)
		for(int j = 1; j <= 30; j++)
		{
			printf("%d%c", sg[i][j], j == 30? '\n' : ' ');
		}
	
	int cnt[1200] = {0};
	for(int i = 1; i <= 1000; i++)
		for(int j = i; j <= 2000; j++)
		{
			// printf("%d%c", sg[i][j], j == 30? '\n' : ' ');
			if(sg[i][j] == 0) cnt[i]++;
		}
			
	for(int i = 1; i <= 1000; i++)
	{
		int tmp = i * (1 + sqrt(5.0))/2.0;
		printf("cnt %d\n", cnt[i]);
		if(i + cnt[i] != tmp) {printf("%d %d\n%d %d\n%d\n",i+1, tmp,i+1,i+cnt[i], i);return 0;}
	}

	printf("after check\n");

	// int n, m;
	// while(scanf("%d%d",&n,&m) != EOF)
	// {
	// 	if(n + m == 0) break;
	// 	if(n > m) swap(n, m);
	// 	int tmp = n * (1 + sqrt(5.0))/2;
	// 	if(m <= tmp) printf("Ollie wins\n");
	// 	else printf("Stan wins\n");
	// }


	return 0;
}