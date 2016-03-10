#include <cstdio>
#include <iostream>
#include <cmath>


using namespace std;


int a[100020];



int main()
{

	int n;
	int tmp;
	bool flag;
	while(scanf("%d", &n) != EOF)
	{

		flag = true;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			tmp = sqrt(a[i]);
			if(tmp * tmp != a[i])
				flag = false;
		}


		printf("%s\n", flag ? "Yes" : "No");

	}



	return 0;
}