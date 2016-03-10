#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int sum[2][100];
int a[100];
int crs[2][100];
int n;

int main()
{

	scanf("%d", &n);

	for(int i = 0; i < 2; i++)
		for(int j = 1; j < n; j++)
		{
			scanf("%d", &crs[i][j]);
			sum[i][j] = sum[i][j-1] + crs[i][j];
		}

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int ans = 0x7fffffff;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			ans = min(ans, a[i] + a[j] + sum[0][i] + sum[1][n-1] - sum[1][i] + sum[0][j] + sum[1][n-1] - sum[1][j]);
		}

	printf("%d\n", ans);

	return 0;
}