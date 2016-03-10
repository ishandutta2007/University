#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

#define EPS 1e-10

double a[200020];
double sum[200020];
int n;

priority_queue<double>pq;

int dcmp(double x)
{
	if (fabs(x)<EPS) return 0;
	return x>0?1:-1;
}

double calmax(double x)
{
	while(!pq.empty()) pq.pop();
	memset(sum, 0, sizeof(sum));
	double tmp = -10000000.0;
	for(int i = 1; i <= n; i++)
	{
		sum[i] += sum[i-1] + a[i] - x;
	}
	pq.push(0.0);
	for(int i = 1; i <= n; i++)
	{
		tmp = max(tmp, sum[i] - pq.top());
		pq.push(sum[i]);
	}

	return tmp;

}
double calmin(double x)
{
	while(!pq.empty()) pq.pop();
	memset(sum, 0, sizeof(sum));
	double tmp = -10000000.0;
	for(int i = 1; i <= n; i++)
	{
		sum[i] += sum[i-1] - a[i] + x;
	}
	pq.push(0.0);
	for(int i = 1; i <= n; i++)
	{
		tmp = max(tmp, sum[i] - pq.top());
		pq.push(sum[i]);
	}
	return -tmp;
}

int main()
{


	scanf("%d", &n);
	double low = 30000, hi = -30000;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf", &a[i]);
		low = min(low, a[i]);
		hi = max(hi, a[i]);
	}

	double mid1, mid2;
	mid1 = (hi - low)/3 + low;
	mid2 = hi - (hi-low) / 3;

	double tmp1, tmp2;
	while(low < mid1 - EPS)
	{
		tmp1 = max(fabs(calmax(mid1)), fabs(calmin(mid1)));

		tmp2 = max(fabs(calmax(mid2)), fabs(calmin(mid2)));


		// cout << tmpmax << "  " << tmpmin << ""<< endl;
		if(fabs(tmp1) > fabs(tmp2))
		{
			hi = mid2;
		}
		else
		{
			low = mid1;
		}

	}

	printf("%.10f\n", mid1);

	return 0;
}