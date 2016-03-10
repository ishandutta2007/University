#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;


vector<int>edge[1020];
queue<int>qid, qt;
int n, m;
int dest[1020];
bool vis[1020];
int pend[1020][1020];
int tmp[1020];

int main(){


    while(scanf("%d%d", &n, &m) != EOF){
        memset(edge, 0, sizeof(edge));
        memset(dest, 0, sizeof(dest));
        memset(vis, 0, sizeof(vis));
        memset(pend, 0, sizeof(pend));
        memset(tmp, 0, sizeof(tmp));
        int x, y, z;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &x, &y, &z);
            pend[x][y] = z;
            dest[y] ++;
        }
        int now = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dest[i] == 0){
                qid.push(i);
                qt.push(now);
            }
        }

        while(!qid.empty()){
            int id = qid.front();
            qid.pop();
            int t = qt.front();
            qt.pop();
            vis[id] = true;
            ans = max(ans, t);
            for(int i = 0; i < n; i++)if(pend[id][i] > 0){

                dest[i]--;
                tmp[i] = max(tmp[i], t + pend[id][i]);
                if(dest[i] == 0 && !vis[i]){
                    qid.push(i);
                    qt.push(tmp[i]);
                }
            }



        }

        printf("%d\n", ans);



    }


    return 0;
}
