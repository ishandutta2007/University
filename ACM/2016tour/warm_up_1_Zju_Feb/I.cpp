#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

double R, H, V, X0, dx, dy, dz;
const double PI = acos(-1.0);


int main()
{
	int T;
	double ans;
	cin >> T;
	while(T--)
	{
		ans = 0.0;
		cin >> R >> H >> V >> X0 >> dx >> dy >> dz;
		dz = fabs(dz);
		double t = X0 / V;
		ans += PI * R * R * t * dz;
		dx = fabs(dx - V);
		dy = fabs(dy);
		double dd = sqrt(dx*dx + dy*dy);
		ans += 2 * R * H * t * dd;
		printf("%.9lf\n", ans);
	}
	return 0;
}