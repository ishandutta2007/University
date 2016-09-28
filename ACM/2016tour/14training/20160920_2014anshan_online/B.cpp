/*
 *******************************
 * author :   poore            *
 * mail   :   py100c@gmail.com *
 * from   :   Chongqing, China *
 *******************************
 */

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template <class T>
inline void RD(T &x) {
  char c=getchar(); 
  x=0;
  while(!isdigit(c))
    c=getchar();
  while(isdigit(c)){ 
    x=x*10+c-'0';
    c=getchar(); 
  }
}
const int oo = 1e9+7;
const int maxn = 20;

typedef pair<double, double> pdd;

pdd p[maxn];
double d[maxn];
int n;

const double eps = 1e-9;

int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0? -1:1;
}

pdd operator - (pdd a, pdd b) {
  return pdd(a.X-b.X, a.Y-b.Y);
}

pdd operator + (pdd a, pdd b) {
  return pdd(a.X+b.X, a.Y+b.Y);
}

pdd operator / (pdd a, double b) {
  return pdd(a.X/b, a.Y/b);
}

double operator * (pdd a, pdd b) {
  return a.X*b.X+a.Y*b.Y;
}

pdd operator * (pdd a, double b) {
  return pdd(a.X*b, a.Y*b);
}

double operator ^ (pdd a, pdd b) {
  return a.X*b.Y-a.Y*b.X;
}


pdd go(pdd A, int i, double theta) {
  A = A - p[i];
  pdd ret = pdd(A.X*cos(theta)-A.Y*sin(theta), A.X*sin(theta)+A.Y*cos(theta)) + p[i];
  return ret;
}

void show(pdd PP) {
  printf("(%.5f %.5f)\n", PP.X, PP.Y);
}

pdd V[2];
pdd P[2];

pdd cr() {
  pdd u = P[0]-P[1];
  double t = (V[1]^u)/(V[0]^V[1]);
  pdd tmp = P[0] + V[0]*t;
  return tmp;
}

const double PI = acos(-1.0);

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("data.in", "r", stdin);
  #endif
  
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf%lf", &p[i].X, &p[i].Y, &d[i]);
    }
    pdd ps1 = pdd(200.0,1000.0);
    pdd ps2 = pdd(1000.0,200.0);
    pdd pe1 = ps1;
    pdd pe2 = ps2;
    pdd mid1 = (ps1+ps2)/2.0;
    for (int i = 1; i <= n; i++) {
      pe1 = go(pe1, i, d[i]);
      pe2 = go(pe2, i, d[i]);
      //show(pe1);
      //show(pe2);
      //cout << "---" << endl;
    }
    pdd mid2 = (pe1+pe2)/2.0;
    pdd tmp;
    P[0] = (ps1+pe1)/2.0;
    tmp = ps1-pe1;
    V[0] = pdd(-tmp.Y, tmp.X);
    
    //show(P[0]);
    //show(V[0]);
    P[1] = (ps2+pe2)/2.0;
    tmp = ps2-pe2;
    V[1] = pdd(-tmp.Y, tmp.X);
    //show(P[1]);
    //show(V[1]);

    pdd ans = cr();
    
    mid1 = ps1-ans;
    ps1 = ps1-ans;
    pe1 = pe1-ans;
    /*
    show(ps1);
    show(ps2);
    */
    double costheta = (ps1*pe1)/(sqrt(ps1*ps1)*sqrt(pe1*pe1));
    double aa = acos(costheta);
    if ((pe1^ps1) > 0) aa = 2*PI - aa;
    printf("%.8f %.8f %.8f\n", ans.X, ans.Y, aa);
  }
  return 0;
}

