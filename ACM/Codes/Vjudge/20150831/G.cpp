#include <cstdio>



int main()
{
	int t ;
	scanf("%d",&t) ;
	while(t--)
	{
		int n ,ans = 0;
		scanf("%d",&n);
		for(int i = 0 ; i < n ; ++i)
		{
			int temp ;
			scanf("%d",&temp);
			if(temp%4==1||temp%4==2)
				ans ^= temp ;
			else if(temp%4==3)
				ans ^= temp+1;
			else if(temp%4==0)
				ans ^= temp-1 ;
		}
		if(ans)
			puts("Alice") ;
		else
			puts("Bob") ;
	}
	return 0 ;
}