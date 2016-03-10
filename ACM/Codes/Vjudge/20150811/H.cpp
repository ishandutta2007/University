#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>

#define maxn 1020

using namespace std;

struct Edge{
    int dest, cost;
}tmp;
vector<Edge>edge[maxn];
int n,m;
int vis[maxn];
int dis[maxn];

int main(){


    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0) return 0;

        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        for(int i = 1; i <= n; i++) edge[i].clear();
        int x,y,z;

        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &x, &y, &z);
            tmp.dest = y;
            tmp.cost = z;
            edge[x].push_back(tmp);
            tmp.dest = x;
            tmp.cost = z;
            edge[y].push_back(tmp);
        }

        dis[1] = 0;
        vis[1] = true;
        for(int i = 0; i < edge[1].size(); i++){
            dis[edge[1][i].dest] = min(dis[edge[1][i].dest], edge[1][i].cost);
        }

        for(int i = 0; i < n; i++){
            int k = 0, mint = 0x3f3f3f3f;
            for(int j = 1; j <= n; j++)
                if(!vis[j] && dis[j] < mint){

                    k = j, mint = dis[j];
                }
            if(k == 0) break;

            for(int j = 0, dest, cost; j < edge[k].size(); j++){
                dest = edge[k][j].dest;
                cost = edge[k][j].cost;

                if(!vis[dest] && cost + dis[k] < dis[dest])
                    dis[dest] = cost + dis[k];
            }


        }


        printf("%d\n", dis[n]);
    }




    return 0;
}
