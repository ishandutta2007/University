#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 10001

using namespace std;


//int vis[maxn];
//vis[i] = 0 means that dfn[i] = 0;

struct Edge{
    int next, dest;
}edge[maxn << 1];
//int edge[maxn][maxn];
int dfn[maxn];
int low[maxn];
//int child[maxn];
int cut[maxn];
int head[maxn];
int n;
int depth;
int flag = 0;
int cnt;


void addedge(int u, int v){
    edge[cnt].next = head[u];
    edge[cnt].dest = v;
    head[u] = cnt++;
}


void dfs(int v, int rt){
    /*
    vis[v] = 1;
    low[v] = v;
    dfn[v] = depth;
    for(int i = 1; i <= n; i++)if(i != rt && edge[v][i]){
        if(vis[i] == 0){
            child[v] ++;
            depth ++;
            dfs(i, v);
            low[v] = min(low[v], low[i]);
        }
        else{
            low[v] = min(low[v], dfn[i]);
        }
    }
//    for(int j = 1; j <= n; j++)if(j != rt && edge[v][j])
//        low[v] = min(low[v], low[j]);
    */
    low[v] = dfn[v] = (++depth);
    for(int i = head[v]; i = -1; i = edge[i].next){
        int u = edge[i].dest;
        if(u == rt)  continue;
        if(dfn[u] != 0)
        {
            low[v] = min(dfn[u], low[v]);
            continue;
        }
        dfs(u, v);
        low[v] = min(low[v], low[u]);
        if(low[u] >= dfn[v])  cut[v]++;  //访问不到比v小的节点
    }
    if(rt!=0) cut[v]++;    //如果此节点不为dfs的根节点，那么删除这个点之后会多出一个subnet
    if(cut[v] >= 2) flag = 1;
}



int main(){

    int x,y;
    int kase = 0;
    while(true){
        kase ++;
        int nextx = 0;
        scanf("%d", &x);
        if(x == 0)
            break;
        memset(edge, 0, sizeof(edge));
        cnt = 0;
        n = 0;
        while(x){
            int nx;
            scanf("%d%d", &y, &nx);
            n = max(n, x);
            n = max(n, y);
//            edge[x][y] = edge[y][x] = 1;
            addedge(x, y);
            addedge(y, x);
            x = nx;
        }
//        for(int i = 1; i <= n; i++)
//            for(int j = 1; j <= n; j++)
//                printf("%d%c", edge[i][j], j == n? '\n':' ');
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(cut, 0, sizeof(cut));
        for(int i = 1; i < maxn;i++) head[i] = -1;
        depth = 1;
        flag = 0;
        dfs(1, 0);
//        for(int i = 1; i <= n; i++)
//            printf("%d %d\n", dfn[i], low[i]);
//        for(int i = 1; i <= n; i++)
//            printf("%d ", cut[i]);
//        printf("\n");
        printf("Network #%d\n", kase);
        if(flag){
            for(int i = 1; i <= n; i++)
                if(cut[i] >= 2) printf("  SPF node %d leaves %d subnets\n", i, cut[i]);
        }

        else printf("  No SPF nodes\n");

        printf("\n");
    }
    return 0;
}
