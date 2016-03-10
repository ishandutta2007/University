#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
int a[1020], b[1020];


int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);

	int tmpa, tmpb;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		tmpa = 0, tmpb = 0;

		for (int j = i; j <= n; j++)
		{
			tmpa |= a[j];
			tmpb |= b[j];

			if(tmpa + tmpb > ans) {
				// cout << i << " " << j << " " << tmpa + tmpb << endl;
				ans = tmpa + tmpb;
			}

		}
	}

	printf("%d\n", ans);

	return 0;
}