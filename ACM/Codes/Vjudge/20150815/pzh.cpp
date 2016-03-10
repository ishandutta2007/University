#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#define inf 10000000
using namespace std;
int ans;
struct point
{
    int x,y;
};
point a[50000];
int b[50000],c[50000];
int sum[50000];
map <int,int> m;
void Add(int b,int e,int t,int l,int r,int rt)
{
    if (l>=b && r <= e)
    {
        sum[rt]=t;
        return;
    }
    if (sum[rt]!=0) {sum[rt*2]=sum[rt*2+1]=sum[rt];}
    sum[rt]=0;
    int mid=(l+r)/2;
    if (mid>=b) Add(b,e,t,l,mid,rt*2);
    if (mid<e) Add(b,e,t,mid+1,r,rt*2+1);
}

void query(int l,int r,int rt)
{
    int x,mid;
    //cout<<l<<' '<<r<<' '<<sum[rt]<<endl;
    if (sum[rt]>0)
    {
        x=sum[rt];
        if (c[x]==0) {ans++;c[x]=1;}
        return;
    }
    if (l>=r) return;
    mid=(l+r)/2;
    if (l<=mid) query(l,mid,rt*2);
    if (mid<r) query(mid+1,r,rt*2+1);
    return;
}
int main()
{
    int t,n,x,y,o,ci;
    scanf("%d",&ci);
    while (ci>0)
    {
        ci--;
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            b[i]=a[i].x;b[i+n]=a[i].y;
        }

        sort(b+1,b+1+2*n);
        o=0;
        b[0]=-999;
        for (int i=1;i<=2*n;i++)
        {
            if (b[i]!=b[i-1]) {o++;m[b[i]]=o;}
        }
        //cout<<o<<endl;
        for (int i=1;i<=n;i++)
        {
            int z;
            x=m[a[i].x];
            y=m[a[i].y];
            //if (x>y) {z=y;y=x;x=z;}
            //cout<<x<<' '<<y<<endl;
            Add(x,y,i,1,o,1);
        }
        ans=0;
        query(1,o,1);
        cout<<ans<<endl;
    }

    return 0;
}
