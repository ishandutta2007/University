#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>


const double EPS = 1e-10;


using namespace std;



double r[10020];
int ans[10020];


double cals(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return (p-a)*(p-b)*(p-c)/p;
}

int dcmp(double a, double b)
{
	if(fabs(a-b) < EPS) return 0;
	return a < b? -1 : 1;
}

int main()
{


	int n;
	scanf("%d", &n);
	double x, y, z;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		r[i] = cals(x, y, z);
		// cout << r[i] << endl;
	}



	sort(r, r + n);
	int aa = 1;
	ans[0] = 1;
	for(int i = 1; i < n; i++)
	{
		if(dcmp(r[i], r[i-1]) == 0)
		{
			ans[i] = ans[i-1] + 1;
		}
		else
			ans[i] = 1;

		aa = max(ans[i], aa);
	}


	cout << aa << endl;
	return 0;
}