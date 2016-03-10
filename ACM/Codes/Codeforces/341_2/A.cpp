#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


int main()
{
	LL n;
	cin >> n;
	LL odd = 0;
	LL ans = 0;
	LL tmp;
	LL minodd = 1000000000;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;

		if(tmp % 2 == 0) ans += tmp;
		else
		{
			minodd = min(tmp, minodd);
			odd += tmp;
			if(odd % 2 == 0)
			{
				ans += odd;
				odd = 0;
			}
		}

	}

	if(odd > 0) ans = ans + odd - minodd;
	cout << ans << endl;

	return 0;
}