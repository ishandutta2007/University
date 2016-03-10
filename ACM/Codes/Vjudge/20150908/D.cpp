#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

#define __maxn 1020
#define EPS 1e-10

using namespace std;

long long ans = 0;
int row[30], col[30], lx[30], rx[30];
int n, m;


void dfs(int dep, int r)
{
	if(dep > m || r > n)
	{
		return;
	}
	if(m - dep <= n-r)
		dfs(dep, r+1);

	for(int i = 1; i <= n; i++)
	{
		if(col[i] == 0 && lx[r+i] == 0 && rx[r-i + 10] == 0)
		{
			if(dep == m - 1)
			{
				ans++;
				continue;
			}
			col[i] = lx[r+i] = rx[r-i+10] = 1;
			// printf("i = %d\n", i);
			dfs(dep+1, r+1);
			col[i] = lx[r+i] = rx[r-i+10] = 0;
		}
	}
}


int main()
{


	scanf("%d%d", &n, &m);

	if(m > n)
	{
		printf("0\n");
		return 0;
	}

	if(m == 0)
	{
		printf("1\n");
		return 0;
	}

	dfs(0, 1);

	printf("%I64d\n", ans);

	return 0;
}