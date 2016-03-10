#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define __maxn 1020

using namespace std;

vector<int>G[__maxn];
int de[__maxn];

int main()
{

	int n;
	while(cin >> n)
	{
		memset(de, 0, sizeof(de));
		for(int i = 0; i <= n; i++)
			G[i].clear();
		int x, y;
		for(int i = 0 ; i < n; i++)
		{
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
			de[x] ++;
			de[y] ++;
		}
		
	}


	return 0;
}