#include <bits/stdc++.h>
#define LL long long
template <class T>
inline void rd(T &x) { char c = getchar(); x = 0;while(!isdigit(c)) c = getchar();
while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }}
template <class T> void Out(T a) { if(a < 0){putchar('-');a = -a;}if(a >= 10)Out(a / 10);putchar(a % 10 + '0');  }
using namespace std;
const int N=100100;
queue <LL> q1,q2;
LL v[N];
LL n,m;
LL inf;
bool Judge(int k)
{
    int be,x,y;
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
    LL tmp=0;
    LL ans=0;
    for (int i=1;i<=n;i++)
        q1.push(v[i]);
    be=(n-1)%(k-1);
    if(be)
    {
        for (int i=1;i<=be;i++)
        {
            x=q1.front();
            q1.pop();
            tmp+=x;
        }
        ans+=tmp;
        q2.push(tmp);
    }

    for (int i=1;i<=(n-1)/(k-1);i++)
    {
        tmp=0;
        for (int j=1;j<=k;j++)
        {
            if (!q1.empty()) x=q1.front();
            else x=inf;

            if (!q2.empty()) y=q2.front();
            else y=inf;

            if (x<y) {tmp+=x;q1.pop();}
            else {tmp+=y;q2.pop();}
        }
        ans+=tmp;
        if (ans>m) return 0;
        q2.push(tmp);
    }
    return 1;
}
int main()
{
    int t,l,r,mid;
    int ans;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        inf=m+1;
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        sort(v+1,v+1+n);

        l=2;r=n;ans=n;
        while (l<=r)
        {
            mid=(l+r)/2;
            if (Judge(mid))
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
