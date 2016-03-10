/*****************************
ATTENTION
求期望总是倒着推过来的 
求概率都是顺着推过来的
*****************************/

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

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	int n, s;

	while(cin >> n >> s)
	{
	// 	// f[1][1] = ;
	// 	for(int i = 1; i <= n; i++)
	// 		for(int j = 1; j <= s; j++)
	// 		{
	// 			if(i == 1 && j == 1)
	// 				f[i][j] = (double)n * s / (n * s - 1);
	// 			else if(i == n && j == s)
	// 				f[i][j] = (f[i - 1][j - 1] + 1) / (n * s) + (f[i - 1][j] + 1) / n + (f[i][j-1] + 1) / s;
	// 			// else if(i == 1)
	// 			// 	f[i][j] = 
	// 			else
	// 				f[i][j] = (i * j + (i > 1) * (1 + f[i-1][j]) * (n - i + 1) * j + (j > 1) * (1 + f[i][j-1]) * i * (s - j + 1) + (i > 1) * (j > 1) * (1 + f[i-1][j-1]) *(n - i + 1) *(s - j + 1)) / (n * s - i * j);
	// 			printf("f[%d][%d] = %.4lf\n", i, j, f[i][j]);
	// 		}


		memset(f, 0, sizeof(f));

	// 	printf("======================================\n");
		for(int i = n; i >= 0; i--)
			for(int j = s; j >= 0; j--)
			{
				if(i==n && j==s){}
				else{
	                double p1=(double(s-j)*i)/n/s;
	                double p2=(double(n-i)*j)/n/s;
	                double p3=(double(n-i)*(s-j))/n/s;
	                double p0=1.0-(double(i*j))/n/s;
	                f[i][j]=p1*f[i][j+1]+p2*f[i+1][j]+p3*f[i+1][j+1]+1;
	                f[i][j]/=p0;
	            }
	            // printf("f[%d][%d] = %.4lf\n", i, j, f[i][j]);
			}


		// printf("%s\n", );
		printf("%.4lf\n", f[0][0]);
	}
	return 0;
}