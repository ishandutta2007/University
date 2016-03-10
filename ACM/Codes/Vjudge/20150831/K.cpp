#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;


bool _check(int n, int m)
{
	if(n > m) swap(n, m);
	int k = ceil((double)(2*n)/(1+sqrt(5)));
	if(n == (int)(k*(1+sqrt(5))/2) && n + k == m)
	{
		return false;
	}
	return true;
}


int n, m;
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	while(scanf("%d%d",&n,&m) == 2)
	{
		if(n+m == 0) break;
		if(_check(n, m) == false)
		{
			printf("0\n");
			continue;
		}
		printf("1\n");
		int k = m - n;
		int a = k*(1+sqrt(5))/2;
		int b = a + k;
		if(a < n && b < m)
		{
			printf("%d %d\n", a, b);
		}
		k = ceil((double)(2*n)/(1+sqrt(5)));
		a = n;
		b = n+k;
		if(b < m && _check(a, b) == false)
		{
			printf("%d %d\n", a, b);
			continue;
		}
		k = ceil((double)(2*n)/(3+sqrt(5)));
		b = n;
		a = n - k;
		if(a >= 0 && _check(a, b) == false)
		{
			printf("%d %d\n", a, b);
			continue;
		}
		k = ceil((double)(2*m)/(3+sqrt(5)));
		b = m;
		a = m - k;
		if(a >= 0 && a < n && _check(a, b) == false)
		{
			printf("%d %d\n", a, b);
			continue;
		}
	}
	return 0;
}