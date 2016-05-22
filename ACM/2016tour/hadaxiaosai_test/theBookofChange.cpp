#include <cstdio>
#include <cstring>

char str[10];

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	int n;

	while(T--)
	{
		int ans = 0;
		scanf("%d", &n);
		getchar();
		while(n--)
		{
			ans *= 2;
			gets(str);
			if(str[1] == ' ')
				ans += 1;
		}

		printf("%d\n", ans);
	}


	return 0;
}