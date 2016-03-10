#include <cstdio>
#include <iostream>


using namespace std;


int a[100020], b[100020];


int main()
{

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);


	b[n] = 0;


	for(int i = n-1; i >= 1; i--)
	{
		b[i] = max(b[i+1], a[i+1]);
	}

	int ans;
	for(int i = 1; i <= n; i++)
	{
		ans = b[i] - a[i] + 1;
		if(ans < 0)
			ans = 0;

		printf("%d%c", ans, i == n? '\n':' ');
	}


}
