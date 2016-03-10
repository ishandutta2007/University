#include <cstdio>
#include <iostream>



using namespace std;


typedef long long LL;



int main()
{
	freopen("out.txt", "w", stdout);
	int n = 1000;
	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		ans *= i;
		while(ans %10 == 0) ans/=10;

		ans %= 100;

		printf("%2d\n",ans);
	}



	return 0;
}