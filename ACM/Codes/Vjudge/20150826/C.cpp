#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define __maxn 500020
#define EPS 1e-10
#define ll long long

using namespace std;


deque<int>deq;
ll sum[__maxn], dp[__maxn];
int n, m;


double calc(int i, int j)
{
	if(sum[i] == sum[j]) return -1.0;
	return (double)(dp[j]+sum[j]*sum[j]-dp[i]-sum[i]*sum[i])/(sum[j]-sum[i]);
}


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	while(scanf("%d%d",&n,&m) != EOF)
	{
		memset(sum, 0, sizeof(sum));
		memset(dp, 0, sizeof(dp));
		deq.clear();
		for(int i = 1; i <= n; i++)
		{
			scanf("%I64d", &sum[i]);
			sum[i] += sum[i-1];
		}
		deq.push_back(0);
		for(int i = 1; i <= n; i++)
		{
			while(deq.size() >= 2 && calc(deq[0], deq[1]) < (double)2*sum[i])
				deq.pop_front();
			int pos;
			if(!deq.empty()) pos = deq.front();
			else pos = 0;
			dp[i] = dp[pos] + (sum[i] - sum[pos])*(sum[i] - sum[pos]) + m;
			while(deq.size() >= 2 && calc(deq[deq.size() - 1],i) < calc(deq[deq.size() - 2],deq[deq.size() - 1])) deq.pop_back();
			deq.push_back(i);
		}
		printf("%I64d\n", dp[n]);

	}


	return 0;
}