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
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define LL long long
#define scan(x) scanf("%d",x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define sqr(x) ((x)*(x))

#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
using namespace std;
#define N 1005
#define M 1000000007

#define PIIL pair<PII,LL>
#define MPP(a,b,c) MP(MP(a,b),c)
const int luck=1000007;
const int rp = 100000007;
const int rpp = 1000007;
LL po2[1005];
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL sol(int k)
{
    return (po2[k]-k-1+M)%M;
}
PIIL cal(PII a,PII b)
{
    if (b.first<a.first) swap(a,b);
    int A=b.first-a.first;
    int B=b.second-a.second;
    LL C=1LL*a.second*b.first-1LL*a.first*b.second;
    int k=gcd(B,gcd(A,C));
    A/=k,B/=k,C/=k;
    return MPP(A,B,C);
}
// vector<PIIL>e[luck];
// vector<int>hyf[luck];
int head[luck],cnt;
struct fwz
{
    int next,e;
    PIIL y;
}edge[N*N];
void add(int x,PIIL y,int e)
{
    edge[cnt].y = y;
    edge[cnt].e = e;
    edge[cnt].next = head[x];
    head[x] = cnt++;
}
struct HUSH
{
    int tot;
    void init()
    {
        tot=0;
        memset(head,-1,sizeof(head));
        cnt = 0;
        // memset(hyf,0,sizeof(hyf));
        // memset(e,0,sizeof(e));
    }
    int find(PIIL t)
    {
        LL x=t.first.first+t.first.second % rpp+t.second % rp;
        x%=luck;
        x=(x+luck)%luck;
        //rep(i,0,e[x].size())
        //if (e[x][i]==t) return hyf[x][i];
        for(int i=head[x];~i;i=edge[i].next)
        {
            PIIL y = edge[i].y;
            if(y == t) return edge[i].e;
        }
        // e[x].push_back(t);
        // hyf[x].push_back(tot++);
        add(x,t,tot++);
        return tot-1;
    }
}Hash;
map<PII,int>use;
PII a[N];
int num[N*N],sum[N],vis[N*N],tj[N];
int main()
{
    freopen("data1.in", "r", stdin);
    int T;
    po2[0]=1;
    rep(i,1,1011)
        po2[i]=po2[i-1]*2%M;
    scan(&T);
    while (T--)
    {  
        use.clear();
        Hash.init();
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        memset(tj,0,sizeof(tj));
        memset(vis,-1,sizeof(vis));
        int n=0;
        int m;
        scan(&m);
        rep(i,0,m)
        {
            PII temp;
            scanf("%d%d",&temp.first,&temp.second);
            if (use.find(temp)==use.end()) use[temp]=n++;
            a[use[temp]]=temp;
            sum[use[temp]]++;
        }
        rep(i,0,n)
        {
            rep(j,i+1,n)
            {
                PIIL t=cal(a[i],a[j]);
                int endd=Hash.tot,hh;
                if ((hh=Hash.find(t))==endd) 
                {
                    num[hh]=sum[i];
                    tj[i]++;vis[hh]=i;
                }
                //cout<<hh<<endl;
                if (vis[hh]==i) num[hh]+=sum[j],tj[j]++; 
            }
        }
        LL ans=0;
        int tot=Hash.tot;
        rep(i,0,tot)
            ans+=sol(num[i]),ans%=M;
        rep(i,0,n)
        if (sum[i]>1)
        {
            ans=ans-((tj[i]-1LL)*sol(sum[i]))%M;
            ans%=M;
        }        
        ans=(ans+M)%M;
        printf("%I64d\n",ans);
    }
    return 0;
}
