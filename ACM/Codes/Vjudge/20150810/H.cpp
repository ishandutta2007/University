#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;


vector<int>edge[100020];
queue<int>qid, qc;
int n, m;
int dest[100020];
bool vis[100020];


int main(){


    while(scanf("%d%d", &n, &m) != EOF){
        memset(edge, 0, sizeof(edge));
        memset(dest, 0, sizeof(dest));
        memset(vis, 0, sizeof(vis));
        int x, y;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &y, &x);
            edge[x].push_back(y);
            dest[y] ++;
        }
        int now = 888;
        long long ans = 0LL;
        int visited = 0;
        for(int i = 1; i <= n; i++){
            if(dest[i] == 0){
                qid.push(i);
                qc.push(now);
            }
        }

        while(!qid.empty()){
            int id = qid.front();
            qid.pop();
            int c = qc.front();
            qc.pop();
            vis[id] = true;
            visited++;
            ans += c;
//            printf("nowid = %d size = %d\n",id, edge[id].size());
            for(int i = 0; i < edge[id].size(); i++){


//                printf("%d -> %d\n", id, edge[id][i]);
                dest[edge[id][i]]--;
                if(dest[edge[id][i]] == 0 && !vis[edge[id][i]]){
                    qid.push(edge[id][i]);
                    qc.push(c + 1);
                }
            }



        }

//        printf("visited = %d\n", visited);
        if(visited == n) printf("%I64d\n", ans);
        else printf("-1\n");



    }


    return 0;
}
