#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

#define EPS 1e-12


// int dcmp(double a, double b)
// {
// 	if(fabs(a - b) < EPS) return 0;

// }

int dcmp(double x)
{
	if (fabs(x)<EPS) return 0;
	return x>0?1:-1;
}

double x, y;
double xx, yy;
int main()
{

	cin >> x >> y;
	if(dcmp(y - x)>0) 
	{
		cout << -1 << endl;
		return 0;
	}
	xx = yy = (x + y) / 2.0;


	while(dcmp(yy / 2 - y)>=0)
	{
		xx /= 2;
		yy /= 2;
	}

	// cout << xx << endl;
	printf("%.11f\n", xx);
	return 0;
}