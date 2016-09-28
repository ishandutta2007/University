const double PI = acos(-1.0);
const double MAXN = 1000000.0;
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vec;
//向量+向量 = 向量，点+向量 = 点
Vec operator +(Vec A,Vec B){return Vec(A.x+B.x,A.y+B.y);}
//点-点 = 向量
Vec operator -(Point A,Point B){return Vec(A.x-B.x,A.y-B.y);}
//向量*数 = 向量
Vec operator *(Vec A,double p){return Vec(A.x*p,A.y*p);}
//向量/数 = 向量
Vec operator /(Vec A,double p){return Vec(A.x/p,A.y/p);}
bool operator <(const Point& a,const Point& b){
	return a.x<b.x || (a.x == b.x && a.y<b.y);
}
const double EPS = 1e-10;
int dcmp(double x){
	if(fabs(x)<EPS) return 0;else return x<0? -1: 1;
}
bool operator == (const Point& a,const Point &b){
	return dcmp(a.x-b.x)==0 &&dcmp(a.y-b.y) == 0;
}
double ang(Vec v){return atan2(v.y,v.x);}
/*========直线基本定义========*/
struct Line{
	Point P;
	Vec v;
	double ang;
	Line(){}
	Line(Point P,Vec v):P(P),v(v){ang  = atan2(v.y,v.x);}
	bool operator < (const Line& L) const {
		return ang < L.ang;
	}
	Point point(double a){
		return P+v*a;
	}
};
/*========圆的基本定义========*/
struct Circle{
	Point c;
	double r;
	Circle(Point c,double r):c(c),r(r){}
	Point point(double a){
		return Point(c.x+cos(a)*r,c.y + sin(a)*r);
	}
};
/*==========以上为基本定义============*/


double Dot(Vec A,Vec B){return A.x*B.x+A.y*B.y;}
double Length(Vec A){ return sqrt(Dot(A,A));}
//只能就算较小的那个角！
double Angle(Vec A,Vec B){return acos(Dot(A,B)/Length(A)/Length(B));}
/*==========用点积算向量长度和两个向量夹角============*/


double Cross(Vec A,Vec B){return A.x*B.y - A.y*B.x;}
//ABC的三角形有向面积的两倍
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}
//rad是弧度 逆时针旋转 //注意：是绕原点旋转，否则要加上坐标
Vec Rotate(Vec A,double rad){
	return Vec(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
//逆时针旋转90°的单位法向量
Vec Normal(Vec A){
	double L = Length(A);
	return Vec(-A.y/L,A.x/L);
}
/*=====以上为叉积的基本运算=====*/


//P+tv和Q+tw两条直线的交点,确保有唯一交点
Point GetlineIntersection(Line a,Line b){
	Point P = a.P,Q = b.P;
	Vec v = a.v,w = b.v;
	Vec u = P-Q;
	double t = Cross(w,u)/Cross(v,w);
	return a.point(t);
}
//点到直线的距离
double DistanceToLine(Point P,Line a){
	Point A = a.P,B = a.P + a.v;
	Vec v1 = B-A,v2 = P-A;
	return fabs(Cross(v1,v2)/Length(v1));//不取绝对值那么得到的是有向距离
}
//点到线段的距离
double DistanceToSegment(Point P,Point A,Point B){
	if(A == B)return Length(P-A);
	Vec v1 = B - A, v2 = P - A, v3 = P - B;
	if(dcmp(Dot(v1,v2))<0)return Length(v2);
	else if(dcmp(Dot(v1,v3))>0) return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v1);
}
//点在直线上的投影
Point GetLineProjection(Point P,Line a){
	Point A = a.P,B = a.P + a.v;
	Vec v = B - A;
	return A + v*(Dot(v,P-A) / Dot(v,v));
}
//判断两条线段是否相交 此处必须为规范相交
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
	double c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-a1);
	double c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
