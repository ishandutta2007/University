#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=110;
const int INF=10000000;
int  dist[maxn][maxn], G[maxn][maxn];
int  n, m, num, minc;

void floyd()
{
    minc=INF;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<k; i++)
            for(int j=i+1; j<k; j++)
            {
                int  ans=dist[i][j]+G[i][k]+G[k][j];
                if(ans<minc)  //找到最优解
                {
                    minc=ans;
                }
            }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
    }
}

int main()
{
    int  u, v, c;
    while(cin >> n >> m)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i == j) dist[i][i] = G[i][i] = 0;
                else dist[i][j]=G[i][j]=INF;
            }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            if(dist[u][v]>c)
                G[u][v]=G[v][u]=dist[u][v]=dist[v][u]=c;
        }
        floyd();
        if(minc==INF)
            printf("It's impossible.\n");
        else
        {
            printf("%d\n", minc);
        }
    }
    return 0;
}