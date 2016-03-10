#include <bits/stdc++.h>

using namespace std;

int t[1020];


int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	
	int x, y;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d,", &x, &y);
		t[x] = max(t[x], y);
	}
	
	int ans = 0;
	
	for(int i = s; i >= 0; i--)
	{
		if(t[i] > ans) ans = t[i];
		ans ++;
	}
	
	printf("%d\n", ans - 1);
	
	return 0;
}


//10min
