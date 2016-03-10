#include <cstdio>
#include <cstring>


using namespace std;

int n;
int a[30];
int b[30];
int main()
{

	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[a[i]] = i;
		}
		

		int ans = 1;
		int now = n;
		while(b[now-1] < b[now] && now - 1 > 0)
		{
			ans ++;
			now--;
		}
		printf("%d\n", n - ans);
	}

	return 0;
}