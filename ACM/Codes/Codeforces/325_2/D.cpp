#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;


char mp[3][120];
int a[3][120];
int k, n;

bool solve()
{
	bool ret = false;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)if(a[j][i] == 1)
		{
			if(mp[j][i+1] == '.' && mp[j][i+2] == '.' && mp[j][i+3] == '.')
			{
				if(i + 3 >= n-1) ret = true;
				a[j][i+3] = 1;
				if(j-1 >= 0 && mp[j-1][i+3] == '.')
					a[j-1][i+3] = 1;
				if(j+1 < 3 && mp[j+1][i+3] == '.')
					a[j+1][i+3] = 1;
			}
		}
	}
	return ret;

}


int main()
{
	int T;
	scanf("%d", &T);
	int sy;
	while(T--)
	{
		memset(a, 0, sizeof(a));
		scanf("%d%d", &n, &k);
		for(int i = 0; i < 3; i++)
			scanf("%s", mp[i]);
		for(int i = n; i < 120; i++)
			for(int j = 0; j < 3; j++)
				mp[j][i] = '.';
		for(int i = 0; i < 3; i++)
			if(mp[i][0] == 's')
				sy = i;
		if(mp[sy][1] != '.')
		{
			printf("NO\n");
			continue;
		}
		else
		{
			a[sy][1] = 1;
			if(sy - 1 >= 0 && mp[sy-1][1] == '.')
				a[sy-1][1] = 1;
			if(sy + 1 < 3 && mp[sy+1][1] == '.')
				a[sy+1][1] = 1;
		}
		if(solve()) printf("YES\n");
		else printf("NO\n");

	}



	return 0;
}