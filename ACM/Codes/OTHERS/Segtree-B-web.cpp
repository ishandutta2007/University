#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
  
#define L l,m,u<<1  
#define R m+1,r,u<<1|1  //u*2+1  
  
const int N=200000+10;  
int h,w,n;  
int a[N<<2];  
  
void build(int l,int r,int u)//u为根结点  
{  
    a[u]=w;  
    if(l==r)  
        return;  
    int m=(l+r)>>1;  
    build(L);  
    build(R);  
}  
  
int query(int x,int l,int r,int u)  
{  
    if(l==r)  
    {  
        a[u]-=x;  
        return l;  
    }  
    int m=(l+r)>>1;  
    int res=(a[u<<1]>=x)?query(x,L):query(x,R);  
    a[u]=max(a[u<<1],a[u<<1|1]);  
    return res;  
}  
  
int main()  
{  
    freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    while (~scanf("%d%d%d",&h,&w,&n))  
    {  
        if(h>n)  
            h=n;  
        build(1,h,1);  
        
        while(n--)  
        {  
            int x;  
            scanf("%d",&x);  
            if(a[1]<x)  
                printf("-1\n");  
            else  
                printf("%d\n",query(x,1,h,1));  
        }  
    }  
    return 0;  
}  
