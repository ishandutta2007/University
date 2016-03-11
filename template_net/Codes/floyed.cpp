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
            for(int j=1; j<=n; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
    }
}
