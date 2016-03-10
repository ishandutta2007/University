#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;


typedef long long LL;

LL A[5000200];



int main()
{

	int T;
	scanf("%d", &T);

	LL a, b;
	int n;


	for(int ka = 1; ka <= T; ka++)
	{
		scanf("%d%I64d%I64d", &n, &a, &b);


		for(int i = 0; i < n; i++)
			scanf("%I64d", &A[i]);


		sort(A, A + n);
		LL ans = -9223372036854775800;
		
		int sub = 0;

		for(int i = 0; i < n; i++)if(sub != i)
		{
			ans = max(ans, a*A[i]*A[i] + b * A[sub]);
		}

		sub = 1;

		for(int i = 0; i < n; i++)if(sub != i)
		{
			ans = max(ans, a*A[i]*A[i] + b * A[sub]);
		}

		sub = n-1;
		for(int i = 0; i < n; i++)if(sub != i)
		{
			ans = max(ans, a*A[i]*A[i] + b * A[sub]);
		}

		sub = n-2;
		for(int i = 0; i < n; i++)if(sub != i)
		{
			ans = max(ans, a*A[i]*A[i] + b * A[sub]);
		}


		printf("Case #%d: %I64d\n", ka, ans);
	}
	return 0;
}