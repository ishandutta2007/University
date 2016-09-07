 #include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
const double MAXN = 1000000.0;
struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vec;
//����+���� = ��������+���� = ��
Vec operator +(Vec A,Vec B){return Vec(A.x+B.x,A.y+B.y);}
//��-�� = ����
Vec operator -(Point A,Point B){return Vec(A.x-B.x,A.y-B.y);}
//����*�� = ����
Vec operator *(Vec A,double p){return Vec(A.x*p,A.y*p);}
//����/�� = ����
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
/*========ֱ�߻�������========*/
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
/*========Բ�Ļ�������========*/
struct Circle{
	Point c;
	double r;
	Circle(Point c,double r):c(c),r(r){}
	Point point(double a){
		return Point(c.x+cos(a)*r,c.y + sin(a)*r);
	}
};
/*==========����Ϊ��������============*/


double Dot(Vec A,Vec B){return A.x*B.x+A.y*B.y;}
double Length(Vec A){ return sqrt(Dot(A,A));}
//ֻ�ܾ����С���Ǹ��ǣ�
double Angle(Vec A,Vec B){return acos(Dot(A,B)/Length(A)/Length(B));}
/*==========�õ�����������Ⱥ����������н�============*/


double Cross(Vec A,Vec B){return A.x*B.y - A.y*B.x;}
//ABC���������������������
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}
//rad�ǻ��� ��ʱ����ת //ע�⣺����ԭ����ת������Ҫ��������
Vec Rotate(Vec A,double rad){
	return Vec(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
//��ʱ����ת90��ĵ�λ������
Vec Normal(Vec A){
	double L = Length(A);
	return Vec(-A.y/L,A.x/L);
}
/*=====����Ϊ����Ļ�������=====*/


//P+tv��Q+tw����ֱ�ߵĽ���,ȷ����Ψһ����
Point GetlineIntersection(Line a,Line b){
	Point P = a.P,Q = b.P;
	Vec v = a.v,w = b.v;
	Vec u = P-Q;
	double t = Cross(w,u)/Cross(v,w);
	return a.point(t);
}
//�㵽ֱ�ߵľ���
double DistanceToLine(Point P,Line a){
	Point A = a.P,B = a.P + a.v;
	Vec v1 = B-A,v2 = P-A;
	return fabs(Cross(v1,v2)/Length(v1));//��ȡ����ֵ��ô�õ������������
}
//�㵽�߶εľ���
double DistanceToSegment(Point P,Point A,Point B){
	if(A == B)return Length(P-A);
	Vec v1 = B - A, v2 = P - A, v3 = P - B;
	if(dcmp(Dot(v1,v2))<0)return Length(v2);
	else if(dcmp(Dot(v1,v3))>0) return Length(v3);
	else return fabs(Cross(v1,v2))/Length(v1);
}
//����ֱ���ϵ�ͶӰ
Point GetLineProjection(Point P,Line a){
	Point A = a.P,B = a.P + a.v;
	Vec v = B - A;
	return A + v*(Dot(v,P-A) / Dot(v,v));
}
//�ж������߶��Ƿ��ཻ �˴�����Ϊ�淶�ཻ
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
	double c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-a1);
	double c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
//�������˵��ཻ���������´��룬�ж�һ�����Ƿ���һ���߶���
bool OnSegment(Point p,Point a1,Point a2){   //���ԣ�������˵��ཻ
	if (p == a1 || p == a2) return 1;
	return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p))<0;
}
/*=========����Ϊ���ֱ�ߣ�ֱ�ߺ�ֱ�߹�ϵ������========*/
//�жϵ�Ͷ����λ�ù�ϵ
int isPointInPolygon(Point p, const vector<Point>& poly){
	int w = 0;
	int n = poly.size();
	for(int i=0;i<n;i++){
		if(OnSegment(p,poly[i],poly[(i+1)%n]))return -1;//�ڱ߽���
		int k = dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
		int d1 = dcmp(poly[i].y - p.y);
		int d2 = dcmp(poly[(i+1)%n].y - p.y);
		if(k > 0 && d1 <= 0 && d2 > 0)w++;
		if(k < 0 && d2 <= 0 && d1 > 0)w--;
	}
	if(w != 0)return 1;
	return 0;
}
//������������
double PolygonArea(vector<Point> p){
	int n = p.size();
	double area = 0;
	for(int i=1;i<n-1;i++)
		area += Cross(p[i] - p[0],p[i+1]-p[0]);
	return area/2;
}
//������ܳ�
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
/*========��������������=========*/

