#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 100020;
bool isprime[maxn];
LL prime[maxn];

LL maxcnt, ans;

LL n;


int doprime(LL N)
//prime[] 储存质数。1-based index;
{
	int nprime = 0;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for(LL i = 2; i <= N; i++)
	{
		if(isprime[i])
		{
			prime[++nprime] = i;
			for(LL j = i*i; j <= N; j+=i)
				isprime[j] = false;
		}
	}
	return nprime;
}


void dfs(int pos, LL now, LL tmpcnt, LL lastcnt)
{
	if(tmpcnt > maxcnt || (tmpcnt == maxcnt && now < ans))
	{
		maxcnt = tmpcnt;
		ans = now;
	}
	int i = 1;
	while(now * pow(prime[pos], i) < n && i <= lastcnt)
	{
		dfs(pos+1, now * pow(prime[pos], i), tmpcnt*(i+1), i);
		i++;
	}
}


int main()
{
	cin >> n;
	doprime(100000);
	dfs(1, 1LL, 1LL, n);
	cout << ans << endl;

	return 0;
}