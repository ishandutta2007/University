#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL gcd(LL M,LL N)
{
	if(M < N) swap(M, N);
	LL Rem;
	while(N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}


int main()
{

	LL a, n;

	while(scanf("%I64d%I64d", &n, &a))
	{
		if(n == 0LL && a == 0LL) return 0;
		LL ans = 1LL;
		LL tmp;
		for(int i = 0; i < n; i++)
		{
			scanf("%I64d", &tmp);
			ans = (tmp*ans)/gcd(ans, tmp);
		}

		printf("%I64d\n", ans - a);
	}



	return 0;
}
