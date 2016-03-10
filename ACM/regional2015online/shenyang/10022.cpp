#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;


int P;




int main()
{

	int T;
	scanf("%d", &T);
	int x;
	for(int ka = 1; ka <= T; ka++)
	{
		scanf("%d%d", &x, &P);



		printf("Case #%d: %d\n", ka, cal(x));
	}


	return 0;
}