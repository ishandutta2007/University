#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

ll p, a;

bool isprime(int x)
{
	if(x <= 2) return true;
	ll l = sqrt(x);
	for(ll i = 2; i <= l; i++)
		if(x % i == 0) return false;
	return true;
}


ll Pow(ll a, ll b, ll m)
{
	if(b == 0) return 1;
	if(b == 1) return a%m;
	ll tmp = Pow(a, b>>1, m)%m;
	if(b & 1) return ((tmp*tmp)%m)*a%m;
	else return (tmp*tmp)%m;
}

int main()
{

	while(cin >> p >> a)
	{
		if(p + a == 0) break;
		if(isprime(p) || Pow(a, p, p) != a)
		{
			printf("no\n");
		}
		else printf("yes\n");

	}


	return 0;
}