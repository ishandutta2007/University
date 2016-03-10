#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;




int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n, m;


	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n + m == 0) break;

		if(n % 2 && m % 2) printf("What a pity!\n");
		else printf("Wonderful!\n");
	}


	return 0;
}