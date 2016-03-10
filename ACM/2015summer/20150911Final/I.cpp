#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <map>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f



using namespace std;

typedef long long LL;




int main()
{




	LL n;
	while(scanf("%lld", &n) != EOF)
	{
		
		if(n % 2 == 1) printf("2\n");
		else if(n % 3 == 0 && n / 3 - 1 > 0) printf("3\n");
		else if((n-2)%4 == 0 && (n-2) / 4 - 1 > 0) printf("4\n");

		else if(n%5 == 0 && n/5 - 2 > 0) printf("5\n");

		else if((n - 5)%10 == 0 && (n-5)/10 - 4 > 0) printf("10\n");

		else if((n - 6)%12 == 0 && (n-6)/12 - 5 > 0) printf("12\n");

		else 
		{
			printf("-1\n");
		}
	}


	return 0;
}