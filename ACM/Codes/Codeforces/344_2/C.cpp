#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, m;
int a[200020];
int ans[200020];
int t[200020], r[200020];

int q[200020];
int head, tail;


int main()
{

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	head = tail = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &t[i], &r[i]);
		while(tail > head && r[i] > r[q[tail-1]]) tail--;
		q[tail++] = i;
	}

	for (int i = r[q[head]] + 1; i <= n; i++)
		ans[i] = a[i];

	sort(a + 1, a + r[q[head]] + 1);

	r[q[tail]] = 0;
	int ll = 1, rr = r[q[head]];
	for (int i = head; i < tail; i++) {
		int nowl = r[q[i+1]] + 1;
		int nowr = r[q[i]];

		if(t[q[i]] == 1) {
			for(int j = nowr; j >= nowl; j--)
				ans[j] = a[rr--];
		} else {
			for(int j = nowr; j >= nowl; j--)
				ans[j] = a[ll++];
		}

	}

	for(int i = 1; i <= n; i++)
		printf("%d%c", ans[i], i == n? '\n' : ' ');
	return 0;
}