#include <bits/stdc++.h>

using namespace std;


int a[1000200];
int f[1000200];

int main()
{
	int n;
	scanf("%d", &n);
	
	int x, y;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x] = y;
	}
	
	int ans = 0;
	
	
	for(int i = 0; i <= 1000001; i++)
	{
		int tmp = i - a[i] - 1;
		if(tmp < 0) f[i] = f[i] = 0;
		else f[i] = f[tmp];
		if(a[i] > 0) f[i] ++;
		ans = max(f[i], ans);
	}
	
	printf("%d\n", n - ans);
	
	return 0;
}

//11:02