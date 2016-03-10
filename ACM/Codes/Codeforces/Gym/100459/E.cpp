#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

struct point
{
	double x, y, z;
	point(){}
	point(double x, double y, double z):x(x),y(y),z(z){}
}C;

const double eps = 1e-10;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1010;
int cmp(double x)
{
	if(fabs(x) < eps) return 0;
	return x < 0? -1:1;
}
int cmp(double x, double y)
{
	return cmp(x-y);
}
//x的平方
inline double sqr(double x){return x*x;};


struct Point
{
	double x, y;
	Point(){}
	Point(double _x, double _y):x(_x),y(_y){}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	void output()
	{
		printf("%.2f %.2f\n", x, y);
	}
	bool operator == (Point b)const
	{
		return cmp(x, b.x)==0 &&cmp(y, b.y)==0;
	}
	bool operator < (Point b)const
	{
		return cmp(x, b.x)==0? cmp(y, b.y)<0 : x<b.x;
	}
	Point operator - (const Point b)const
	{
		return Point(x-b.x,y-b.y);
	}
	Point operator + (const Point b)const
	{
		return Point(x+b.x,y+b.y);
	}
	//叉积^
	double operator ^(const Point b)const
	{
		return x*b.y - y*b.x;
	}
	//点积*
	double operator *(const Point b)const
	{
		return x*b.x+y*b.y;
	}
	Point operator *(const double k)const
	{
		return Point(x*k, y*k);
	}
	Point operator /(const double k)const
	{
		return Point(x/k, y/k);
	}
	//返回长度
	double len()
	{
		return hypot(x, y);
	}
	//返回长度的平方
	double len2()
	{
		return x*x+y*y;
	}
	//返回两点之间的距离
	double distance(Point p)
	{
		return hypot(x-p.x, y-p.y);
	}
	//求 ∠APB 的大小 弧度制
	//LightOJ 1230
	double rad(Point a, Point b)
	{
		Point p = *this;
		return fabs(atan2(fabs((a-p)^(b-p)),(a-p)*(b-p)));
	}
	//化为长度为r的向量
	Point turnc(double r)
	{
		double l = len();
		//为0向量，返回本身
		if(!cmp(l)) return *this;
		r /= l;
		return Point(x*r, y*r);
	}
	//逆时针旋转 90 度
	Point rotleft()
	{
		return Point(-y,x);
	}
	//顺时针旋转 90 度
	Point rotright()
	{
		return Point(y, -x);
	}
	//绕着点 p 逆时针旋转 angle (rad)
	Point rotate(Point p, double angle)
	{
		Point v = (*this)-p;
		double c = cos(angle), s = sin(angle);
		return Point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
	}
};

