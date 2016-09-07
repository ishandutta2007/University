#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <map>
#include <bitset>
#include <ctime>
#define lson (p<<1)
#define rson (lson | 1)
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define LL long long
#define ULL unsigned long long
#define scan(x) scanf("%d",x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define MP make_pair
#define sqr(x) ((x)*(x))
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
using namespace std;
#define N 111
#define M 110119
// LL exp_mod(LL a, LL b, LL p) {
//     LL res = 1;
//     while(b != 0) {
//         if(b&1) res = (res * a) % p;
//         a = (a*a) % p;
//         b >>= 1;
//     }
//     return res;
// }

// LL Comb(LL a, LL b, LL p) {
//     if(a < b)   return 0;
//     if(a == b)  return 1;
//     if(b > a - b)   b = a - b;

//     LL ans = 1, ca = 1, cb = 1;
//     for(LL i = 0; i < b; ++i) {
//         ca = (ca * (a - i))%p;
//         cb = (cb * (b - i))%p;
//     }
//     ans = (ca*exp_mod(cb, p - 2, p)) % p;
//     return ans;
// }

// LL Lucas(LL n, LL m, LL p) {
//      LL ans = 1;
//      while(n&&m&&ans) {
//         ans = (ans*Comb(n%p, m%p, p)) % p;
//         n /= p;
//         m /= p;
//      }
//      return ans;
// }
LL PowMod(LL a,LL b,LL MOD){  
    LL ret=1;  
    while(b){  
        if(b&1) ret=(ret*a)%MOD;  
        a=(a*a)%MOD;  
        b>>=1;  
    }  
    return ret;  
}  
LL fac[M+10];  
LL Get_Fact(LL p){  
    fac[0]=1;  
    for(LL i=1;i<=p;i++)  
        fac[i]=(fac[i-1]*i)%p;  //预处理阶乘 
}  
LL Lucas(LL n,LL m,LL p){  
    LL ret=1;  
    while(n&&m){  
        LL a=n%p,b=m%p;  
        if(a<b) return 0;  
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2,p))%p;  
        n/=p;  
        m/=p;  
    }  
    return ret;  
}  
LL cal(LL n,LL m)
{
    LL x,y;
    if ((2*n-m)<0||(2*n-m)%3||(2*m-n)%3||(2*m-n)<0) return 0;
    x=(2*n-m)/3;y=(2*m-n)/3;
    return Lucas(x+y,x,M);
}
LL n,m;
int r;
PLL a[N];
LL fz[N][N];
LL ans[N];
LL sub(LL x,LL y)
{
    return ((x-y)%M + M) % M; 
}
int main()
{
    //cout<<(Lucas(1LL,2LL,M) )<<endl;
    //biao();
    Get_Fact(M);
    int top = 0;
    while(~scanf("%I64d%I64d%d",&n,&m,&r) )
    {
        rep(i,0,r)
            scanf("%I64d%I64d",&a[i].first,&a[i].second);
        a[r].first=1,a[r++].second=1;
        a[r].first=n,a[r++].second=m;
        sort(a,a+r);
        rep(i,0,r)
            rep(j,i+1,r)
            fz[i][j]=cal(a[j].first-a[i].first,a[j].second-a[i].second);
        for(int i=1;i<r;i++)
        {
            ans[i] = fz[0][i];
            //cout<<ans[i]<<endl;
        }
        for(int i=1;i<r;i++)
        {
            for(int j=i+1;j<r;j++)
            {
                ans[j] = sub(ans[j],ans[i]*fz[i][j]);
            }
        }
        printf("Case #%d: %I64d\n",++top,ans[r-1]);
        // f[0][0]=1;//0  ji
        // f[0][1]=0;//1  ou
        // rep(i,0,r)
        //     rep(j,0,i)
        //     if (a[j].first<a[i].first&&a[j].second<a[i].second)
        //     {
        //         f[i][0]=f[i][0]*f[j][1]*fz[i][j]%M;
        //         f[i][1]=f[i][1]*f[j][0]*fz[i][j]%M;
        //     }
    }
    return 0;
}   
/*
*/
