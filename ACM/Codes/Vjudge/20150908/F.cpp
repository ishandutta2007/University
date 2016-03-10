#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 2200

using namespace std;

int main()
{
	printf("2000\n");
	for (int i=1;i<=1000;i++)
	{
		printf("%d 1 %d 2\n",i, i);
	}
	for (int i=1000;i>=1;i--)
	{
		printf("%d 1 %d 2\n",i, i);
	}
	return 0;
}