//如果允许端点相交，则用以下代码，判断一个点是否在一条线段上
bool OnSegment(Point p,Point a1,Point a2){   //不对，不允许端点相交
	if (p == a1 || p == a2) return 1;
	return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p))<0;
}
/*=========以上为点和直线，直线和直线关系的内容========*/
//判断点和多边形位置关系
int isPointInPolygon(Point p, const vector<Point>& poly){
	int w = 0;
	int n = poly.size();
	for(int i=0;i<n;i++){
		if(OnSegment(p,poly[i],poly[(i+1)%n]))return -1;//在边界上
		int k = dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
		int d1 = dcmp(poly[i].y - p.y);
		int d2 = dcmp(poly[(i+1)%n].y - p.y);
		if(k > 0 && d1 <= 0 && d2 > 0)w++;
		if(k < 0 && d2 <= 0 && d1 > 0)w--;
	}
	if(w != 0)return 1;
	return 0;
}
//多边形有向面积
double PolygonArea(vector<Point> p){
	int n = p.size();
	double area = 0;
	for(int i=1;i<n-1;i++)
		area += Cross(p[i] - p[0],p[i+1]-p[0]);
	return area/2;
}
//多边形周长
double PolygonZhouc(vector<Point> p){
	int n = p.size();
	if (!n) return 0.0;
	double ans = 0;
	for(int i=0;i<n-1;i++)
		ans+= Length(p[i+1]-p[i]);
	ans+=Length(p[0]-p[n-1]);
	return ans;
}
double isint(double x){
	return fabs(x - (int)(x+0.5))<EPS;
}
/*========多边形面积等内容=========*/

bool OnLeft(Line L,Point P){
	return Cross(L.v,P - L.P)>=0;          //如果线上的点不算就改成>
}
int HalfplaneIntersection(Line* L,int n,Point* poly){ //L数组是从0开始
	sort(L,L+n);
	int first,last;
	Point *p = new Point[n];
	Line *q = new Line[n];
	q[first = last = 0] = L[0];
	for(int i=1;i<n;i++){
		while(first<last && !OnLeft(L[i],p[last-1]))last--;
		while(first<last && !OnLeft(L[i],p[first]))first++;
		q[++last] = L[i];
		if(fabs(Cross(q[last].v,q[last-1].v))<EPS){
			last--;
			if(OnLeft(q[last],L[i].P))q[last] = L[i];
		}
		if(first<last) p[last-1] = GetlineIntersection(q[last-1],q[last]);
	}
	while(first<last && !OnLeft(q[first],p[last-1]))last -- ;
	if(last-first<=1)return 0;
	p[last] = GetlineIntersection(q[last],q[first]);
	int m = 0;
	for(int i=first;i<=last;i++)poly[m++] = p[i];
	return m;
}
/*=========半平面交所需函数及主过程=========*/

vector<Point> ConvexHull(vector<Point> p){
	sort(p.begin(),p.end());
	//删除重复点
	p.erase(unique(p.begin(),p.end()),p.end());
	int n = p.size();
	vector<Point> ch(n+1);
	int m = 0;
	for(int i=0;i<n;i++){
		while(m>1 && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])) <= 0) m--;         //若需要把边线上的点也算上，把等号去掉
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2;i>=0;i--){
		while(m > k && dcmp(Cross(ch[m-1] - ch[m-2] , p[i]-ch[m-2] )) <= 0)m--;
		ch[m++] = p[i];
	}
	if(n > 1)m--;
	ch.resize(m);
	return ch;
}
/*=============以上为凸包==========*/
double RotatingCalipers(const vector<Point>& p){
	int n = p.size();
	double ans = 0;
	Point v;
	int cur = 1;
	for(int i=0;i<n;i++){
		v = p[i]-p[(i+1)%n];
		while(dcmp(Cross(v,p[(cur+1)%n]-p[cur]))<0)
			cur = (cur+1)%n;
		ans = max(ans,max(Length(p[i]-p[cur]),Length(p[(i+1)%n]-p[(cur+1)%n])));
	}
	return ans;
}//求凸包上两点间最远距离
/*==========以上为旋转卡壳=========*/
double earthdis(Point a,Point b){
	double x1=PI*a.x/180.0;
	double y1=PI*a.y/180.0;
	double x2=PI*b.x/180.0;
	double y2=PI*b.y/180.0;
	return acos(cos(x1-x2)*cos(y1)*cos(y2)+sin(y1)*sin(y2));
}
/*=======给出经纬度，算出球体上两点之间的角度=====*/


