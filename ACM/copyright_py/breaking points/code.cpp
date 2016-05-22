#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int a[50020];

long long cal(int x)
{
	if (x <= 0) return 0LL;
	// cout << x << " : ";
	long long c = (long long)min(x, k);
	// cout << c*x - (c-1)*c/2 << endl;
	return c*x - (c-1)*c/2;
}



int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &k, &m);
		// cout << n << " " << k << " " << m << endl;
		for (int i = 1; i <= m; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + m + 1);
		a[0] = 0;
		a[m + 1] = n + 1;
		long long ans = cal(n);
		for (int i = 0; i <= m; i++)
			ans -= cal(a[i+1] - a[i] - 1);
		cout << ans << endl;
	}
}
