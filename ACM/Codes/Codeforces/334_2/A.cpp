#include <bits/stdc++.h>

using namespace std;

int m[10], w[10];
int s, u;
int x[10] = {500,1000,1500,2000,2500};

int main()
{

	for(int i = 0; i < 5; i++)
		scanf("%d", &m[i]);
	for(int i = 0; i < 5; i++)
		scanf("%d", &w[i]);

	scanf("%d%d", &s,&u);

	int ans = 0;
	for(int i = 0; i < 5; i++)
	{
		ans += max(3*x[i]/10, x[i]-x[i]*m[i]/250 - 50*w[i]);
	}

	cout << ans + 100*s - 50 * u << endl;

	return 0;
}