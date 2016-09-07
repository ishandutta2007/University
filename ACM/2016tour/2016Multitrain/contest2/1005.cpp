#include <bits/stdc++.h>
#define maxn 1020
using namespace std;

typedef long long llg;
typedef llg LL;

const double EPS=1e-6;
int dcmp(double x){ if (fabs(x)<EPS) return 0; else return x>0 ?1 :-1;}

struct point
{
  llg x, y;
  int p;
  point (){
    if (y==0) p=(x>0); else p=(y>0);
  }
  point(llg x, llg y):x(x),y(y){
    if (y==0) p=(x>0); else p=(y>0);
  }
  llg len(){ return x*x+y*y;}
}O;

//向量加法
point operator +(point a, point b){ return point(a.x+b.x, a.y+b.y);}
//向量减法
point operator -(point A, point B){ return point(A.x-B.x, A.y-B.y);}
//向量点积
llg operator ^(point a, point b){ return a.x*b.x+a.y*b.y;}
//向量叉积
llg operator *(point a, point b){ return a.x*b.y-a.y*b.x;}
double Ang(point a) { return atan2(a.y, a.x);}
bool operator <(point a, point b)
{
  //return dcmp(Ang(a-O)-Ang(b-O))<0;
  return ((a-O).p==(b-O).p)?((a-O)*(b-O)>0):(a-O).p<(b-O).p;
}

bool cmp(const point &a, const point &b) { //极角序
  double t = a.x*b.y-a.y*b.x;
  return t > 0 || (t==0 && a.x*a.x+a.y*a.y> b.x*b.x+b.y*b.y);
}

bool operator ==(point a, point b)
{
  return a.x==b.x && a.y==b.y;
}
LL exp(LL a, LL b, LL p)
{
  a%=p;
  LL tmp=1;
  while (b)
  {
    if (b&1) tmp=(tmp*a)%p;
    a=a*a%p;
    b=b/2;
  }
  return tmp;
}

LL rev(LL x, LL oo)
{
  if (x==1) return 1;
  else return (oo-oo/x)*rev(oo%x, oo)%oo;
}

bool online(point a, point b)
{
  return (a*b)==0 && (a^b)>=0;
}

const llg oo=1000000007;

point p[maxn], q[maxn];
int n;
llg ans;


int main()
{
  //freopen("data1.in", "r", stdin);
  int Case;
  scanf("%d",&Case);
  for (int o=1;o<=Case;o++)
  {
    int x,y;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
      scanf("%d%d",&x,&y);
      p[i].x = x;
      p[i].y = y;
      q[i] = p[i];
    }
    //cout << "hello" << endl;
    ans=0;
    O=point(0,0);
    sort(q, q + n);
    for (int i=0;i<n;i++)
    {
      if (i>0 && q[i]==q[i-1]) continue;
      O=q[i];
      sort(p, p + n);
      //cout << "hello" << endl;

      //cout<<"p: "<<O.x<<' '<<O.y<<endl;
      //for (int j=0;j<n;j++) cout<<p[j].x<<','<<p[j].y<<' '; cout<<endl;
      llg sum=1, cnt=0;
      for (int j=0;j<n;j++) if (p[j]==O) cnt++;
      //cout<<cnt<<' ';
      point v=point(1,1);

      int fst = 1;
      for (int j=0;j<n;j++)
      {
        if (p[j]==O) continue;
        //cout<<p[j].x-O.x<<' '<<p[j].y-O.y<<' ';
        //cout<<v.x<<' '<<v.y<<' ';
        if (fst)
        {
          v = p[j] - O;
          fst = 0;
          continue;
        }
        if (online(v, p[j]-O)) sum++;
        else
        {
          // printf("sum[%d]\n", sum);
          (ans+=(exp(2, cnt, oo)-1+oo)*(exp(2, sum, oo)-1+oo)%oo)%=oo;
          //cout<<": "<<ans<<' ';
          v=p[j]-O;
          sum=1;
        }
      }
      // printf("sum[%d]\n", sum);
      //cout<<": "<<ans<<endl;
      if (fst == 0) (ans+=(exp(2, cnt, oo)-1+oo)*(exp(2, sum, oo)-1+oo)%oo)%=oo;
    //    cout<<ans<<endl;
      (ans+=(2*(exp(2, cnt, oo)-1-cnt+oo)))%=oo;
    }
    //cout << "hello" << endl;

    printf("%I64d\n",ans*rev(2, oo)%oo);
  }
  return 0;
}
