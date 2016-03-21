#include <iostream>

using namespace std;

typedef long long LL;

LL n, m;

int f[8001][8001];

LL GCD(LL a, LL b)
//递归
{
	if(a < b) swap(a, b);
	if(b == 0) return a;
	if(a < 8001 && b < 8001 && f[a][b]) return f[a][b];
	LL r = a % b;
	if(r == 0) {
		if(a < 8001 && b < 8001)
		{
			f[a][b] = b;
			return b;
		}
		else return b;
	}
	if(a < 8001 && b < 8001)
	{
		f[a][b] = GCD(b,r);
		return f[a][b];
	}
	return GCD(b,r);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		LL ans = 0;
		

		for (int i = 1; i <= n; i++)
			ans += GCD(i|n, n&i);

		cout << ans << endl;

	}


	return 0;
}