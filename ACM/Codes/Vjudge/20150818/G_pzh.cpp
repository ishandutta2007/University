#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int sum[55555*10],ans;
int run[55555*10],year[55555*10];
int num,n;
void pushup(int rt)
{
    sum[rt]=max(sum[rt*2],sum[rt*2+1]);
}

void build(int l,int r,int rt)
{
    int x;
    if (l==r)
        {
            scanf("%d%d",&x,&sum[rt]);
            num++;
            year[num]=x;
            run[num]=sum[rt];
            return;
        }
    int m=(l+r)/2;
    build(l,m,rt*2);
    build(m+1,r,rt*2+1);
    pushup(rt);
    return;
}

void query(int b,int e,int l,int r,int rt)
{
    if (l>=b && r <= e) {ans=max(ans,sum[rt]);return;}
    int m=(l+r)/2;
    if (m>=b) query(b,e,l,m,rt*2);
    if (m<e) query(b,e,m+1,r,rt*2+1);
    return;
}
int Find(int flag)
{
    int l=1,r=n,mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        //cout<<l<<' '<<r<<' '<<mid<<' '<<year[mid]<<endl;
        if (year[mid]==flag) return mid;
        if (year[mid]>flag) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main()
{
    int c,c1,a1,a2;
    int m,fx,fy,xn,yn,x,y;
    memset(sum,0,sizeof(sum));
    memset(run,0,sizeof(run));

        yn=0;xn=0;
    scanf("%d",&n);
    num=0;
    if (n!=0) build(1,n,1);
    scanf("%d",&m);

    for (int i=1;i<=m;i++)
    {
        ans=-1;
        fx=0;fy=0;
        scanf("%d%d",&x,&y);
        if (x>=y) {printf("false\n");continue;}

        xn=Find(x);
        yn=Find(y);
        if (xn==yn) {printf("maybe\n");continue;}
        if (year[xn]!=x) {query(xn,yn-1,1,n,1);fx=1;} else query(xn+1,yn-1,1,n,1);
        if (year[yn]!=y) fy=1;

        if (fx==1 && fy==1) {printf("maybe\n");continue;}

        if (fx==1)
        {
            if (run[yn]<=ans) printf("false\n");
            else printf("maybe\n");
            continue;
        }

        if (fy==1)
        {
            if (run[xn]<=ans) printf("false\n");
            else printf("maybe\n");
            continue;
        }

        if (run[yn]>run[xn] || ans>=run[yn]) {printf("false\n");continue;}

        if (yn-xn!=y-x) {printf("maybe\n");continue;}
        printf("true\n");
    }
    //printf("\n");
    return 0;
}