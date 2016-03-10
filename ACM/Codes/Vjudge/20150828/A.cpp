// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define EPS (1e-10)
// #define MAXN = 1000000.0
const double PI = acos(-1.0);
struct Point
{
	double x, y;
	Point(double x=0.0,double y=0.0):x(x),y(y){}
};
typedef Point Vec;
int dcmp(double x){if(fabs(x) < EPS) return 0; return x<0.0?-1:1;}
int dcmp(double x, double y){return dcmp(x-y);}
double isint(double x){return fabs(x - (int)(x+0.5))<EPS;}
Vec operator + (Vec a, Vec b){return Vec(a.x+b.x,a.y+b.y);}
Vec operator - (Vec a, Vec b){return Vec(a.x-b.x,a.y-b.y);}
double operator * (Vec a, Vec b){return a.x*b.y-a.y*b.x;}
Vec operator * (Vec a, double b){return Vec(a.x*b,a.y*b);}
Vec operator / (Vec a, double b){return Vec(a.x/b,a.y/b);}
bool operator == (Vec a, Vec b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
double operator ^ (Vec a, Vec b){return a.x*b.x+a.y*b.y;}
bool operator < (Vec a, Vec b){ return a.x<b.x || (a.x==b.x&&a.y<b.y);}// < 水平序
double operator % (Vec a, double b){return sqrt(a^a)/b;}
bool operator == (Vec a, double b){return (a%1.0) == b;}
double ang(Vec v){return atan2(v.y, v.x);}//angle between v and x+ range 0 - 2*PI
double ang(Vec a,Vec b){return acos((a^b)/(a%1.0)/(b%1.0));}
Vec rotv(Vec A,double rad){return Vec(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));} //rotate rad counterclockwise
Vec getvn(Vec A){double L = A%1.0;return Vec(-A.y/L,A.x/L);}//求 A 逆时针旋转90°的单位法向量
double area2(Point A,Point B,Point C){return (B-A)*(C-A);}//ABC的三角形有向面积的两倍
double area2(Vec A, Vec B){return A*B;}//AB为邻边的三角形有向面积的两倍
/*************************************
basic operations of Vectors and Points
**************************************/
struct Line
{
	Point p;Vec v;double ang;
	Line(){}
	Line(Point p,Vec v):p(p),v(v){ang=atan2(v.y,v.x);if(dcmp(ang, 0.0)<0||dcmp(ang, PI)>=0) ang=atan2(-v.y,-v.x);}
	bool operator < (const Line& L) const {return ang < L.ang;}
	Point point(double t){return p+v*t;}//根据参数t求得直线上一点
};
Point intersection_point(Line a,Line b)
//P+tv和Q+tw两条直线的交点,确保有唯一交点
{
	Point p=a.p,q=b.p;Vec v=a.v,w=b.v,u=p-q;
	double t=(w*u)/(v*w);
	return a.point(t);
}
double distance_p_l(Point P,Line a)
{
	Vec v1 = a.v,v2 = P-a.p;
	return fabs((v1*v2)/(v1%1.0));//不取绝对值那么得到的是有向距离
}

double distace_p_seg(Point P,Point A,Point B)
//点到线段的距离
//需要考虑点和线段的位置关系
{
	if(A == B) return (P-A)%1.0;
	Vec v1=B-A,v2=P-A,v3=P-B;
	if(dcmp(v1^v2)<0) return v2%1.0;
	else if(dcmp(v1^v3)>0) return v3%1.0;
	else return fabs(v1*v2)/(v1%1.0);
}

