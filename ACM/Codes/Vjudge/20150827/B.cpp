#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


const double PI = acos(-1.0);
const double MAXN = 1000000.0;
const double EPS = 1e-10;
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vec;
Vec operator +(Vec A,Vec B){return Vec(A.x+B.x,A.y+B.y);}
Vec operator -(Point A,Point B){return Vec(A.x-B.x,A.y-B.y);}
Vec operator *(Vec A,double p){return Vec(A.x*p,A.y*p);}
Vec operator /(Vec A,double p){return Vec(A.x/p,A.y/p);}
bool operator <(const Point& a,const Point& b){
    return a.x<b.x || (a.x == b.x && a.y<b.y);
}
int dcmp(double x){
    if(fabs(x)<EPS) return 0;else return x<0? -1: 1;
}
bool operator == (const Point& a,const Point &b){
    return dcmp(a.x-b.x)==0 &&dcmp(a.y-b.y) == 0;
}
//ang return the angle between v and x+ in rad
double ang(Vec v){return atan2(v.y,v.x);}
//Point, Vector
//Basic operations
//attention to the conversion from Point to Vector

//Def of Line
struct Line{
    Point P;
    Vec v;
    double ang;
    Line(){}
    Line(Point P,Vec v):P(P),v(v){ang  = atan2(v.y,v.x);}
    bool operator < (const Line& L) const {
        return ang < L.ang;
    }
    //point return a Point on this Line calculated by t
    //t is memtioned below
    //t ???
    Point point(double a){
        return P+v*a;
    }
};
//Def of Circle
struct Circle{
    Point c;
    double r;
    Circle(Point c,double r):c(c),r(r){}
    Point point(double a){
        return Point(c.x+cos(a)*r,c.y + sin(a)*r);
    }
};
/***********************************
*********end of basic def***********
***********************************/

//Vector operations
double Dot(Vec A,Vec B){return A.x*B.x+A.y*B.y;}
double Length(Vec A){ return sqrt(Dot(A,A));}
double Angle(Vec A,Vec B){return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vec A,Vec B){return A.x*B.y - A.y*B.x;}

//Area2 return sighed area of ABC
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}

//Rotate return a Vector rotated by rad
//counterclockwise
Vec Rotate(Vec A,double rad){
    return Vec(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
//UnitNormal return the unit normal vector of A AFTER ROTATE 90°
//counterclockwise
Vec UnitNormal(Vec A){
    double L = Length(A);
    return Vec(-A.y/L,A.x/L);
}


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
    else if(dcmp(Dot(v1,v3)>0)) return Length(v3);
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
bool OnSegment(Point p,Point a1,Point a2){
    return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p))<0;
}
/*=========以上为点和直线，直线和直线关系的内容========*/


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
Point GetIntersection(Line a, Line b){
    Vec u = a.P - b.P;
    double t = Cross(b.v,u)/Cross(a.v,b.v);
    return a.P+a.v*t;
}
int HalfplaneIntersection(Line* L,int n,Point* poly){
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
        if(first<last) p[last-1] = GetIntersection(q[last-1],q[last]);
    }
    while(first<last && !OnLeft(q[first],p[last-1]))last -- ;
    if(last-first<=1)return 0;
    p[last] = GetIntersection(q[last],q[first]);
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
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0) m--;         //若需要把边线上的点也算上，把等号去掉
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2;i>=0;i--){
        while(m > k && Cross(ch[m-1] - ch[m-2] , p[i]-ch[m-2] ) <= 0)m--;
        ch[m++] = p[i];
    }
    if(n > 1)m--;
    ch.resize(m);
    return ch;
}
/*=============以上为凸包==========*/

double earthdis(Point a,Point b){
    double x1=PI*a.x/180.0;
    double y1=PI*a.y/180.0;
    double x2=PI*b.x/180.0;
    double y2=PI*b.y/180.0;
    return acos(cos(x1-x2)*cos(y1)*cos(y2)+sin(y1)*sin(y2));
}
//x as longtitude, y as latitude
/*=======给出经纬度，算出球体上两点之间的角度=====*/


//判断圆和直线交点
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
//判断两圆相交
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol){
    double d = Length(C1.c-C2.c);
    if(dcmp(d)==0){
        if(dcmp(C1.r-C2.r)==0)return -1;//重合
        return 0;
    }
    if(dcmp(C1.r + C2.r -d) < 0) return 0;
    if(dcmp(fabs(C1.r-C2.r)-d)>0)return 0;

    double a = ang(C2.c - C1.c);
    double da = acos((C1.r * C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
    Point p1 = C1.point(a-da),p2 = C1.point(a+da);

    sol.push_back(p1);
    if(p1 == p2)return 1;
    sol.push_back(p2);
    return 2;
}
//过点p到圆C的切线
int getTangents(Point p,Circle C,vector<Line> L){
    Vec u = C.c - p , temp;
    double dist = Length(u);
    if(dist < C.r) return 0;
    else if(dcmp(dist - C.r) == 0){
        temp = Rotate(u,PI/2);
        L.push_back(Line(p,temp));
        return 1;
    }else {
        double ang = asin(C.r/dist);
        temp = Rotate(u,-ang),L.push_back(Line(p,temp));
        temp = Rotate(u,+ang),L.push_back(Line(p,temp));
        return 2;
    }
}
/*==========以上为圆的常用函数及计算==========*/

#define Rearth 6371009
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r",stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int ka = 1;
    int a, b;
    while(scanf("%d : %d", &a, &b) != EOF)
    {
        Vec v1, v2;
        v1 = Point(a, b);
        v2 = Point(a, -b);
        double theta = Angle(v1, v2);
        cout << theta << endl;
        double d = sqrt(a*a + b*b);

        double x = 400.0 / (a*2 + PI * d * theta / PI);

        // printf("%lf\n", theta);
        printf("Case %d: %.8lf %.8lf\n", ka++, x * a, x * b);
    }

    return 0;
}
