#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 200005
int T[N*4],M;

void seg_build(int n){
    int i;
    for(M=1;M<=n+1;M*=2);
    for(i=1+M;i<=n+M;i++){
        scanf("%d",&T[i]);
    }
    for(i=M-1;i;i--) T[i]=max(T[i*2],T[i*2+1]);
}

void seg_update(int n,int V){
    for(T[n+=M]=V,n/=2;n;n/=2)
        T[n]=max(T[n*2],T[n*2+1]);
}

int seg_query(int s,int t){
    int maxc=-1;
    for(s=s+M-1,t=t+M+1;s^t^1;s/=2,t/=2){
        if(s%2==0) maxc=max(maxc,T[s^1]);
        if(t%2==1) maxc=max(maxc,T[t^1]);
    }
    return maxc;
}

int main()
{
    int n,m,a,b;
    char str[5];
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(T,0,sizeof(T));
        seg_build(n);
        while(m--){
            scanf("%s%d%d",str,&a,&b);
            if(strcmp(str,"U")==0){
                seg_update(a,b);
            }
            else if(strcmp(str,"Q")==0){
                cout << seg_query(a,b) << endl;
            }
        }
    }
    return 0;
}