Point projection_p_l(Point P,Line a){return a.p + a.v*((a.v^(P-a.p))/(a.v^a.v));}
//点在直线上的投影
//判断两条线段是否相交 此处必须为规范相交
bool intersection_seg_seg(Point a1,Point a2,Point b1,Point b2){
	double c1 = (a2-a1)*(b1-a1),c2 = (a2-a1)*(b2-a1);
	double c3 = (b2-b1)*(a1-b1),c4 = (b2-b1)*(a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
//如果允许端点相交，则用以下代码，判断一个点是否在一条线段上s
bool onsegment_p(Point p,Point s,Point e){return dcmp((s-p)*(e-p)) == 0 && dcmp((s-p)^(e-p))<0;}

//判断点和多边形位置关系
int inpolygon_p(Point p, const vector<Point>& poly)
{
	int w = 0;
	for(int i=0,n=poly.size();i<n;i++){
		if(onsegment_p(p,poly[i],poly[(i+1)%n]))return -1;//在边界上
		int k = dcmp((poly[(i+1)%n]-poly[i])*(p-poly[i]));
		int d1 = dcmp(poly[i].y - p.y);
		int d2 = dcmp(poly[(i+1)%n].y - p.y);
		if(k > 0 && d1 <= 0 && d2 > 0)w++;
		if(k < 0 && d2 <= 0 && d1 > 0)w--;
	}
	if(w != 0)return 1;
	return 0;
}
//多边形有向面积,点需要极角排序
double cals_polygon(vector<Point> p)
{
	double area = 0;
	for(int i=1,n=p.size();i<n-1;i++)
		area+=(p[i]-p[0])*(p[i+1]-p[0]);
	return area/2.0;
}
//多边形周长,点需要极角排序
double calc_polyon(vector<Point> p)
{
	double ans = 0;
	for(int i=0,n = p.size();i<n-1;i++)
		ans+= (p[i+1]-p[i])%1.0;
	ans+=(p[0]-p[p.size()-1])%1.0;
	return ans;
}
//如果线上的点不算就改成>
bool onleft(Line L,Point P){return (L.v)*(P - L.p)>=0;}

//UNDONE BELOW
int halfplane_intersection(Line* L,int n,Point* poly)
//半平面交所需函数及主过程
{
	sort(L,L+n);
	int first,last;
	Point *p = new Point[n];
	Line *q = new Line[n];
	q[first = last = 0] = L[0];
	for(int i=1;i<n;i++){
		while(first<last && !onleft(L[i],p[last-1]))last--;
		while(first<last && !onleft(L[i],p[first]))first++;
		q[++last] = L[i];
		if(fabs((q[last].v)*(q[last-1].v))<EPS){
			last--;
			if(onleft(q[last],L[i].p))q[last] = L[i];
		}
		if(first<last) p[last-1] = intersection_point(q[last-1],q[last]);
	}
	while(first<last && !onleft(q[first],p[last-1]))last -- ;
	if(last-first<=1)return 0;
	p[last] = intersection_point(q[last],q[first]);
	int m = 0;
	for(int i=first;i<=last;i++)poly[m++] = p[i];
	return m;
}

vector<Point> ConvexHull(vector<Point> p)
{
	sort(p.begin(),p.end());
	//删除重复点
	p.erase(unique(p.begin(),p.end()),p.end());
	int n = p.size();
	vector<Point> ch(n+1);
	int m = 0;
	for(int i=0;i<n;i++){
		while(m>1 && dcmp((ch[m-1]-ch[m-2])*(p[i]-ch[m-2])) <= 0) m--;         //若需要把边线上的点也算上，把等号去掉
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2;i>=0;i--){
		while(m > k && dcmp((ch[m-1] - ch[m-2])*(p[i]-ch[m-2] )) <= 0)m--;
		ch[m++] = p[i];
	}
	if(n > 1)m--;
	ch.resize(m);
	return ch;
}
/*=============以上为凸包==========*/
double earthdis(Point a,Point b)
//给出经纬度，算出球体上两点之间的角度
//纬度作为纵坐标，经度作为横坐标
//以度为单位，返回弧度值
{
	double x1=PI*a.x/180.0;
	double y1=PI*a.y/180.0;
	double x2=PI*b.x/180.0;
	double y2=PI*b.y/180.0;
	return acos(cos(x1-x2)*cos(y1)*cos(y2)+sin(y1)*sin(y2));
}
struct Circle
{
	Point c;
	double r;
	Circle(){};
	Circle(Point c,double r):c(c),r(r){}
	Point point(double a){
		return Point(c.x+cos(a)*r,c.y + sin(a)*r);
	}
};
int getLineCircleIntersection(Line L, Circle C, double& t1,double& t2,vector<Point>& sol)
//圆和直线交点方程法
//返回交点个数
//sol 为交点的数组
{
	double a=L.v.x,b=L.p.x-C.c.x,c=L.v.y,d=L.p.y-C.c.y,e=a*a+c*c,f=2*(a*b+c*d),g=b*b-C.r*C.r,delta=f*f-4*e*g;
	//相离
	if(dcmp(delta)<0)return 0;              
	//相切
	if(dcmp(delta)==0){t1 = t2 = -f/(2*e);sol.push_back(L.point(t1));return 1;}
	//相交
	t1 = (-f - sqrt(delta)) / (2*e); sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2*e); sol.push_back(L.point(t2));
	return 2;
}
int getLineCircleIntersection(Line L, Circle C,vector<Point>& sol)
//圆和直线交点几何法
//返回交点个数
{
	double d = distance_p_l(C.c, L);
	//相离
	if(dcmp(d - C.r)>0)return 0;
	Point ans = intersection_point(L, Line(C.c,getvn(L.v)));
	//相切
	if(dcmp(d - C.r) == 0){sol.push_back(ans);return 1;}
	//相交
	double len = sqrt(C.r*C.r-d*d);
	Vec v = L.v / (L.v%1.0);
	sol.push_back(ans + v * len),sol.push_back(ans - v * len);
	return 2;
}
//判断两圆相交
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol){
	double d = (C1.c-C2.c)%1.0;
	if( dcmp(C1.r - C2.r)>0)
		swap(C1,C2);
	if(dcmp(d)==0){
		if(dcmp(C1.r-C2.r)==0)return -1;//重合
		return 0;
	}
	if(dcmp(C1.r + C2.r -d) < 0) return 0;//外离
	if(dcmp(fabs(C1.r-C2.r)-d)>0)return 0;//内含
	if(dcmp(C1.r + C2.r - d) == 0 || dcmp(fabs(C1.r - C2.r)-d) == 0){
		Vec p = C1.c-C2.c;
		sol.push_back(C2.c + p / (p%1.0) * C2.r);
		return 1;
	}//外切或内切
	double a = ang(C2.c - C1.c);
	double da = acos((C1.r * C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
	Point p1 = C1.point(a-da),p2 = C1.point(a+da);
	sol.push_back(p1);
	sol.push_back(p2);
	return 2;//相交
}
//过点p到圆C的切线
int getTangents(Point p,Circle C,vector<Line>& L){
	Vec u = C.c - p , temp;
	double dist = (u%1.0);
	if(dist < C.r) return 0;
	else if(dcmp(dist - C.r) == 0){
		temp = getvn(u);
		L.push_back(Line(p,temp));
		return 1;
	}else{
		double ang = asin(C.r/dist);
		temp = rotv(u,-ang);
		L.push_back(Line(p,temp));
		temp = rotv(u,+ang),L.push_back(Line(p,temp));
		return 2;
	}
}
//两圆公切线,返回切线条数，-1表示无穷多条
//注意,当两圆内切或者外切的时候,切点相同,均为p.
//sol里存的是切线，p为a上切点,p+v为b上切点
int getTangents(Circle A,Circle B,vector<Line>& sol)
{
	int cnt = 0;
	Point a,b;
	if(dcmp(A.r - B.r) < 0)swap(A,B);
	double d2 = (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y -B.c.y);
	double rdiff = A.r - B.r;
	double rsum = A.r + B.r;
	if(dcmp(d2 - rdiff * rdiff) < 0) return 0;//内含

	double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
	if(dcmp(d2)==0 && A.r == B.r)return -1;//重合,切线无限多
	if(dcmp(d2-rdiff * rdiff)==0){//内切，一条切线
		a = A.point(base),b = B.point(base);
		sol.push_back(Line(a,getvn(A.c-B.c)));
		return 1;
	}
	//有外切线
	double ang = acos((A.r-B.r) / sqrt(d2));
	a = A.point(base+ang),b = B.point(base+ang),sol.push_back(Line(a,b-a)),cnt++;
	a = A.point(base-ang),b = B.point(base-ang),sol.push_back(Line(a,b-a)),cnt++;
	if(dcmp(d2 - rsum * rsum)==0){
		a = A.point(base),b = B.point(PI + base),sol.push_back(Line(a,getvn(A.r-B.r))),cnt++;
	}else if(dcmp(d2 - rsum * rsum)>0){
		double ang2 = acos((A.r + B.r) / sqrt(d2));
		a = A.point(base+ang),b = B.point(PI+base+ang2),sol.push_back(Line(a,b-a)),cnt++;
		a = A.point(base-ang),b = B.point(PI+base-ang2),sol.push_back(Line(a,b-a)),cnt++;
	}
	return cnt;
}
/*==========以上为圆的常用函数及计算==========*/

Point translation(Point p, Vec v, double m)
{
	double theta = atan2(v.y, v.x);
	return Point(p.x+m*cos(theta), p.y+m*sin(theta));
}

void CircumscribedCircle(Point a, Point b, Point c)
{
	Point p1 = (a + b) / 2, p2 = (a + c) / 2;
	Line l1 = Line(p1, getvn(b-a)), l2 = Line(p2,getvn(c-a));
	Point o = intersection_point(l1, l2);
	printf("(%.6lf,%.6lf,%.6lf)\n", o.x,o.y,(o-a)%1.0);
}
void InscribedCircle(Point a, Point b, Point c)
{
	Line l1 = Line(a, (c-a)/((c-a)%1.0) + (b-a)/((b-a)%1.0)), l2 = Line(b, (c-b)/((c-b)%1.0) + (a-b)/((a-b)%1.0)), l3 = Line(a, c - a);
	// cout << l1.v.x <<","<< l1.v.y<<endl;
	// cout << l2.v.x <<","<< l2.v.y<<endl;
	Point o = intersection_point(l1, l2);
	printf("(%.6lf,%.6lf,%.6lf)\n", o.x,o.y,distance_p_l(o, l3));
}
void TangentLineThroughPoint(Circle O, Point p)
{
	vector<Line>Ls;
	Ls.clear();
	getTangents(p, O, Ls);
	sort(Ls.begin(), Ls.end());
	printf("[");
	for(int i = 0; i < Ls.size();i++)
	{
		printf("%.6lf", fabs(Ls[i].ang * 180 / PI));
		if(i != Ls.size() - 1) printf(",");
	}
	printf("]\n");
}
bool cmp1(Point a, Point b)
{
	return a.y < b.y || (a.y==b.y && a.x < b.x);
}
void CircleThroughAPointAndTangentToALineWithRadius(Point p, Line l, double r)
{
	vector<Point>v;
	Circle O = Circle(p, r);
	Line l2 = Line(translation(l.p, getvn(l.v), r), l.v);
	Line l3 = Line(translation(l.p, getvn(l.v), -r), l.v);
	getLineCircleIntersection(l2, O, v);
	getLineCircleIntersection(l3, O, v);
	sort(v.begin(), v.end());
	printf("[");
	for(int i = 0; i < v.size();i++)
	{
		printf("(%.6lf,%.6lf)", v[i].x, v[i].y);
		if(i != v.size() - 1) printf(",");
	}
	printf("]\n");
}
void CircleTangentToTwoLinesWithRadius(Line l1, Line l2, double r)
{
	vector<Point>v;
	v.clear();
	Point p = intersection_point(l1, l2);
	Vec n = l1.v/(l1.v%1.0) + l2.v/(l2.v%1.0);
	v.push_back(translation(p, n, r/sin(ang(l1.v, l2.v)/2)));
	v.push_back(translation(p, n, -r/sin(ang(l1.v, l2.v)/2)));
	l2.v.x = -l2.v.x;
	l2.v.y = -l2.v.y;
	n = l1.v/(l1.v%1.0) + l2.v/(l2.v%1.0);
	v.push_back(translation(p, n, r/sin(ang(l1.v, l2.v)/2)));
	v.push_back(translation(p, n, -r/sin(ang(l1.v, l2.v)/2)));
	sort(v.begin(), v.end());
	printf("[");
	for(int i = 0; i < v.size();i++)
	{
		printf("(%.6lf,%.6lf)", v[i].x, v[i].y);
		if(i != v.size() - 1) printf(",");
	}
	printf("]\n");
}

void CircleTangentToTwoDisjointCirclesWithRadius(Circle o1, Circle o2, double r)
{
	vector<Point>v;
	v.clear();
	o1.r += r;
	o2.r += r;
	getCircleCircleIntersection(o1, o2, v);
	sort(v.begin(), v.end());
	printf("[");
	for(int i = 0; i < v.size();i++)
	{
		printf("(%.6lf,%.6lf)", v[i].x, v[i].y);
		if(i != v.size() - 1) printf(",");
	}
	printf("]\n");
}


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif


	// Point pp = Point(0,0);
	// pp = translation(pp, Vec(-1, -1), -2);
	// cout << pp.x << "   " << pp.y << endl;

	char cmd[50];
	Point p[10];
	while(scanf("%s", cmd)!=EOF)
	{
		if(strcmp(cmd, "CircumscribedCircle") == 0)
		{
			for(int i = 0; i < 3; i++)
			{
				cin >> p[i].x >> p[i].y;
			}
			CircumscribedCircle(p[0], p[1], p[2]);
		}
		else if(strcmp(cmd, "InscribedCircle") == 0)
		{
			for(int i = 0; i < 3; i++)
			{
				cin >> p[i].x >> p[i].y;
				// cout << p[i].x << p[i].y;
			}
			sort(p, p + 3, cmp1);
			InscribedCircle(p[0], p[1], p[2]);
		}
		else if(strcmp(cmd, "TangentLineThroughPoint") == 0)
		{
			Circle o;
			cin >> o.c.x >> o.c.y >> o.r >> p[0].x >> p[0].y;
			TangentLineThroughPoint(o, p[0]);
		}
		else if(strcmp(cmd, "CircleThroughAPointAndTangentToALineWithRadius") == 0)
		{
			double r;
			cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> r;
			Line l1 = Line(p[1], p[2] - p[1]);
			CircleThroughAPointAndTangentToALineWithRadius(p[0], l1, r);
		}
		else if(strcmp(cmd, "CircleTangentToTwoLinesWithRadius") == 0)
		{
			double r;
			for(int i = 0; i < 4; i++)
			{
				cin >> p[i].x >> p[i].y;
			}
			cin >> r;
			Line l1 = Line(p[0], p[1]-p[0]);
			Line l2 = Line(p[2], p[3]-p[2]);
			CircleTangentToTwoLinesWithRadius(l1, l2, r);
		}
		else
		{
			Circle O1, O2;
			double r;
			cin >> O1.c.x >> O1.c.y >> O1.r >> O2.c.x >> O2.c.y >> O2.r >> r; 
			CircleTangentToTwoDisjointCirclesWithRadius(O1, O2, r);
		}
	}

	return 0;
}