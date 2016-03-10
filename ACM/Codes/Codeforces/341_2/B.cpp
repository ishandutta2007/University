#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


int mp[1020][1020];
int lx[3000], rx[3000];
int n;
LL ans;

int main()
{
	cin >> n;
	int x, y;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		mp[x][y] = 1;
	}
	ans = 0;

	for(int i = 1; i <= 1000; i++)
		for(int j = 1; j <= 1000; j++)if(mp[i][j])
		{
			ans += lx[i-j+1000];
			ans += rx[i+j];
			lx[i-j+1000]++;
			rx[i+j]++;
		}


	cout << ans << endl;

	return 0;
}