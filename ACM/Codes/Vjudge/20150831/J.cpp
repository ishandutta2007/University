#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	while(scanf("%d%d",&n,&m) == 2)
	{

		if(n > m) swap(n, m);
		int k = ceil((double)(2*n)/(1+sqrt(5)));
		if(n == (int)(k*(1+sqrt(5))/2) && n + k == m) printf("0\n");
		else printf("1\n");
	}
	return 0;
}