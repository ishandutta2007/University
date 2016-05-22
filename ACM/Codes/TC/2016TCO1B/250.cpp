#include <bits/stdc++.h>
using namespace std;

const int maxn = 100020;
bool isprime[maxn];
int prime[maxn];
int doprime(int N)
//prime[] 储存质数。1-based index;
{
	int nprime = 0;
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for(int i = 2; i <= N; i++)
	{
		if(isprime[i])
		{
			prime[++nprime] = i;
			for(int j = i*i; j <= N; j+=i)
				isprime[j] = false;
		}
	}
	return nprime;
}

int vis[1000];


bool is_prime(int x)
{
	if(x == 1) return false;
	int k = sqrt(x);
	for (int i = 2; i <= k; i++)
		if(x%i == 0) return false;
	return true;
}


class ExploringNumbers
{
public:

	int cal(int x)
	{
		int ret = 0;
		while(x)
		{
			int dig = x%10;
			ret += dig*dig;
			x /= 10;
		}
		return ret;
	}

	int numberOfSteps(int n)
	{
		// if(n == 1) return -1;
		if(is_prime(n)) return 1;
		memset(vis, 0, sizeof(vis));
		doprime(1000);
		int now = cal(n);
		int ans = 2;
		cout << ans << endl;
		cout << n << endl;
		while(ans <= n && !vis[now])
		{
			if(isprime[now]) return ans;
			vis[now] = 1;
			now = cal(now);
			ans++;
		}
		return -1;
	}

};