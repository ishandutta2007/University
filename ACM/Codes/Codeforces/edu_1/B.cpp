#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;

char ss[10020];
char sd[10020];
int n;
int L[400], R[400], k[400];

int getp(int p)
{
	for(int i = 0; i < n; i++)
	{
		if(p >= L[i] && p < R[i])
		{
			p = (p - L[i] + k[i]) % (R[i] - L[i]) + L[i];
		}
	}
	return p;
}

int main()
{

	scanf("%s", ss);
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &L[i], &R[i], &k[i]);
		L[i] --;
	}

	strcpy(sd, ss);

	for(int i = 0, len = strlen(ss); i < len; i++)
	{
		sd[getp(i)] = ss[i];
	}

	printf("%s\n", sd);
	return 0;
}