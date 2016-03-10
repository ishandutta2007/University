/*

题目：给出数轴上的n个城市的位置，然后给出每个城市的人数，现在需要建一
个TV站。不和谐度 = sigma(每个城市与TV站的距离 * 该城市人数)。现在问如何
选取这个TV站的位置，使得不和谐度最小。

分析：越靠近最好的位置，不和谐度更小。所以我们可以用三分迭代的方式来选
取该位置。

*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define debug puts("here")
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define foreach(i,vec) for(unsigned i=0;i<vec.size();i++)
#define pb push_back
#define RD(n) scanf("%d",&n)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)

const int MAXN = 15005;
const double eps = 1e-8;

int a[MAXN],b[MAXN];
int n;

double solve(double pos){
    double ans = 0;
    rep1(i,n)
        ans += fabs(a[i]-pos)*b[i];
    return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("sum.in","r",stdin);
	//freopen("sum.out","w",stdout);
#endif

    double l = 500000,r = 0;
    cin>>n;
    rep1(i,n){
        cin>>a[i]>>b[i];
        if(a[i]>l)
            l = a[i];
        if(a[i]<r)
            r = a[i];
    }

    double R = r,L = l;
    l = 0,r = 1;
    double ans = 1e15;
    double pos = 0;
    rep(step,1000){ // 浮点数建议以迭代次数为1000替代判断边界相等
        double M1 = (2*l+r)/3;
        double M2 = (l+2*r)/3;
        double x1 = M1*L+(1-M1)*R;
        double x2 = M2*L+(1-M2)*R;
        double tmp = solve(x1);
        double ret = solve(x2);
        if(tmp+eps<ans){
            ans = tmp;
            pos = x1;
        }
        if(ret+eps<ans){
            ans = ret;
            pos = x2;
        }
        if(tmp-ret>eps)
            l = M1;
        else
            r = M2;
    }
    printf("%.5lf\n",pos);

	return 0;
}
