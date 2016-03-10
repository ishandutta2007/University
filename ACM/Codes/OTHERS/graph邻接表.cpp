#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

#define MAXE 1001*1001
#define MAXV 1001


using namespace std;



struct Edge{
        int dest;
//        int cost;
        Edge *next;
        Edge() {}
        Edge(int iD, Edge *iN)
        { dest = iD; next = iN; }
}Npool[MAXE], *Nptr = Npool, *adj[MAXV];

void insert(int start, int finish)
{ adj[start] = new(Nptr++)Edge(finish, adj[start]); }


int V,E;
int dfn[MAXV];
int low[MAXV];
int cut[MAXV];
int depth;
int flag = 0;

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
    for(Edge *p = adj[v]; p ; p = p->next){
        int u = p->dest;
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
        memset(adj, 0, sizeof(adj));
        memset(Npool, 0, sizeof(Npool));
        Nptr = Npool;
        V = 0;
        while(x){
            int nx;
            scanf("%d%d", &y, &nx);
            V = max(V, x);
            V = max(V, y);
            insert(x ,y);
            insert(y ,x);
            x = nx;
        }
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(cut, 0, sizeof(cut));
        depth = 1;
        flag = 0;
        dfs(1, 0);
        if(kase != 1) printf("\n");
        printf("Network #%d\n", kase);
        if(flag){
            for(int i = 1; i <= V; i++)
                if(cut[i] >= 2) printf("  SPF node %d leaves %d subnets\n", i, cut[i]);
        }
        else printf("  No SPF nodes\n");
    }
    return 0;
}
