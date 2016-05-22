#include <bits/stdc++.h>
using namespace std;


int a[1020];


int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			printf("%d ", a[l++]);
		else
			printf("%d ", a[r--]);
	}

	printf("\n");

	return 0;
}