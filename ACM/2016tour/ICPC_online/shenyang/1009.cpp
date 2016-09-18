#include <bits/stdc++.h>
#define LL long long
template <class T>
inline void rd(T &x) { char c = getchar(); x = 0;while(!isdigit(c)) c = getchar();
while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }}
template <class T> void Out(T a) { if(a < 0){putchar('-');a = -a;}if(a >= 10)Out(a / 10);putchar(a % 10 + '0');  }
using namespace std;
const int N=1e5;
LL Gcd(LL x,LL y)
{
    if (x%y==0) return y;
    else return Gcd(y,x%y);
}
LL dp[500][500];
LL sum[1000],v[1000],k[1000];
LL num[1000];
LL ans,tmp,g;
int t,n;
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        num[0]=0;
        for (int i=1;i<=n;i++)
            scanf("%I64d",&k[i]);

        for (int i=1;i<=n;i++)
        {
            scanf("%I64d",&v[i]);
            num[i]=num[i-1]+v[i];
        }

        for (int i=0;i<=n;i++)
        {
            sum[i]=0;
            dp[i][0]=0;
        }

        ans=0;
        for (int i=2;i<=n;i++)
        {
            sum[i]=sum[i-1];
            for (int j=1;j<i;j+=2)
            {
                if (j>2 && dp[i-1][j-2]==-1) continue;
//                if (k[i]==1 || k[i-j]==1) continue;
                g=Gcd(max(k[i],k[i-j]),min(k[i],k[i-j]));
                if(g==1) continue;

                tmp=sum[i-j-1]+num[i]-num[i-j-1];

                dp[i][j]=max(dp[i][j],tmp);
                ans=max(ans,dp[i][j]);
                sum[i]=max(sum[i],dp[i][j]);
//                cout<<" i="<<i<<" j="<<j<<' '<<dp[i][j]<<' '<<sum[i-j-1]<<endl;
            }
        }

        printf("%I64d\n",ans);
    }
    return 0;
}
/*
100
6
2 2 4 4 2 2
1 2 3 3 2 1
*/
