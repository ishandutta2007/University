#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

//SG
// int a[12];
// int sg[1020][1020];


// void dfs(int rest, int mm)
// {
// 	if(sg[rest][mm] >= 0) return;
// 	sg[rest][mm] = 1;
// 	if(rest <= mm) return;
// 	for(int i = 1; i <= mm; i++)
// 	{
// 		dfs(rest - i, i*2);
// 		sg[rest][mm] = min(sg[rest-i][i*2], sg[rest][mm]);
// 	}

// 	if(sg[rest][mm] == 0) sg[rest][mm] = 1;
// 	else sg[rest][mm] = 0;
// }

// int main()
// {

// 	#ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
// 	#endif

// 	memset(sg, -1, sizeof(sg));

// 	for(int i = 2; i <= 100; i++)
// 		for(int j = 1; j < i; j++)
// 			dfs(i, j);

// 	// printf("!!!!\n");
// 	for(int i = 2; i <= 100; i++)
// 	{
// 		bool flag = false;
// 		for(int j = 1; j <= i; j++)
// 		{
// 			if(sg[i-j][j*2] == 0)
// 				flag = true;
// 		}
// 		// if(flag) printf("%d 1\n", i);
// 		if(!flag) printf("%d 2\n", i);
// 	}

// 	return 0;
// }

vector<long long>v;
int main()
{
	long long p1 = 2, p2 = 3, m = 1;
	m = m << 32;
	v.push_back(2LL);
	v.push_back(3LL);
	while(p1 + p2 <= m)
	{
		v.push_back(p1+p2);
		p2 = p1 + p2;
		p1 = p2 - p1;
	}

	long long n;
	while(scanf("%I64d", &n) != EOF)
	{
		if(n == 0LL) break;
		int pos = lower_bound(v.begin(), v.end(), n) - v.begin();
		if(pos < v.size() && v[pos] == n)
			printf("Second win\n");
		else
			printf("First win\n");
	}

	return 0;
}