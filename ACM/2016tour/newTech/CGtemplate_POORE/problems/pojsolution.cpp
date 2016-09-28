#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<iomanip> 
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
#include<complex>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
    return x*f;
} 
ll sqr(ll a){return a*a;}
ld sqr(ld a){return a*a;}
const double eps=1e-10;
int dcmp(double x) {
    if (fabs(x)<eps) return 0; else return x<0 ? -1 : 1; 
}
ld PI = acos(-1.0);
class P{
public:
    double x,y;
    P(double x=0,double y=0):x(x),y(y){}
    friend ld dis2(P A,P B){return sqr(A.x-B.x)+sqr(A.y-B.y);   }
    friend ld Dot(P A,P B) {return A.x*B.x+A.y*B.y; }
    friend ld Length(P A) {return sqrt(Dot(A,A)); }
    friend ld Angle(P A,P B) {
        if (dcmp(Dot(A,A))==0||dcmp(Dot(B,B))==0||dcmp(Dot(A-B,A-B))==0) return 0;
        return acos(max((ld)-1.0, min((ld)1.0, Dot(A,B) / Length(A) / Length(B) )) ); 
    }

    friend P operator- (P A,P B) { return P(A.x-B.x,A.y-B.y); }
    friend P operator+ (P A,P B) { return P(A.x+B.x,A.y+B.y); }
    friend P operator* (P A,double p) { return P(A.x*p,A.y*p); }
    friend P operator/ (P A,double p) { return P(A.x/p,A.y/p); }
    friend bool operator< (const P& a,const P& b) {return dcmp(a.x-b.x)<0 ||(dcmp(a.x-b.x)==0&& dcmp(a.y-b.y)<0 );}

}; 
P read_point() {
    P a;
    scanf("%lf%lf",&a.x,&a.y);
    return a;   
} 
bool operator==(const P& a,const P& b) {
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y) == 0;
} 
typedef P V;

double Cross(V A,V B) {return A.x*B.y - A.y*B.x;}
double Area2(P A,P B,P C) {return Cross(B-A,C-A);}
namespace complex_G{
    typedef complex<double> Point;
    //real(p):实部 imag(p):虚部 conj(p):共轭 
    typedef Point Vector;
    double Dot(Vector A,Vector B) {return real(conj(A)*B); }
    double Cross(Vector A,Vector B) {return imag(conj(A)*B); }
    Vector Rotate(Vector A,double rad) {return A*exp(Point(0,rad)); }
}
//Cross(v,w)==0(平行)时,不能调这个函数 
P GetLineIntersection(P p,V v,P Q,V w){
    V u = p-Q;
    double t = Cross(w,u)/Cross(v,w);
    return p+v*t;
}
P GetLineIntersectionB(P p,V v,P Q,V w){
    return GetLineIntersection(p,v-p,Q,w-Q);
}

