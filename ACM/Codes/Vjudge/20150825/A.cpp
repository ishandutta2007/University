#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

#define __maxn 1020
#define EPS 1e-10

using namespace std;

double f[__maxn][__maxn];
double ori[__maxn][__maxn], ri[__maxn][__maxn], down[__maxn][__maxn];
int R, C;


int main()
{
	while(scanf("%d%d", &R, &C) != EOF)
	{

		for(int i = 1; i <= R; i++)
			for(int j = 1; j <= C; j++)
			{
				scanf("%lf%lf%lf", &ori[i][j], &ri[i][j], &down[i][j]);
			}
		memset(f, 0, sizeof(0));
		// f[1][1] = 2 * ori[1][1] / (1 - ori[1][1]);
		for(int i = R; i >= 1; i--)
			for(int j = C; j >= 1; j--)
			{
				// if(i == R && j == C)
				if(ori[i][j] == 1)
				{
					f[i][j] = 0;
				}
				else 
					f[i][j] = ((f[i+1][j] + 2)*down[i][j] + (f[i][j+1] + 2)*ri[i][j] + 2 * ori[i][j]) / (1 - ori[i][j]);
				// if(ori[i][j] == 1)
				// {
				// 	f[i][j] = (f[i][j-1] + 2) * ri[i][j-1] + (f[i-1][j] + 2) * down[i-1][j];
				// }
				// f[i][j] = f[i-1][j] + down[i-1][j] * 2 + f[i][j-1] + ri[i][j-1] * 2;
				// else 
					// f[i][j] = ((f[i-1][j] + 2)*down[i-1][j] + (f[i][j-1] + 2)*ri[i][j-1] + 2 * ori[i][j]) / (1 - ori[i][j]);
				// printf("%d %d %lf\n", i, j, f[i][j]);
			}
		printf("%.3lf\n", f[1][1]);
	}

	return 0;
}