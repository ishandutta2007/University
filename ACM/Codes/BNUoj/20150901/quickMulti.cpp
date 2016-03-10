#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

#define ll long long


ll A,B,C;

ll Mul(ll a, ll b)
{
	ll tmp=0;
	while (b)
	{
		if (b & 1) tmp+=a, tmp%=C;
		a+=a, a%=C;
		b>>=1;
	}
	return tmp % C;
}

ll Pow(ll a, ll b)
{
	ll tmp=1;
	while (b)
	{
		if (b & 1) tmp=Mul(tmp,a), tmp%=C;
		a=Mul(a,a), a%=C;
		b>>=1;
	}
	return tmp % C;
}


int main()
{


	return 0;
}