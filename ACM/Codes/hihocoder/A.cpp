#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define __maxn 1000

using namespace std;

int n;
char s[60][10], ch[10];
double a[60];


int ck(int x, char s[10], double b)
{
	if(strcmp("<=", s) == 0 && x <= b)
		return 1;
	if(strcmp("<",s) == 0 && x < b)
		return 1;
	if(strcmp("=", s) == 0 && x == b)
		return 1;
	if(strcmp(">=", s) == 0 && x >= b)
		return 1;
	if(strcmp(">", s) == 0 && x > b)
		return 1;
	return 0;
}

int calans(int x)
{
	int tmp = 0;
	for(int i = 1; i <= n; i++)
	{
		tmp += ck(x, s[i], a[i]);
	}

	return tmp;
}


int main()
{
	scanf("%d", &n);

	for(int i = 1; i <= n;i++)
	{
		scanf("%s %s %lf", ch, s[i], &a[i]);
		a[i] *= 2;
	}


	int ans = 0;

	for(int i = -10; i <= 2222; i++)
	{
		ans = max(ans, calans(i));
	}

	printf("%d\n", ans);

	return 0;
}