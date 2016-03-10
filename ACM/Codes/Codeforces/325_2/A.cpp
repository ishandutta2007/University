#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;


int a[120];


int main()
{

	int n;
	scanf("%d", &n);


	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);


	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1) ans++;
		else if(a[i-1] == 1 && a[i + 1] == 1)
		{
			ans++;
		}
	}

	printf("%d\n", ans);


	return 0;
}