//判断圆和直线交点,方程法
int getLineCircleIntersection(Line L, Circle C, double& t1,double& t2,vector<Point>& sol){
	double a = L.v.x, b = L.P.x-C.c.x, c = L.v.y, d = L.P.y - C.c.y;
	double e = a*a+c*c,f = 2*(a*b+c*d),g = b*b-C.r*C.r;
	double delta = f*f - 4*e*g;             //判别式
	if(dcmp(delta) < 0)return 0;              //相离
	if(dcmp(delta) == 0){                   //相切
		t1 = t2 = -f/(2*e);sol.push_back(L.point(t1));
		return 1;
	}
	//相交
	t1 = (-f - sqrt(delta)) / (2*e); sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2*e); sol.push_back(L.point(t2));
	return 2;
}
//圆和直线交点,几何法
int getLineCircleIntersection(Line L, Circle C,vector<Point>& sol){
	double d = DistanceToLine(C.c, L);
	if(dcmp(d - C.r)>0)return 0;	//相离
	Point ans = GetlineIntersection(L, Line(C.c,Normal(L.v)));
	if(dcmp(d - C.r) == 0){			//相切
		sol.push_back(ans);
		return 1;
	}
	//相交
	double len = sqrt(C.r*C.r-d*d);
	Vec v = L.v / Length(L.v);
	sol.push_back(ans + v * len),sol.push_back(ans - v * len);
	return 2;
}
//判断两圆相交
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol){
	double d = Length(C1.c-C2.c);
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
		sol.push_back(C2.c + p / Length(p) * C2.r);
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
	double dist = Length(u);
	if(dist < C.r) return 0;
	else if(dcmp(dist - C.r) == 0){
		temp = Normal(u);
		L.push_back(Line(p,temp));
		return 1;
	}else {
		double ang = asin(C.r/dist);
		temp = Rotate(u,-ang),L.push_back(Line(p,temp));
		temp = Rotate(u,+ang),L.push_back(Line(p,temp));
		return 2;
	}
}
//两圆公切线,返回切线条数，-1表示无穷多条
//注意,当两圆内切或者外切的时候,切点相同,均为p.
//sol里存的是切线，p为a上切点,p+v为b上切点
int getTangents(Circle A,Circle B,vector<Line>& sol){
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
		sol.push_back(Line(a,Normal(A.c-B.c)));
		return 1;
	}
	//有外切线
	double ang = acos((A.r-B.r) / sqrt(d2));
	a = A.point(base+ang),b = B.point(base+ang),sol.push_back(Line(a,b-a)),cnt++;
	a = A.point(base-ang),b = B.point(base-ang),sol.push_back(Line(a,b-a)),cnt++;
	if(dcmp(d2 - rsum * rsum)==0){
		a = A.point(base),b = B.point(PI + base),sol.push_back(Line(a,Normal(A.r-B.r))),cnt++;
	}else if(dcmp(d2 - rsum * rsum)>0){
		double ang2 = acos((A.r + B.r) / sqrt(d2));
		a = A.point(base+ang2),b = B.point(PI+base+ang2),sol.push_back(Line(a,b-a)),cnt++;
		a = A.point(base-ang2),b = B.point(PI+base-ang2),sol.push_back(Line(a,b-a)),cnt++;
	}
	return cnt;

}
/*==========以上为圆的常用函数及计算==========*/

//double RotatingCalipers(const vector<Point>& p){
int main(){
    int n;
    vector <Point> p;
    double tx,ty;
    while(~scanf("%d",&n)){
        p.clear();
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&tx,&ty);
            p.push_back(Point(tx,ty));
        }
        p=ConvexHull(p);
        double goal=RotatingCalipers(p);
        goal*=goal;
        printf("%.f\n",goal);
    }
	return 0;
}
