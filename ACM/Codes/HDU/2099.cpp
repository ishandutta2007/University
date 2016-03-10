#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
//GCD
LL GCD(LL a, LL b)
//递归
{
	if(a < b) swap(a, b);
	LL r = a % b;
	if(r == 0LL) return b;
	return GCD(b, r);
}

LL gcd(LL M,LL N)
//非递归
{
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

	int a, b;
	bool first = true;
	while(scanf("%d%d", &a, &b) != EOF && (a+b))
	{

		first = true;
		a*=100;
		for(int i = 0; i < 100; i++)
		{
			if((a+i) % b == 0)
			// cout << a+i << " " << b << endl;
			// cout << GCD((LL)a+i,(LL)b) << endl;
			// if(gcd((LL)a+i,(LL)b) == (LL)b)
			{
				if(first)
				{
					first = false;
					printf("%02d", i);
				}
				else
					printf(" %02d", i);
			}
		}
		printf("\n");
	}



	return 0;
}