double DistanceToLine(P p,P A,P B) {
    V v1 = B-A, v2 = p-A;
    return fabs(Cross(v1,v2))/Length(v1);
}
double DistanceToSegment(P p,P A,P B) {
    if (A==B) return Length(p-A);
    V v1 = B-A, v2 = p-A, v3 = p - B;
    if (dcmp(Dot(v1,v2))<0) return Length(v2);
    else if (dcmp(Dot(v1,v3))>0 ) return Length(v3);
    else return fabs(Cross(v1,v2) ) / Length(v1);
}
P GetLineProjection(P p,P A,P B) {
    V v=B-A;
    return A+v*(Dot(v,p-A)/Dot(v,v));
}
//规范相交-线段相交且交点不在端点 
bool SegmentProperIntersection(P a1,P a2,P b1,P b2) { 
    double  c1 = Cross(a2-a1,b1-a1) , c2 = Cross(a2-a1,b2-a1),
            c3 = Cross(b2-b1,a1-b1) , c4 = Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
//点在线段上（不包含端点） 
bool OnSegment(P p,P a1,P a2) {
    return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p))<0;
}
double PolygonArea(P *p,int n) {
    double area=0;
    For(i,n-2) area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
} 
/*欧拉公式： V+F-E=2 
V-点数 F面数 E边数 */
struct C{
    P c;
    double r,x,y;
    C(P c,double r):c(c),r(r),x(c.x),y(c.y){}
    P point(double a) {
        return P(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};

struct Line{
    P p;
    V v;
    double ang;
    Line(){}
    Line(P p,V v):p(p),v(v) {ang=atan2(v.y,v.x); }
    bool operator<(const Line & L) const {
        return ang<L.ang;
    }
    P point(double a) {
        return p+v*a;
    }
};
int getLineCircleIntersection(Line L,C cir,double &t1,double &t2,vector<P> & sol) {
    if (dcmp(DistanceToLine(cir.c,L.p,L.p+L.v)-cir.r)==0) {
        P A=GetLineProjection(cir.c,L.p,L.p+L.v);
        sol.pb(A); 
        t1 = (A-L.p).x / L.v.x;  
        return 1;
    }

    double a = L.v.x, b = L.p.x - cir.c.x, c = L.v.y, d= L.p.y - cir.c.y;
    double e = a*a+c*c, f = 2*(a*b + c*d), g = b*b+d*d-cir.r*cir.r;
    double delta = f*f - 4*e*g;
    if (dcmp(delta)<0) return 0;
    else if (dcmp(delta)==0) {
        t1 = t2 = -f / (2*e); sol.pb(L.point(t1));
        return 1;
    } 
    t1 = (-f - sqrt(delta)) / (2*e); sol.pb(L.point(t1));
    t2 = (-f + sqrt(delta)) / (2*e); sol.pb(L.point(t2));
    return 2;
}
double angle(V v) {return atan2(v.y,v.x);}

int getSegCircleIntersection(Line L,C cir,vector<P> & sol) {
    if (dcmp(DistanceToLine(cir.c,L.p,L.p+L.v)-cir.r)==0) {
        P A= GetLineProjection(cir.c,L.p,L.p+L.v);
        if (OnSegment(A,L.p,L.p+L.v) || L.p==A || L.p+L.v==A  ) 
            sol.pb(A);
        return sol.size();
    }
    double t1,t2;
    double a = L.v.x, b = L.p.x - cir.c.x, c = L.v.y, d= L.p.y - cir.c.y;
    double e = a*a+c*c, f = 2*(a*b + c*d), g = b*b+d*d-cir.r*cir.r;
    double delta = f*f - 4*e*g;
    if (dcmp(delta)<0) return 0;
    else if (dcmp(delta)==0) {
        t1 = -f / (2*e); 
        if (dcmp(t1)>=0&&dcmp(t1-1)<=0) {
            sol.pb(L.point(t1));
        }
        return sol.size();
    } 
    t1 = (-f - sqrt(delta)) / (2*e); if (dcmp(t1)>=0&&dcmp(t1-1)<=0) sol.pb(L.point(t1));
    t2 = (-f + sqrt(delta)) / (2*e); if (dcmp(t2)>=0&&dcmp(t2-1)<=0) sol.pb(L.point(t2));
    if(SI(sol)==2 && t1>t2) swap(sol[1],sol[0]);
    return sol.size();
}
int isPointInOrOnCircle(P p,C c) {
    return dcmp(Length(p-c.c)-c.r)<=0;
}

// Triangle(O,A,B) and Circle(O,m)
double CircleTriangleArea(P A,P B,double m) {
    double ans=0;
    C c=C(P(),m); P O=c.c;
    if (A==O||B==O) return 0;
    bool b = isPointInOrOnCircle(A,c);
    bool b2 = isPointInOrOnCircle(B,c);
    double opr;
    if (dcmp(Area2(O,A,B))>=0) opr=1; else opr=-1;
    if (b&&b2) {
        ans+=opr*fabs(Area2(A,B,O))/2; 
    } else if (!b&&!b2){
        Line l=Line(A,B-A);
        vector<P> sol;
        getSegCircleIntersection(l,c,sol);
        if (SI(sol)==2) {
            ans+=opr*fabs(Area2(sol[0],sol[1],O))/2;
            ans+=opr*m*m/2*(Angle(A,sol[0])+Angle(sol[1],B));
        } else {
            ans+=opr*m*m/2*(Angle(A,B));
        }
    } else {
        Line l=Line(A,B-A);
        vector<P> sol;
        getSegCircleIntersection(l,c,sol);
        if (SI(sol)==2) {
            ans+=opr*fabs(Area2(sol[0],sol[1],O))/2;
            ans+=opr*m*m/2*(Angle(A,sol[0])+Angle(sol[1],B));
        } else if(b) { 
            ans+=opr*fabs(Area2(sol[0],A,O))/2;
            ans+=opr*m*m/2*(Angle(sol[0],B));
        } else {
            ans+=opr*fabs(Area2(sol[0],B,O))/2;
            ans+=opr*m*m/2*(Angle(sol[0],A));
        }
    }
    return ans;
}
P a[10000];
int main()
{
//  freopen("poj2986.in","r",stdin);
//  freopen(".out","w",stdout);
  //freopen("in.txt", "r", stdin);
  freopen("data.in", "r", stdin);
  freopen("out1.txt", "w", stdout);
    double R;
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a[0].x,&a[0].y,&a[1].x,&a[1].y,&a[2].x,&a[2].y,&a[3].x,&a[3].y,&R)) {
        double ans=0;
        Rep(i,3) {
            double tmp=CircleTriangleArea(a[i]-a[3],a[(i+1)%3]-a[3],R);
          //printf("tmp = %.4f\n", tmp);
          ans += tmp;
        }
        printf("%.2f\n",fabs(ans));
    }
    return 0;
}
