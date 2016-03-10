#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int a[1000020];
int n, k;
int q[1000020];
int head, tail;


void push(int i)
{
	while(head < tail && a[q[tail-1]] > a[i])
	{
		tail--;
	}
	q[tail++] = i;
	// deq.push_back(make_pair(a[i]*md, i));
}

int getmin(int l, int r)
{
	while(head < tail && q[head] < l)
		head++;

	push(r);
	return a[q[head]];
}

void solve(int md)
{

	for(int i = 1; i <= n; i++)
		a[i] *= md;


	head = tail = 0;
	for(int i = 1; i < k; i++)
	{
		push(i);
	}
	for(int r = k; r <= n; r++)
	{
		printf("%d%c", md * getmin(r-k+1, r), r == n? '\n':' ');
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}



	solve(1);
	solve(-1);
	


	return 0;
}