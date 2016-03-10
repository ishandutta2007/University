#include"cstdio"
#include"iostream"
#include"algorithm"
#include"cmath"

using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;



struct Point{
	double x,y;
	Point(double _x=0,double _y=0){
		x=_x,y=_y;
	}
	void read(){
		scanf("%lf%lf",&x,&y);
	}
};

struct Line{
	double a,b,c;
	Line(double _a,double _b, double _c):a(_a),b(_b),c(_c){}
	Line(){}
};


struct Lineseg{
	struct Point s,e;
	Lineseg(){}
	Lineseg(Point _s,Point _e){
		s = _s; e = _e;
	}
	
};


	bool equal_double(double a,double b){
		return (fabs(a-b)<eps);
	}
	double multiply(Point op, Point sp, Point ep){
		return ((sp.x - op.x)*(ep.y - op.y) - (ep.x - op.x)*(sp.y - op.y));
	}
	
	bool Isintersect(Point a1, Point a2, Point b1, Point b2){
		return min(a1.x, a2.x) <= max(b1.x, b2.x) &&
			min(a1.y, a2.y) <= max(b1.y, b2.y) &&
			min(b1.x, b2.x) <= max(a1.x, a2.x) &&
			min(b1.y, b2.y) <= max(a1.y, a2.y) &&
			multiply(a1, a2, b1) * multiply(a1, a2, b2) <= 0 &&
			multiply(b1, b2, a1) * multiply(b1, b2, a2) <= 0 ;
		
	}
	
	Line makeline(Point p1, Point p2){
		Line tl;
		tl.a = p2.y - p1.y;
		tl.b = p1.x - p2.x;
		tl.c = p1.y * p2.x - p1.x * p2.y;
		
		return tl;
	}
	bool lineintersect(Line l1, Line l2, Point &p){
		double d = l1.a * l2.b - l2.a * l1.b;
		if(fabs(d) < eps) return 0;
		p.y = (l1.c * l2.a - l1.a * l2.c) / d;
		p.x = (l2.c * l1.b - l1.c * l2.b) / d;
		return 1;
	}
	bool Line_Coincide(const Line &l1,const Line &l2){
		return equal_double(l1.a*l2.c,l2.a*l1.c) && equal_double(l1.b*l2.c,l2.b*l1.c);
	}


int main(){
	
	int n;
	struct Point a1,a2,b1,b2,p;
	
	
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	for(int i = 1; i <= n; i++){
		a1.read();
		a2.read();
		b1.read();
		b2.read();
		struct Line line1 = makeline(a1, a2);
		struct Line line2 = makeline(b1, b2);
		if(lineintersect(line1, line2, p) == 1)
			printf("POINT %.2lf %.2lf\n", p.x, p.y);
		else if(Line_Coincide(line1, line2) == 1)
			printf("LINE\n");
		else
			printf("NONE\n");
		
	}
	printf("END OF OUTPUT\n");
	
	
	
}




