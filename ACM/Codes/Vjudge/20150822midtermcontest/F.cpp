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

double a[20][1020];
int n, m;
bool vis[20];

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	int T;
	scanf("%d", &T);
	for(int ka = 1; ka <= T; ka++)
	{
		scanf("%d%d", &n, &m);


		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				scanf("%lf", &a[i][j]);
			}


		dfs(1, );



	}


	#ifdef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}