#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 120
#define min(a, b) a < b ? a : b


int dfn[maxn];
int low[maxn];
int cut[maxn];
int edge[maxn][maxn];
int n;
int depth;


void dfs(int v, int rt){
    dfn[v] = low[v] = (++ depth);
    for(int i = 1; i <= n; i++)if(edge[v][i]){
        if(i == rt)  continue;
        if(dfn[i] != 0)
        {
            low[v] = min(dfn[i], low[v]);
            continue;
        }
        dfs(i, v);
        low[v] = min(low[v], low[i]);
        if(low[i] >= dfn[v])  cut[v]++;  //访问不到比v小的节点
    }
    if(rt!=0) cut[v]++;    //如果此节点不为dfs的根节点，那么删除这个点之后会多出一个subnet
}




int main(){

    while(scanf("%d", &n) != EOF){
        if(n == 0)
            return 0;

        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(cut, 0, sizeof(cut));
        memset(edge, 0, sizeof(edge));
        depth = 0;
        int x, y;
        while(scanf("%d", &x) && x)
        {
            while(getchar()!='\n')
            {
                scanf("%d", &y);
                edge[x][y]=edge[y][x]=1;
            }
        }

        dfs(1, 0);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(cut[i] > 1)
                ans++;

        printf("%d\n", ans);
    }



    return 0;
}
