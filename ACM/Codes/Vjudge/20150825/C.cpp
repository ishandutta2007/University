#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

#define __maxn 1020
#define EPS 1e-10

using namespace std;

int n, k1,k2,k3, a, b, c, sum;
double f[__maxn], p[__maxn];
double A[__maxn], B[__maxn];



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif



	int T;
	scanf("%d", &T);
	while(T--)
	{
		cin >> n >> k1 >> k2 >> k3 >> a >> b >> c ;
		memset(f, 0, sizeof(f));
		memset(p, 0, sizeof(p));
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));

		sum = k1 + k2 + k3;
		double pp = (double)1 / k1 / k2 / k3;
		for(int i1 = 1; i1 <= k1; i1++)
			for(int i2 = 1; i2 <= k2; i2++)
				for(int i3 = 1; i3 <= k3; i3++)
				{
					if(!(i1 == a && i2 == b && i3 == c))
						p[i1 + i2 + i3] += pp;
				}
			
		for(int i = n; i >= 0; i--)
		{
			A[i] = pp;
			B[i] = (double)1;
			for(int j = sum; j >= 0; j--)
			{
				A[i] += A[i + j] * p[j];
				B[i] += B[i + j] * p[j];
			}
		}
		printf("%.9lf\n", B[0] / (1 - A[0]));

	}





	return 0;
}