#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>


#define ll long long
#define __maxn 1000020
#define INF 0x3f3f3f3f

using namespace std;

int a[__maxn], sum[__maxn];


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	int T;
	scanf("%d", &T);
	int n;
	int minpos;
	int mmin;
	int l, r;
	for(int ka = 1; ka <= T; ka++)
	{
		memset(a, 0, sizeof(a));
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		minpos  = 0;
		mmin = 0;
		int ans = -0x7f7f7f7f;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
			if(sum[i] - mmin > ans)
			{
				l = minpos + 1;
				r = i;
				ans = sum[i] - mmin;
			}
			if(sum[i] < mmin)
			{
				mmin = sum[i];
				minpos = i;
			}
			// if(sum[i] - mmin > ans)
			// {
			// 	l = minpos + 1;
			// 	r = i;
			// 	ans = sum[i] - mmin;
			// }


		}

		printf("Case %d:\n", ka);
		printf("%d %d %d\n", ans, l, r);
		if(ka != T) printf("\n");
	}


	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}