bool OnLeft(Line L,Point P){
	return Cross(L.v,P - L.P)>=0;          //������ϵĵ㲻��͸ĳ�>
}
int HalfplaneIntersection(Line* L,int n,Point* poly){ //L�����Ǵ�0��ʼ
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
/*=========��ƽ�潻���躯����������=========*/

vector<Point> ConvexHull(vector<Point> p){
	sort(p.begin(),p.end());
	//ɾ���ظ���
	p.erase(unique(p.begin(),p.end()),p.end());
	int n = p.size();
	vector<Point> ch(n+1);
	int m = 0;
	for(int i=0;i<n;i++){
		while(m>1 && dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])) <= 0) m--;         //����Ҫ�ѱ����ϵĵ�Ҳ���ϣ��ѵȺ�ȥ��
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
/*=============����Ϊ͹��==========*/
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
}//��͹�����������Զ����
/*==========����Ϊ��ת����=========*/
double earthdis(Point a,Point b){
	double x1=PI*a.x/180.0;
	double y1=PI*a.y/180.0;
	double x2=PI*b.x/180.0;
	double y2=PI*b.y/180.0;
	return acos(cos(x1-x2)*cos(y1)*cos(y2)+sin(y1)*sin(y2));
}
/*=======������γ�ȣ��������������֮��ĽǶ�=====*/


//�ж�Բ��ֱ�߽���,���̷�
int getLineCircleIntersection(Line L, Circle C, double& t1,double& t2,vector<Point>& sol){
	double a = L.v.x, b = L.P.x-C.c.x, c = L.v.y, d = L.P.y - C.c.y;
	double e = a*a+c*c,f = 2*(a*b+c*d),g = b*b-C.r*C.r;
	double delta = f*f - 4*e*g;             //�б�ʽ
	if(dcmp(delta) < 0)return 0;              //����
	if(dcmp(delta) == 0){                   //����
		t1 = t2 = -f/(2*e);sol.push_back(L.point(t1));
		return 1;
	}
	//�ཻ
	t1 = (-f - sqrt(delta)) / (2*e); sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2*e); sol.push_back(L.point(t2));
	return 2;
}
//Բ��ֱ�߽���,���η�
int getLineCircleIntersection(Line L, Circle C,vector<Point>& sol){
	double d = DistanceToLine(C.c, L);
	if(dcmp(d - C.r)>0)return 0;	//����
	Point ans = GetlineIntersection(L, Line(C.c,Normal(L.v)));
	if(dcmp(d - C.r) == 0){			//����
		sol.push_back(ans);
		return 1;
	}
	//�ཻ
	double len = sqrt(C.r*C.r-d*d);
	Vec v = L.v / Length(L.v);
	sol.push_back(ans + v * len),sol.push_back(ans - v * len);
	return 2;
}
//�ж���Բ�ཻ
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol){
	double d = Length(C1.c-C2.c);
	if( dcmp(C1.r - C2.r)>0)
		swap(C1,C2);
	if(dcmp(d)==0){
		if(dcmp(C1.r-C2.r)==0)return -1;//�غ�
		return 0;
	}
	if(dcmp(C1.r + C2.r -d) < 0) return 0;//����
	if(dcmp(fabs(C1.r-C2.r)-d)>0)return 0;//�ں�
	if(dcmp(C1.r + C2.r - d) == 0 || dcmp(fabs(C1.r - C2.r)-d) == 0){
		Vec p = C1.c-C2.c;
		sol.push_back(C2.c + p / Length(p) * C2.r);
		return 1;
	}//���л�����
	double a = ang(C2.c - C1.c);
	double da = acos((C1.r * C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
	Point p1 = C1.point(a-da),p2 = C1.point(a+da);
	sol.push_back(p1);
	sol.push_back(p2);
	return 2;//�ཻ
}
//����p��ԲC������
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
//��Բ������,��������������-1��ʾ�������
//ע��,����Բ���л������е�ʱ��,�е���ͬ,��Ϊp.
//sol���������ߣ�pΪa���е�,p+vΪb���е�
int getTangents(Circle A,Circle B,vector<Line>& sol){
	int cnt = 0;
	Point a,b;
	if(dcmp(A.r - B.r) < 0)swap(A,B);
	double d2 = (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y -B.c.y);
	double rdiff = A.r - B.r;
	double rsum = A.r + B.r;
	if(dcmp(d2 - rdiff * rdiff) < 0) return 0;//�ں�

	double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
	if(dcmp(d2)==0 && A.r == B.r)return -1;//�غ�,�������޶�
	if(dcmp(d2-rdiff * rdiff)==0){//���У�һ������
		a = A.point(base),b = B.point(base);
		sol.push_back(Line(a,Normal(A.c-B.c)));
		return 1;
	}
	//��������
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
/*==========����ΪԲ�ĳ��ú���������==========*/

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
