#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;


int n,m,K,Q;
int sumver[100020], sumhor[100020];



int main()
{
	int T;
	scanf("%d", &T);
	int x, y, xx, yy;
	while(T--)
	{
		scanf("%d%d%d%d", &n,&m, &K, &Q);
		for(int i = 0; i < K; i++)
		{
			scanf("%d%d", &x, &y);
			sumver[x] = 1;
			sumhor[y] = 1;
		}

		for(int i = 1; i <= n; i++)
		{
			sumver[i] += sumver[i-1];
		}
		for(int i = 1; i <= m; i++)
		{
			sumhor[i] += sumhor[i-1];
		}


		while(Q--)
		{
			scanf("%d%d%d%d", &x,&y, &xx, &yy);

			if(sumver[xx] - sumver[x-1] == xx-x+1 || sumhor[yy] - sumhor[y-1] == yy - y+1)
			{
				printf("Yes\n");
			}

			else
			{
				printf("No\n");
			}
		}

	}
	return 0;
}