#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define inf 1000000007
#define maxn 220000
#define maxm 4200

using namespace std;

int f[maxn][2],a[maxn],c[maxn];
int n,m;

struct bit
{
    int b[maxn];
    int num;
    void add(int x,int z)
    {
        for (int i=x;i<=num;i+=(i&-i)) b[i]=max(b[i],z);
    }
    int ask(int x)
    {
        int tmp=0;
        for (int i=x;i;i-=(i&-i)) tmp=max(tmp,b[i]);
        return tmp;
    }
    void clear(int n)
    {
        num=n;
        memset(b,0,sizeof(b));
    }
}s,t,p;


int main()
{
    int Case;
    scanf("%d",&Case);
    for (int o=1;o<=Case;o++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) c[i]=a[i];
        sort(c+1,c+n+1);
        for (int i=1;i<=n;i++) a[i]=lower_bound(c+1, c+n+1, a[i])-c;
        s.clear(n);
        t.clear(n);
        p.clear(n);
        int ans=0;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            if (i<=n-m)
            {
                f[i][0]=1;
                f[i][0]=max(f[i][0],s.ask(a[i]-1)+1);
                s.add(a[i],f[i][0]);
            }
            if (i>=m+1)
            {
                f[i][1]=1;
                f[i][1]=max(f[i][1],t.ask(a[i]-1)+1);
                t.add(a[i],f[i][1]);
                f[i][1]=max(f[i][1],p.ask(a[i]-1)+1);
                p.add(a[i-m],f[i-m][0]);
            }
            ans=max(ans,max(f[i][0],f[i][1]));
        }
        printf("Case #%d: %d\n",o,ans);
    }
    return 0;

}