#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a, b;


int main()
{
	cin >> a >> b;

	int ans = 0;


	while((a >= 1 && b >= 2) || (a >= 2 && b >= 1))
	{
		ans ++;
		if(a == 1) {
			a += 1;
			b -= 2;
		}
		else if(b == 1) {
			a -= 2;
			b += 1;
		}
		else if(a<b) a++, b-=2;
		else a-=2, b++;
	}

	cout << ans << endl;


	return 0;
}