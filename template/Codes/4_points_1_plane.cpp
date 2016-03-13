#include <bits/stdc++.h>
using namespace std;
struct  Point3 {
	double x, y, z;
	Point3  operator - ( Point3 & p ) {
		Point3  ans;
		ans.x = this->x - p.x;
		ans.y = this->y - p.y;
		ans.z = this->z - p.z;
		return ans;
	}
};
Point3 operator * ( const Point3 & a, const Point3 & b ) {
	Point3  ans;
	ans.x = a.y * b.z - a.z * b.y;
	ans.y = a.z * b.x - a.x * b.z;
	ans.z = a.x * b.y - a.y * b.x;
	return ans;
}
double  dot( const Point3 & a, const Point3 & b ) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
int main() {
	Point3  p[4];
	int T;
	cin >> T;
	while(T--) 
	{
		for( int i = 0; i < 4; ++i ) scanf( "%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z );
		puts( dot( p[3] - p[0], (p[2] - p[0])*(p[1] - p[0])) == 0.0 ? "Yes" : "No" );
	}
	return 0;
}