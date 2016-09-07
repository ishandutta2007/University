#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n, m;
	int x, y;
	int flag;
	while(cin >> n >> m)
	{
		flag = 0;
		for(int i = 0; i < m;i++)
		{
			cin >> x >> y;
			if(x > y) swap(x, y);
			if(x == 1 && y == n)
				flag = 1;
		}
		if(flag == 1)
		{
			printf("%d %d\n", 1, n * (n - 1) / 2);
		}
		else printf("1 1\n");
	}

	return 0;
}
