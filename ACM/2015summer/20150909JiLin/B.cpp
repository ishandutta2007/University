#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char src[302000];
char s1[302000];
int Next[302000];
int cnt[302000];

int l1, l2;
long long ans;

void get_Next(char* substring)
{
	int substring_len = strlen(substring);
	memset(Next, 0, sizeof(Next));
	memset(cnt, 0, sizeof(cnt));
	Next[0] = -1;
	int j = -1;
	for(int i = 1; i < substring_len; i++)
	{
		while(j > -1 && substring[i] != substring[j + 1])
			j = Next[j];
		if(substring[j+1] == substring[i])
			j = j + 1;
		Next[i] = j;
		if(j >= 0) cnt[i] = cnt[j]+1;
		if(i > l2 && j >= 0)
		{
			ans += cnt[i];
			// int p = i;
			// while(Next[p] > -1)
			// {
			// 	ans++;
			// 	p = Next[p];
			// }
		}
	}
}




int main()
{
	while(scanf("%s%s", s1, src) != EOF)
	{

		l1 = strlen(s1), l2 = strlen(src);


		src[l2] = '$';

		for(int i = 0; i <= l1; i++)
			src[i + l2 + 1] = s1[i];

		ans = 0LL;
		// printf("%s\n", src);
		get_Next(src);
		// int len = l1 + l2 + 1;
		// for(int i = 0; i < len; i++)
		// 	printf("%d", Next[i]);
		// printf("\n");
		// long long ans = 0;

		// for(int i = l2; i < len; i++)
		// 	if(Next[i] >= 0)
		// 		ans++;
		printf("%lld\n", ans);
	}
	return 0;
}

