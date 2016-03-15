#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[30];

long long calans(int mask)
{
	long long tmp = 1;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int bit = (mask>>i) & 1;
		if (bit) {
			tmp *= a[i];
			cnt += bit;
		}
	}
	if(tmp > n) return 0;
	long long t = n / tmp;
	long long high = t * tmp;
	tmp = (tmp + high)*t/2;
	if(cnt % 2 == 0) return tmp * -1;
	else return tmp;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		cin >> n >> m;


		for (int i = 0; i < m; i++)
			cin >> a[i];

		long long ans = 0;

		for (int mask = 1, len = (1 << m); mask < len; mask++)
		{
			ans += calans(mask);
		}
		cout << ans << endl;
	}

	return 0;
}
