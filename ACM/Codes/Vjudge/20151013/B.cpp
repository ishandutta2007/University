#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

int n;

int dcmp(double x)
{
	if(fabs(x) < EPS) return 0;
	return x < 0 ? -1:1;
}


struct Point{
	double x, y;
	Point(){}
	Point(double x, double y):x(x),y(y){}
};


vector<Point>ps;


int father[520];

double caldis(Point a, Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


int root(int a)
{
	return father[a]? father[a] = root(father[a]) : a;
}


void unionset(int a, int b)
{
	int fa = root(a);
	int fb = root(b);
	if(fa != fb)
	father[fa] = b;

}


int solve(double dis)
{
	memset(father, 0, sizeof(father));
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			if(dcmp(caldis(ps[i], ps[j]) - dis) <= 0)
				unionset(i, j);
		}


	int ret = 0;
	for(int i = 0; i < n; i++)if(father[i] == 0)
		ret ++;

	// cout << ret << endl;
	return ret;
}



int main()
{
	int T;
	scanf("%d", &T);
	int m;
	double x, y;
	while(T--)
	{
		scanf("%d%d",&m,&n);
		ps.clear();
		for(int i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &x, &y);
			ps.push_back(Point(x, y));
		}

		double low = 0.0, high = 20000;
		// cout << m << endl;
		while(low+0.0001 < high)
		{
			double mid = (high + low) / 2;
			if(solve(mid) <= m)
				high = mid;
			else low = mid;
		}

		printf("%.2f\n", low);

	}
	return 0;
}