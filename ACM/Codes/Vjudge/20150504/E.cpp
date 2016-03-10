#include<bits/stdc++.h>
#define LL long long


using namespace std;


LL countFact(ll n, ll p)
{
	ll k=0;
	while (n>=p)
	{
		k+=n/p;
		n/=p;
	}
	return k;
}

int main(){


    cout << countFact

    return 0;
}
