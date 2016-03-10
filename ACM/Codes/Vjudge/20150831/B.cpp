#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;


int a[12];
int sg[1020];

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif

	for(int i = 0; i <= 10;i++)
	{
		a[i] = (1 << i);
	}
	for(int i = 1; i <= 1000; i++)
	{
		sg[i] = 1;
		for(int j = 0; j < 10; j++)if(i - a[j] >= 0)
			sg[i] = min(sg[i], sg[i-a[j]]);
		if(sg[i] == 0) sg[i] = 1;
		else sg[i] = 0;
	}

	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%s\n", sg[n]? "Kiki" : "Cici");
	}


	return 0;
}