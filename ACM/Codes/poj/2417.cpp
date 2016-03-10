#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define N 100000
struct hashtable
{
    int key[N];
    int value[N];
    void init()
    {
        for(int i=0;i<N;i++)key[i]=-1,value[i]=-1;
    }
    void insert(int k,int v)
    {
        int kk=k%N;
        while(key[kk]!=-1&&key[kk]!=k) kk=(kk+1)%N;
        key[kk]=k,value[kk]=v;
    }
    int find(int k)
    {
        int kk=k%N;
        while(key[kk]!=-1&&key[kk]!=k) kk=(kk+1)%N;
        return value[kk];
    }
}h;
int baby_giant(int x,int k,int z)
{
    x%=z,k%=z;
    int m=(int)ceil(sqrt(1.0*z)),pre=1;
    h.init();h.insert(k,0);
    for(int i=1; i<=m; i++)
    {
        pre=(1ll*pre*x)%z;
        h.insert((1ll*pre*k)%z,i);
    }
    for(int i=0,xm=pre,y=1;i*m<=z;i++)
    {
        int j=h.find(y);
        if(j>=0&&i*m-j>=0) return i*m-j;
        y=(1ll*y*xm)%z;
    }
    return -1;
}
int main()
{
    int a, b, p;

    while(scanf("%d%d%d",&p,&a,&b)!=EOF)
    {
        int ans=baby_giant(a,b,p);
        if(ans>=0)cout<<ans<<endl;
        else cout<<"no solution"<<endl;
    }
    return 0;
}