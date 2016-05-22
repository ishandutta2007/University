#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>


using namespace std;

int a[100020], b[100020];
int cnt[100020];




int main()
{
	int T, n;
	int tmp;
	int ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &tmp);
			a[i] = b[i] = tmp;
		}
		sort(b+1, b+n+1);
		for (int i = 1; i <= n; i++)
			a[i] = lower_bound(b+1, b+n+1, a[i]) - b;

		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
		{
			int now = a[i];
			if(cnt[now-1] > 0)
				cnt[now] = cnt[now-1] + 1;
			else
				cnt[now] = 1;
			ans = max(cnt[now], ans);
		}
		printf("%d\n", n - ans);

	}


	return 0;
}