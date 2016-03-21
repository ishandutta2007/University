// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long LL;

LL t, n, k;
const LL mod = 1e9+7;

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> k;


		if(k*(k+1)/2 > n) cout << -1 << endl;
		else
		{
			LL rest = n - k*(k+1)/2;
			LL avg = rest / k;
			rest = rest - avg*k;

			LL ans = 1;

			for (LL i = k; i >= 1; i--, rest--)
			{
				if(rest > 0)
					ans = ans * (i + avg + 1) % mod;
				else
					ans = ans * (i + avg) % mod;

			}

			cout << ans << endl;

		}

	}
	return 0;
}