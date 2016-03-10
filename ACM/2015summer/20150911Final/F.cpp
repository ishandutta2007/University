#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int n;

int main()
{



	while(scanf("%d", &n) != EOF)
	{
		if(n % 3 == 0) printf("%d\n", n / 3);
		else printf("%d\n", n);
	}

	return 0;
}