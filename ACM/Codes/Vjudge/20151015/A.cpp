#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;


int a[30020];
int vis[30020];


int main()
{


	int n, t;
	scanf("%d%d", &n, &t);
	for(int i = 1; i < n; i++ )
		scanf("%d", &a[i]);

	bool flag = false;
	
	vis[1] = 1;

	for(int i = 1; i < n; i++)if(vis[i])
	{
		vis[i + a[i]] = 1;
		if(i + a[i] == t)
			flag = true;
	}


	printf("%s\n",flag? "YES": "NO" );





	return 0;
}