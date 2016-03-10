#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>

#define maxn 1020

using namespace std;


struct Edge{
    int dest, cost, len;
}tmp;

vector<Edge>edge[maxn];
int cost[maxn], dis[maxn];
bool vis[maxn];



int main(){

    int n, m, start, dest;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 && m == 0) return 0;


        for(int i = 1; i <= n; i++) edge[i].clear();

        memset(dis, 0x3f, sizeof(dis));
        memset(cost, 0x3f, sizeof(cost));
        int a, b, d, q;
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d%d", &a, &b, &d, &q);
            tmp.len = d;
            tmp.cost = q;
            tmp.dest = a;
            edge[b].push_back(tmp);
            tmp.dest = b;
            edge[a].push_back(tmp);
        }


//        for(int i = 1; i <= n; i++)
//        {
//            for(int j = 0; j < edge[i].size(); j++){
//                printf("%d %d %d \n", edge[i][j].dest, edge[i][j].cost, edge[i][j].len);
//
//            }
//            printf("\n");
//        }

        scanf("%d%d", &start, &dest);

        cost[start] = dis[start] = 0;
        vis[start] = true;

        for(int i = 0; i < edge[start].size(); i++){
            int de = edge[start][i].dest;
            int len = edge[start][i].len;
            int co = edge[start][i].cost;
            if(len < dis[de] || (len == dis[de] && co < cost[de])){
                dis[de] = len;
                cost[de] = co;
            }
        }

        for(int i = 1; i <= n; i++)
            printf("%d ", dis[i]);
        printf("\n");

        for(int i = 1; i < n; i++){
            int k = 0, mint = 0x3f3f3f3f, minc = 0x3f3f3f3f;

            for(int j = 1; j <= n; j++)
                printf("%d ", dis[j]);
            printf("\n");
            for(int j = 1; j <= n; j++)if(!vis[j] && (dis[j] < mint || (dis[j] == mint && cost[j] < minc)))
            {
                mint = dis[j];
                minc = cost[j];
                k = j;
            }
            printf("k = %d\n",k);
            if(k == 0) {
//                printf("break when i is %d\n", i);
                break;
            }

            vis[k] = true;

            for(int j = 0; j < edge[k].size(); j++)if(!vis[edge[k][j].dest]){
                printf("%d %d\n", k, j);
                int de = edge[start][j].dest;
                int len = edge[start][j].len;
                int co = edge[start][j].cost;
                printf("de=%d len=%d co=%d\n", de,len,co);
                if(len + dis[k] < dis[j] || (dis[j] == len + dis[k] && cost[j] > cost[k] + co)){
                    dis[j] = dis[k] + len;
                    cost[j] = cost[k] + co;
                }

            }
//            for(int k = 1; k <= n; k++)
//                printf("%d ", dis[k]);
//            printf("\n");


        }


        printf("%d %d\n", dis[dest], cost[dest]);



    }





    return 0;
}
