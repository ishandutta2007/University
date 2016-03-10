#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL tmp = LONG_LONG_MAX;
	
	LL l, r;
	
	cin >> l >> r;
	
	int ans = 0;
	for(int i = 2; i < 64; i++)
	{
		tmp = (1LL<<i) - 1;
		
		// cout << tmp << endl;
		
		for(int j = 0; j < i - 1; j++)
		{
			LL now = tmp ^ (1LL<<j);
			if(now >= l && now <= r)
			{
				ans ++;
				
			// cout << "   " << now << endl;
			}
		}			
	}
	
	cout << ans << endl;
	
	return 0;
}