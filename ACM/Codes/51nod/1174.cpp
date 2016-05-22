#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int st[20000][32];
int n, q;


int rmq(int l, int r)
{
	int k = log2(r-l+1);
	return max(st[l][k], st[r-(1<<k)+1][k]);
}



int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n;i++)
		scanf("%d", &st[i][0]);

	for (int j = 1; j <= 20; j++)
		for (int i = 0; i < n; i++)
			if(i+(1<<j)-1 < n)
				st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);


	scanf("%d", &q);
	int l, r;
	while(q--)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", rmq(l, r));
	}



	return 0;
}