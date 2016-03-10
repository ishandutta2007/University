#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>


#define EPS 1e-11


using namespace std;



int dcmp(double a, double b)
{
	if(fabs(a-b) < EPS) return 0;
	return a > b? 1 : -1;
}



double k;
double l;

int main()
{


	int T;
	scanf("%d", &T);
	int ans;
	while(T--)
	{

		scanf("%lf", &k);
		k = 0.5 - k;
		l = 0.5;
		if(dcmp(0, k) == 0)
		{
			printf("1000\n");
			continue;
		}

		ans = 0;
		for(int i = 1; i <= 500; i++)
		{



			int del = dcmp(k, l);
			if(del == 0)
			{
				printf("-1\n");
				break;
			}

			else if(del > 0)
			{
				printf("%d\n", ans);
				break;
			}

			else
			{
				l /= 2;
				ans += 4;
			}
		}

	}

	return 0;
}