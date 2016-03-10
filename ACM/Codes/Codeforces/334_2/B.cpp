#include <bits/stdc++.h>

using namespace std;

int a[100020];
int n,k,x;

int main()
{
	scanf("%d%d",&n,&k);

	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	x = 2*k-n;

	int ans = 0;

	if(x > 0) ans = a[n];

	for(int i = 1; i <= n-x; i++)
		ans = max(ans, a[i] + a[n-x-i+1]);

	cout << ans << endl;
	return 0;
}