#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 10010;
const double eps = 1e-8;
double U[500][500];
int id[MAXN];
int fa[MAXN];
int vis[MAXN];
int eu[MAXN*4];
int ev[MAXN*4];

int mfind(int x)
{
    if(x==fa[x])return x;
    else return fa[x]=mfind(fa[x]);
}

void guass(int n)
{
    for(int i=0;i<n;i++){
        int r;
        for(r=i;r<n;r++){
            if(fabs(U[r][i])>=eps)break;
        }
        if(r==n)continue;
        for(int j=0;j<=n;j++)swap(U[i][j],U[r][j]);
        for(int j=n;j>i;j--)U[i][j]/=U[i][i];
        U[i][i]=1;
        for(int j=0;j<n;j++){
            if(i==j || fabs(U[j][i])<eps)continue;
            for(int k=n;k>i;k--)U[j][k]-=U[j][i]*U[i][k];
            U[j][i]=0;
        }
    }
}
/*
0.000000
0.000000
1.000000
inf
1.111111
inf
1.500000
2.000000
inf
1.000000

*/
int main()
{
  freopen("data2.in", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int N,M,S,T;
        scanf("%d%d%d%d",&N,&M,&S,&T);
        for(int i=1;i<=N;i++)fa[i]=i;
        for(int i=0;i<M;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            if(!c)fa[mfind(u)]=mfind(v);
            eu[i]=u;
            ev[i]=v;
        }
        if(mfind(S)==mfind(T)){
            printf("%.6lf\n",0);
            continue;
        }
        memset(vis,-1,sizeof(vis));
        int cnt=0;
        for(int i=1;i<=N;i++){
            int rt=mfind(i);
            if(vis[rt]==-1)vis[rt]=cnt++;
            id[i]=vis[rt];
        }
        memset(U,0,sizeof(U));
        for(int i=0;i<cnt;i++)fa[i]=i;

        for(int i=0;i<M;i++){
            int u=id[eu[i]];
            int v=id[ev[i]];
            if(u==v)continue;
            fa[mfind(u)]=mfind(v);
            U[u][u]+=1;
            U[v][v]+=1;
            U[u][v]-=1;
            U[v][u]-=1;
        }
        if(mfind(id[S])!=mfind(id[T])){
            printf("inf\n");
            continue;
        }
        U[id[S]][cnt]=1;
        U[id[T]][cnt]=-1;
        U[cnt-1][0]+=1;

        guass(cnt);
        printf("%.6lf\n",fabs((U[id[S]][cnt]-U[id[T]][cnt])));
    }
}
