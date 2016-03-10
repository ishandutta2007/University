#include <cstdio>
#include <iostream>
#include <cstring>


using namespace std;


void prow(int a, int n)
{

	if(a < 26) a = 'a' + a;
	else a = 'A' + a - 26;
	for(int i = 0; i < n; i++)
	{
		printf("%c", a);
	}
	printf("\n");
}

void pline(int a)
{
	if(a < 26) a = 'a' + a;
	else a = 'A' + a - 26;
	printf("%c", a);
}

int main()
{
	int n;


	scanf("%d", &n);


	printf("2 %d %d\n", n, n);
	for(int i = 0; i < n; i++)
	{
		prow(i, n);
	}

	printf("\n");


	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			pline(j);
		printf("\n");
	}


	return 0;
}