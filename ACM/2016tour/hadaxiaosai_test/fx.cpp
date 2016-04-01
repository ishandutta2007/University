#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

// int f[1000];

int main()
{
	// f[0] = 0;
	// for (int i = 1; i <= 90; i++)
	// {
	// 	f[i] = f[i-1] ^ i;	
	// 	cout << f[i] << endl;
	// }
	int T,n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);

		int r = n % 4;

		if(r == 3) {
			printf("0\n");
			// cout << 0 << endl;
		}
		else if(r == 1) {
			printf("1\n");
			// cout << 1 << endl;
		}
		else if(r == 0) {
			printf("%d\n", n);
			// cout << n << endl;
		}
		else {
			printf("%d\n", n+1);
			// cout << n + 1 << endl;
		}


	}




	return 0;
}