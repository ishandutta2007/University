#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define __maxn 500
#define EPS 1e-10

using namespace std;

int v, p;
int a[__maxn], dp[__maxn][__maxn];



int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	scanf("%d%d", &v, &p);
	for(int i = 1; i <= v; i++)
		scanf("%d", &a[i]);


	
	return 0;
}