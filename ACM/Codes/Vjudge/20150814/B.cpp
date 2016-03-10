#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>


#define maxn 100020


using namespace std;


struct Edge{
    int to, len;
}tmp;

struct node{
    int a, id;
}low[maxn][33];

int n, m, c;
int fa[maxn];
vector<Edge>edge[maxn];
bool vis[maxn];
int ver[maxn],first[maxn],R[maxn],dir[maxn];
int tot;


void init(){
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
        edge[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    memset(ver, 0, sizeof(ver));
    memset(first, 0, sizeof(first));
    memset(R, 0, sizeof(R));
    tot = 0;
    memset(low, 0, sizeof(low));
}

int root(int a){
    while(a != fa[a])
        a = fa[a] = fa[fa[a]];
    return a;
}
void unionset(int x, int y){
    int rx = root(x);
    int ry = root(y);

    if(rx == ry) return;
    else fa[rx] = ry;
}

void addedge(int x, int y, int z){
    tmp.len = z;
    tmp.to = y;
    edge[x].push_back(tmp);
}

void dfs(int u ,int dep)
{
    vis[u] = true; ver[++tot] = u; first[u] = tot; R[tot] = dep;
    for(int i = 0; i < edge[u].size(); i++)
        if( !vis[edge[u][i].to] )
        {
            int to = edge[u][i].to;


            dir[to] = dir[u] + edge[u][i].len;
            dfs(to,dep+1);
            ver[++tot] = u; R[tot] = dep;
        }
}
int query(int s, int e){

        int k = log2(e - s + 1);
        if(low[s][k].a <= low[e - (1 << k) + 1][k].a) return low[s][k].id;
        return low[e - (1 << k) + 1][k].id;
    }


int LCA(int u ,int v)
{
    int x = first[u] , y = first[v];

    if(x > y) swap(x,y);

    int res = query(x, y);
    return ver[res];
}

int main(){


    while(scanf("%d%d%d",&n,&m,&c) != EOF){
        init();

        int x, y, z;
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d",&x,&y,&z);
            addedge(x, y, z);
            addedge(y, x, z);
            unionset(x, y);
        }

        for(int i = 1; i <= n; i++)if(i == root(i)) dfs(i, 1);
        for(int i = 1; i <= tot; i++) {low[i][0].a = R[i];low[i][0].id = i;}

        //RMQ
        for(int j = 1; j <= 20; j++)
        for(int i = 1; i <= tot; i++)if(i + (1 << j) - 1 <= tot){
            if(low[i][j - 1].a <= low[i + (1 << (j - 1))][j - 1].a){
                low[i][j].a = low[i][j - 1].a;
                low[i][j].id = low[i][j - 1].id;
            }else{
                low[i][j].a = low[i + (1 << (j - 1))][j - 1].a;
                low[i][j].id = low[i + (1 << (j - 1))][j - 1].id;
            }
        }

        while(c--){
            int a, b;
            scanf("%d%d",&a,&b);
            if(root(a) != root(b)){
                printf("Not connected\n");
                continue;
            }
            printf("%d\n", dir[a] + dir[b] - 2 * dir[LCA(a, b)]);

        }

    }

    return 0;
}
