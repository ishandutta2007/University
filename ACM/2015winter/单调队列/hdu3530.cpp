#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>


using namespace std;


int q1[100020], q2[100020];
int n, m, k;
int a[100020];
int head1, head2, tail1, tail2;



int main()
{

	while(cin >> n >> m >> k)
	{

		int now = 1;
		int ans = 0;
		head1 = head2 = tail1 = tail2 = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			while(head1 < tail1 && a[q1[tail1 - 1]] < a[i]) tail1--;
			while(head2 < tail2 && a[q2[tail2 - 1]] > a[i]) tail2--;
			q1[tail1++] = i;
			q2[tail2++] = i;

			while(head1 < tail1 && head2 < tail2 && a[q1[head1]] - a[q2[head2]] > k)
			{
				if(q1[head1] < q2[head2]) now = q1[head1++] + 1;
				else now = q2[head2++] + 1;
			}
			if(head1 < tail1 && head2 < tail2 && a[q1[head1]] - a[q2[head2]] >= m && ans < i - now + 1)
				ans = i - now + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}