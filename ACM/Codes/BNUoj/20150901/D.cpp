#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

#define ll unsigned long long

using namespace std;


ll A, B, C;
ll smul(ll A, ll B)
{
	ll tmp=0;
	while (B)
	{
		if (B & 1) tmp+=A, tmp%=C;
		A+=A, A%=C;
		B>>=1;
	}
	return tmp % C;
}

ll qpow(ll A, ll B)
{
	if(B == 0) return 1LL;
	if(B == 1) return A%C;
	ll tmp = qpow(A, B>>1)%C;
	if(B & 1) return smul(smul(tmp,tmp),A)%C;
	else return smul(tmp,tmp)%C;
}


int main()
{

	while(cin >> A >> B >> C)
	{
		A %= C;

		cout << qpow(A, B) <<endl;
	}


	return 0;
}