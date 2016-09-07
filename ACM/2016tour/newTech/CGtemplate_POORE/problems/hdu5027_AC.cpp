#include <bits/stdc++.h>

using namespace std;

const double eps=1e-4;
const double INF = 1e16;
const int maxn = 50000+10;
double sumL[maxn],sumR[maxn];
double Ts,Vr,Vs;
int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    else if(x < 0) return -1;
    else return 1;
}
struct Point{
    double x,y;
    Point(double x0=0,double y0=0){
        x=x0,y=y0;
    }
    friend bool operator < (Point a,Point b){
        if(a.y!=b.y) return a.y<b.y;
        else return a.x<b.x;
    }
};

Point Poly[maxn],cur,targ;
int n;
typedef Point Vector;
double MinToLandT,ans;
inline Vector operator + (Vector A,Vector B) { return Vector(A.x+B.x,A.y+B.y); }
Vector operator - (Vector A,Vector B) { return Vector(A.x-B.x,A.y-B.y); }
Vector operator * (Vector A,double p) { return Vector(A.x*p,A.y*p); }
Vector operator / (Vector A,double p) { return Vector(A.x/p,A.y/p); }
bool operator == (const Point &a,const Point &b) { return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0 ; }
inline double sqr(double x) {
    return x*x;
}
double Dot(Vector A,Vector B){ return A.x*B.x+A.y*B.y; }
double Length(Vector A){ return sqrt(Dot(A,A)); }
double Angle(Vector A,Vector B){ return acos(Dot(A,B)/Length(A)/Length(B)); }
double Cross(Vector A,Vector B){ return A.x*B.y-A.y*B.x; }
Vector Rotate(Vector A,double rad){ return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad)); }
double torad(double ang){ return ang/180.0*acos(-1.0); }

void circle_cross_line(Point a,Point b,Point o,double r,Point ret[],int &num) {
    double x0 = o.x ,y0 = o.y;
    double x1 = a.x, y1 = a.y;
    double x2 = b.x, y2 = b.y;
    double dx = x2-x1, dy = y2-y1;
    double A = dx*dx+dy*dy;
    double B = 2*dx*(x1-x0) + 2*dy*(y1-y0);
    double C = sqr(x1-x0) + sqr(y1-y0)-sqr(r);
    double delta = B*B-4*A*C;
    num = 0;
    if( dcmp(delta) >= 0) {
        double t1 = (-B - sqrt(delta)) / (2*A);
        double t2 = (-B + sqrt(delta)) / (2*A);
        ret[num++] = Point(x1+t1*dx,y1+t1*dy);
        ret[num++] = Point(x1+t2*dx,y1+t2*dy);
    }
}
double DistanceToSegment(Point P,Point A,Point B){
    if(A==B) return Length(P-A);
    Vector v1=B-A,v2=P-A,v3=P-B;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}
double targetT(Point t,Point st) {
    if(dcmp(Length(t-targ)/Vs-Ts+MinToLandT) > 0) return INF;
    else return Length(t-st)/Vr+Length(t-targ)/Vs;

}
bool cmp(Vector a,Vector b) {
    if(dcmp(Cross(b , a)) > 0) return true;
    else if(dcmp(Cross(b,a))== 0) return abs(a.x) < abs(b.x);
    return false;
}

void show(Point tmp)
{
  printf("(%.4f, %.4f)\n", tmp.x, tmp.y);
}
void input() {
    scanf("%lf%lf%lf",&Ts,&Vr,&Vs);
    scanf("%lf%lf",&cur.x,&cur.y);
    scanf("%lf%lf",&targ.x,&targ.y);
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf",&Poly[i].x,&Poly[i].y);
    }
    Vector t1 = Poly[0]-Poly[1];
    Vector t2 = Poly[2]-Poly[1];
    if(dcmp(Cross(t1,t2)) > 0) {
        reverse(Poly,Poly+n);
    }
    MinToLandT = INF;
    for(int i = 0; i < n; i++) {
        MinToLandT = min(MinToLandT,DistanceToSegment(targ,Poly[i],Poly[(i+1)%n])*2/Vs);
    }
}
double thi_Search(Point p0 , Point p1, Point st){
    Point l = p0 , r = p1;
    while(Length(l-r) > eps){
        Point lmid = (l*2+r)/3 , rmid = (l+r*2)/3;
        if(targetT(lmid , st ) < targetT(rmid , st )) r = rmid;
        else l = lmid;
    }
    printf("==========\n");
    show(p0);
    show(p1);
    show(st);
    show((l+r)/2);
    printf("==========\n");

    return targetT((l+r)/2 , st);
}