struct Line
{
	Point s, e;
	Line(){}
	Line(Point _s, Point _e):s(_s),e(_e){}
	bool operator == (Line v)const
	{
		return (s==v.s)&&(e==v.e);
	}
	//根据一个点和倾斜角 angle 确定直线， 0 <= angle < pi;
	Line(Point p, double angle)
	{
		s = p;
		if(cmp(angle, pi/2) == 0)
		{
			e = (s+Point(0,1));
		}else{
			e = (s+Point(1,tan(angle)));
		}
	}
	//根据ax+by+c=0
	Line(double a, double b, double c)
	{
		if(cmp(a)==0)
		{
			s=Point(0,-c/b);
			e=Point(1,-c/b);
		}
		else if(cmp(b)==0)
		{
			s=Point(-c/a,0);
			e=Point(-c/a,1);
		}
		else
		{
			s=Point(0,-c/b);
			e=Point(1,(-c-a)/b);
		}
	}
	void input()
	{
		s.input();
		e.input();
	}
	//调整为起点在终点的左下方
	void adjust()
	{
		if(e<s) swap(e, s);
	}
	//计算以s e 为端点的线段的长度
	double length()
	{
		return s.distance(e);
	}
	//返回直线倾斜角
	double angle()
	{
		double k = atan2(e.y-s.y,e.x-s.x);
		if(cmp(k)<0) k+=pi;
		if(cmp(k,pi)==0) k-=pi;
		return k;
	}
	//点和直线关系
	//1 在左侧
	//2 在右侧
	//3 在直线上
	int relation(Point p)
	{
		int c = cmp((p-s)^(e-s));
		if(c<0) return 1;
		else if(c>0) return 2;
		else return 3;
	}
	//点在线段上的判定
	bool pointonseg(Point p)
	{
		//包含在端点上 <=
		//不包含在端点上 <
		return cmp((p-s)^(e-s))==0 && cmp((p-s)*(p-e)) <= 0;
	}
	//两向量平行(对应直线平行或重合)
	bool parallel(Line v)
	{
		return cmp((e-s)^(v.e-v.s))==0;
	}
	//两线段相交判断
	//2 规范相交
	//1 非规范相交
	//0 不相交
	int segcrossseg(Line v)
	{
		int d1=cmp((e-s)^(v.s-s));
		int d2=cmp((e-s)^(v.e-s));
		int d3=cmp((v.e-v.s)^(s-v.s));
		int d4=cmp((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2 && (d3^d4)==-2) return 2;
		return (d1==0 && cmp((v.s-s)*(v.s-e))<=0) ||
			(d2==0 && cmp((v.e-s)*(v.e-e))<=0) ||
			(d3==0 && cmp((s-v.s)*(s-v.e))<=0) ||
			(d4==0 && cmp((e-v.s)*(e-v.e))<=0);
	}
	//直线和线段相交判断
	//*this line
	//v seg
	//2 规范相交
	//1 非规范相交
	//0 不相交
	int linecrossseg(Line v)
	{
		int d1 = cmp((e-s)^(v.s-s));
		int d2 = cmp((e-s)^(v.e-s));
		if((d1^d2)==-2) return 2;
		return (d1==0||d2==0);
	}
	//两直线平行
	//0 平行
	//1 重合
	//2 相交
	int linecrossline(Line v)
	{
		if((*this).parallel(v)) return v.relation(s)==3;
		return 2;
	}
	//两直线的交点
	//要保证两直线不平行或重合
	Point crosspoint(Line v)
	{
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1), (s.y*a2-e.y*a1)/(a2-a1));
	}
	//点到直线的距离
	double dispointtoline(Point p)
	{
		return fabs((p-s)^(e-s))/length();
	}
	//点到线段的距离
	double dispointtoseg(Point p)
	{
		if(cmp((p-s)*(e-s))<0 || cmp((p-e)*(s-e))<0)
			return min(p.distance(s), p.distance(e));
		return dispointtoline(p);
	}
	//返回线段到线段的距离
	//前提是两线段不相交， 相交距离为0
	double dissegtoseg(Line v)
	{
		return min(min(dispointtoseg(v.s), dispointtoseg(v.e)),min(v.dispointtoseg(s),v.dispointtoseg(e)));
	}
	//返回点 p 在直线上的投影
	Point lineprog(Point p)
	{
		return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
	}
	//返回点 p 关于直线的对称点
	Point symmetrypoint(Point p)
	{
		Point q = lineprog(p);
		return Point(2*q.x-p.x,2*q.y-p.y);
	}
};


vector<point> vp;
vector<Point> tp;


int main()
{
	int x, y, z;
	int touchplane = 0;
	for(int i = 0; i < 4; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if(z == 0)
		{
			touchplane ++;
			tp.push_back(Point(x, y));
		}
		vp.push_back(point(x, y, z));
	}

	if(touchplane == 0)
	{
		printf("Falling\n");
		return 0;
	}

	C = point(0,0,0);

	for(int i = 0; i < 4; i++)
	{
		C.x += vp[i].x;
		C.y += vp[i].y;
		C.z += vp[i].z;
	}
	C.x/=3;
	C.y/=3;
	C.z=0.0;
	Point c = Point(C.x, C.y);

	if(touchplane == 1)
	{
		if(cmp(tp[0].x, C.x)==0 && cmp(tp[0].y, C.y)==0)
			printf("Unstable\n");
		else
			printf("Falling\n");
		return 0;
	}
	else if(touchplane == 2)
	{
		Line L = Line(tp[0], tp[1]);
		if(L.pointonseg(c)) printf("Unstable\n");
		else printf("Falling\n");
	}
	if(touchplane == 3)
	{
		for(int i = 0; i < 3; i++)
		{
			Line tl = Line(tp[i], tp[(i+1)%3]);
			if(tl.pointonseg(c))
			{
				printf("Unstable\n");
				return 0;
			}
		}

		double tmp = 0, tmp1 = 0;
		tmp1 = fabs((tp[2]-tp[0])^(tp[1]-tp[0]));
		for(int i = 0; i < 3; i++)
			tp[i] = tp[i] - c;
		for(int i = 1; i < 3; i++)
			tmp += fabs(tp[i]^tp[(i+1)%3]);
		if(cmp(tmp, tmp1) != 0) printf("Falling\n");
		else printf("Standing\n");
	}
	return 0;
}