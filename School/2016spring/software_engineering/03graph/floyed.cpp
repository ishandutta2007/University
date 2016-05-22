#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=110;
const int INF=100000000;
int  dist[maxn][maxn], G[maxn][maxn];
int  n, m, num, minc;
void floyd()
{
    minc=INF;
    // 求最小环
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
            for(int j=1; j<=n; j++)if(i!=j)
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
    scanf("%d%d", &n, &m);
    int x, y, c;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            dist[i][j] = G[i][j] = INF;
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x,&y,&c);
        G[x][y] = G[y][x] = dist[x][y] = dist[y][x] = c;
    }

    floyd();

    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n; j++)
            printf("%d%c", dist[i][j]==INF? -1: dist[i][j], j == n? '\n':' ');

    return 0;
}
/*
4 4
1 2 10
2 3 10
3 4 -10
1 4 10

*/