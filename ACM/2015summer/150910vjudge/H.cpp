#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


double ans;

int main()
{
	int T;
	scanf("%d", &T);
	for(int ka = 1; ka <= T; ka++)
	{
		int x;
		char str[5];
		scanf("%d[%s]", &x, str);
		int n;
		if(str[0] == 'B') n = 1;
		else if(str[0] == 'K') n = 2;
		else if(str[0] == 'M') n = 3;
		else if(str[0] == 'G') n = 4;
		else if(str[0] == 'T') n = 5;
		else if(str[0] == 'P') n = 6;
		else if(str[0] == 'E') n = 7;
		else if(str[0] == 'Z') n = 8;
		else if(str[0] == 'Y') n = 9;

		ans = 1.0;

		for(int i = 1; i < n; i++)
			ans *= (1000.0) / 1024.0;

		printf("Case #%d: %.2lf%%\n", ka, (1.0-ans)*100);
	}
	return 0;
}