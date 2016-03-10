#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int n;
int a[320][320];
int b[320][320];
int cg[320];

int calch(int tmp[320])
{
	int ret = 0;

	return ret;
}


int main()
{

	scanf("%d", &n);


	if(n == 1)
	{
		printf("1\n");
		return 0;
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &b[i][j]);
	for(int i = 1; i <= n; i++)
		cg[a[1][i]] = i;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = cg[a[i][j]];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			b[i][j] = cg[b[i][j]];


	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			printf("%d%c", a[i][j], j==n? '\n':' ');

	printf("\n");

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			printf("%d%c", b[i][j], j==n? '\n':' ');

	printf("\n");
	int tmprev = 0x3f3f3f3f, id = 1;
	
	for(int i = 2; i <= n; i++)
	{
		int tmp = 0;
		for(int j = 1; j <= n; j++)
			for(int k = j+1; k <= n; k++)
				if(a[i][k] < a[i][j]) tmp++;

		if(tmp < tmprev)
		{
			tmprev = tmp;
			id = i;
		}

	}
	int ans = tmprev;

	for(int i = 1; i <= n; i++)
		cg[b[id][i]] = i;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			b[i][j] = cg[b[i][j]];



	for(int i = 1; i <= n; i++)
		cg[a[1][i]] = i;


	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = cg[a[i][j]];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			b[i][j] = cg[b[i][j]];

	tmprev = 0x3f3f3f3f, id = 1;

	int ttmp[320];
	for(int i = 1; i <= n; i++)
	{

		for(int j = 1; j <= n; j++)
			ttmp[j] = b[j][i];

		int tmp = calch(ttmp);
		if(tmp < tmprev)
		{
			tmprev = tmp;
			id = i;
		}
	}
	printf("%d\n", ans + tmprev);
	return 0;
}