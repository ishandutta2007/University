#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;


typedef struct Friend
{
	LL mon, fri;
}F;

F a[100020];
LL sum[100020];


deque<F>deq;


int n, d;


bool cmp(F a, F b)
{
	return a.mon < b.mon;
}


int main()
{
	scanf("%d%d", &n, &d);

	memset(a, 0, sizeof(a));

	for(int i = 1; i <= n; i++)
	{
		scanf("%I64d%I64d", &a[i].mon, &a[i].fri);
	}

	sort(a + 1, a+n + 1, cmp);


	deq.clear();
	a[0].mon = -1000000009;
	a[0].fri = -1000000009;
	deq.push_back(a[0]);
	int pos = 0;
	LL ans = 0;
	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i -1] + a[i].fri;
		while(!deq.empty() && deq.front().mon + d <= a[i].mon)
		{
			deq.pop_front();
			pos++;
		}
		deq.push_back(a[i]);
		// printf("%d %d\n", pos, i);
		ans = max(ans, sum[i] - sum[pos-1]);
	}

	printf("%I64d\n", ans);

	return 0;
}
