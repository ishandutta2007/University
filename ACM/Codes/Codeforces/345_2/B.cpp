#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int n, a[1020];


int main()
{

	cin >> n;
	int tmp;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[tmp] ++;
	}

	int ans = 0;

	for (int t = 1; t <= 1000; t++) {
		int tcnt = 0;
		for (int i = 1; i <= 1000; i++) if(a[i]) {
			tcnt ++;
			a[i] --;
		}

		if(tcnt >= 2)
			ans += tcnt - 1;
	}

	cout << ans << endl;


	return 0;
}