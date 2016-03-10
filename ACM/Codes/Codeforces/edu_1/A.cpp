#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
typedef long long LL;
LL sp2[40], p2[40];

int calp(int n)
{
	int res = 0;
	while(n)
	{
		n /= 2;
		res++;
	}
	return res;
}


int main()
{

	for(int i = 0; i < 32; i++)
		p2[i] = 1 << i;
	sp2[0] = 1;
	for(int i = 1; i < 32; i++)
	{
		sp2[i] = sp2[i-1] + p2[i];
		// cout << i << " " << sp2[i] <<endl;
	}


	int T;
	scanf("%d", &T);

	int n;
	LL ans;
	while(T--)
	{
		scanf("%d", &n);
		int p = calp(n);
		ans = (LL)n*(n+1)/2;
		ans -= sp2[p-1]*2;

		cout << ans << endl;

	}
	return 0;
}