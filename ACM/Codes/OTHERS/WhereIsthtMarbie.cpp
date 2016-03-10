#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int a[100020];


int main(){
	int t = 0;
	int n,q;
	
	while(scanf("%d%d",&n,&q) == 2)
	{
		if(n == 0 && q == 0)
			break;
		memset(a,0,sizeof(a));
		printf("CASE# %d:\n",++t);
		
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		
		sort(a, a+n);
		
		while(q--)
		{
			int x;
			scanf("%d",&x);
			int p = lower_bound(a, a+n, x) - a;
			if(a[p] == x)
				printf("%d found at %d\n", x, p + 1);
			else
				printf("%d not found\n",x);
		}
		
		
	}


	return 0;
}

