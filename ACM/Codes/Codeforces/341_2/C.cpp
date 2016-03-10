#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


int cnt[100020],all[100020];
double f[100020];
int n, p;

int calcnt(int x)
{
	return x / p;
}


int main()
{
	cin >> n >> p;
	int l, r;

	for(int i = 0; i < n; i++)
	{
		cin >> l >> r;

		all[i] = r - l + 1;
		cnt[i] = calcnt(r) - calcnt(l-1);
		f[i] = cnt[i]*1.0 / all[i];
	}

	double ans = 0.0;


	for(int i = 0; i < n; i++)
	{
		ans += 2000 * (1 - (1-f[i])*(1-f[(i+1)%n]));
	}

	printf("%.6f\n", ans);

	return 0;
}