#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


int n, a, b, l;

int L[120], R[120];
int delta[120];


int main()
{

	int T;
	scanf("%d", &T);


	for(int ka = 1; ka <= T; ka++)
	{
		scanf("%d%d%d%d",&n,&a,&b,&l);

		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&L[i], &R[i]);
			delta[i] = R[i] - L[i];
		}


		int pos = 0;
		int ans = 0;
		int now = 0;
		for(int i = 0; i < n; i++)
		{
			now += (L[i] - pos)*b;
			now -= delta[i] * a;
			ans = min(ans, now);
			pos = R[i];
		}

		printf("Case #%d: %d\n",ka,  abs(min(ans, 0)));

	}

	return 0;
}