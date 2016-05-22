#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[1000200];

int main()
{
	int T;
	freopen("data.in", "r", stdin);
	scanf("%d", &T);
	int n, a[2];
	while(T--)
	{
		scanf("%d%d%d", &n, &a[1], &a[0]);
		memset(f, 0, sizeof(f));
		f[1] = 0;
		int pos = 0;
		for (int i = 2; i <= n; i++)
		{
			f[i] = (f[i-1] + a[i%2]) % i;
		}
		printf("%d\n", f[n]);
	}

	return 0;
}