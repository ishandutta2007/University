#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define __maxn 200020
#define EPS 1e-10

using namespace std;


int a[__maxn], s[__maxn], t[__maxn], pre[__maxn];
int n, k;
deque<int>deq;


void __deqinsert(int i)
{
	while(!deq.empty() && s[deq.back()] > s[i])
		deq.pop_back();
	deq.push_back(i);
}

int main(int argc, char const *argv[])
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
		memset(pre,0, sizeof(pre));
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i + n] = a[i];
		}
		for(int i = 1; i <= 2*n; i++)
		{
			s[i] = s[i-1] + a[i];
		}
		deq.clear();
		deq.push_back(0);
		for(int i = 1; i <= 2*n; i++)
		{
			if(deq.front() < i - k)
				deq.pop_front();
			t[i] = s[i] - s[deq.front()];
			// printf("front = %d %d\n", deq.front(), i);
			pre[i] = deq.front() + 1;
			__deqinsert(i);
		}
		int ans = -100000020, pos;
		for(int i = 1; i <= 2*n; i++)
		{
			// printf("%d %d\n", i, t[i]);
			if(t[i] > ans)
			{
				ans = t[i];
				pos = i;	
			}
			
		}
		printf("%d %d %d\n", ans, (pre[pos] - 1) % n + 1, (pos - 1) % n + 1);
		// printf("=========================\n");
	}



	return 0;
}