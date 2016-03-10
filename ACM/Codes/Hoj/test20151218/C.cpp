#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;


int a[1000200];
int n;


int main()
{
	int T;
	cin >> T;
	int n;
	for(int ka = 1; ka <= T; ka ++)
	{
		cin >> n;
		
		
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a+1, a + n + 1);
		int i, ni;
		for(i = 0; i <= n; i++)
		{
			ni = n-i;
			
			if(a[i] <= ni && a[i+1] >= ni) break;
			
		}
		
		printf("Case #%d: %d\n", ka, ni);
	}
	
	
	
	return 0;
}