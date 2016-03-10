#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;

int n;
int a[10020];




int main()
{

	scanf("%d", &n);


	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	if(n < 4)
	{
		printf("-1\n");
		return 0;
	}

	sort(a, a + n);

	int ans = -1;


	for(int i = n-1; i >= 3; i--)if(a[i] < a[i-1]+a[i-2]+a[i-3] && (a[i] != a[i-3]))
	{
		ans = a[i] + a[i-1] + a[i-2]+a[i-3];
		break;
	}


	printf("%d\n", ans);

	return 0;
}