void init(int Lid,int Rid) {
    sumR[Rid] = Length(cur-Poly[Rid]);
    for(int i = (Rid+1)%n; i != Lid; i = (i+1)%n) {
        int before = (i-1+n)%n;
        sumR[i] = sumR[before] + Length(Poly[before]-Poly[i]);
    }
    sumL[Lid] = Length(cur-Poly[Lid]);
    for(int i = (Lid-1+n)%n; i != Rid; i = (i-1+n)%n) {
        int before = (i+1)%n;
        sumL[i] = sumL[before] + Length(Poly[before]-Poly[i]);
    }
}
bool PointOnSegment(Point o,Point a,Point b) {//o on segment (a,b)
    if(a.x > b.x) swap(a,b);
    return (dcmp(b.x-o.x) >= 0 && dcmp(o.x-a.x) >= 0);
}
void solve() {
    if(Ts < MinToLandT ) {
        puts("-1");
        return;
    }
    Vector vec[maxn];
    for(int i = 0; i < n; i++) {
        vec[i] = Poly[i]-cur;
    }
    sort(vec,vec+n,cmp);
    ans = INF;
    int Lid = 0,Rid = 0;
    Point L = vec[0]+cur,R;
    if(dcmp(Angle(vec[n-1],vec[n-2]))==0) R = vec[n-2]+cur;
    else R = vec[n-1]+cur;
    for(int i = 0; i < n; i++) {
        if(R==Poly[i]) Rid = i;
        if(L==Poly[i]) Lid = i;
    }
    init(Lid,Rid);
    for(int i = Lid; i != Rid; i = (i+1)%n) {
        Point o = targ;
        Point ret[2];
        int num;
        double r = (Ts-MinToLandT)*Vs;
        Point a = Poly[i],b = Poly[(i+1)%n];
        if(a.x > b.x) swap(a,b);
        circle_cross_line(a,b,o,r,ret,num);
        if(num==0) continue;
        if(num==1) {
            Point t = ret[0];
            if(PointOnSegment(t,a,b)) {
                ans = min(ans,Length(t-cur));
            }
        }else{
            Point ep1,ep2;
            if(PointOnSegment(a,ret[0],ret[1])) {
                ep1 = a;
            }else{
                ep1 = ret[0];
            }
            if(PointOnSegment(b,ret[0],ret[1])) {
                ep2 = b;
            }else{
                ep2 = ret[1];
            }
            ans = min(ans,thi_Search(ep1 , ep2 , cur));
        }
    }
    printf("mid ans = %.4f\n", ans);
    for(int i = Rid; i != Lid; i = (i+1)%n) {
        Point o = targ;
        Point ret[2];
        int num;
        double r = (Ts-MinToLandT)*Vs;
        Point a = Poly[i],b = Poly[(i+1)%n];
        if(a.x > b.x) swap(a,b);
        circle_cross_line(a,b,o,r,ret,num);
        double tmp1,tmp2;
        if(num==0) continue;
        if(num==1) {
            Point t = ret[0];
            if(PointOnSegment(t,a,b)) {
                tmp1 = sumL[(i+1)%n] + Length(t-b);
                tmp2 = sumR[i]+Length(t-a);
            }
        }else{
            Point ep1,ep2;
            if(PointOnSegment(a,ret[0],ret[1])) {
                ep1 = a;
            }else{
                ep1 = ret[0];
            }
            if(PointOnSegment(b,ret[0],ret[1])) {
                ep2 = b;
            }else{
                ep2 = ret[1];
            }
            tmp1 = sumL[(i+1)%n]/Vr+thi_Search(ep1 , ep2 , Poly[(i+1)%n]);
            tmp2 = sumR[i]/Vr+thi_Search(ep1 , ep2 , Poly[i]);
        }

        ans = min(tmp1,ans);
        ans = min(tmp2,ans);
    }
    ans += MinToLandT;
    if(ans >= INF) {
        puts("-1");
    }else{
        printf("%.2lf\n",ans);
    }
}
int main() {
  freopen("data.in", "r", stdin);
    int ncase;
    cin >> ncase;
    while(ncase--) {
        input();
        solve();
    }
    return 0;
}
