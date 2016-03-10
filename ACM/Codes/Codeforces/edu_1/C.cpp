#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;


const long double EPS = 1e-20;
const double PI = acos(-1.0);

int dcmp(double a)
{
	if(fabs(a) < EPS) return 0;
	return a > 0? 1 : -1;
}

struct Vec
{
	int i;
	long double ang;
	Vec(int x, int y, int i):i(i)
	{
		ang = atan2(y, x);
	}
	Vec(){}
}v[100020];

bool cmp(Vec a, Vec b)
{
	return a.ang < b.ang;
}


int main()
{

	// cout << atan2(10000, 10000) << endl;
	// cout << (PI < 3.14159) << endl;
	int n;
	scanf("%d", &n);
	int x, y;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		v[i] = Vec(x, y, i);
		// cout << v[i].ang << endl;
	}

	sort(v + 1, v + n + 1, cmp);


	int p1 = v[1].i, p2 = v[n].i;
	long double ans = v[1].ang + PI * 2 - v[n].ang;
	for(int i = 1; i < n; i++)
	{
		if(v[i+1].ang - v[i].ang < ans)
		{
			p1 = v[i+1].i;
			p2 = v[i].i;
			ans = v[i+1].ang - v[i].ang;
		}
	}

	printf("%d %d\n", p1, p2);

	return 0;
}