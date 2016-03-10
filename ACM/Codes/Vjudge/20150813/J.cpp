#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#include<queue>
#include<limits.h>

using namespace std;


vector<int>edge[100020];
int c[100020], in[100020], out[100020];
int n, m;
int ans[100020];
bool vis[100020];
queue<int>qu;


int main(){

    while(scanf("%d%d",&n,&m) != EOF){
        memset(c, 0, sizeof(c));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            edge[i].clear();
            scanf("%d", &c[i]);
            ans[i] = -0X7fffffff;
        }
        int x, y;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            out[x] ++;
            in[y] ++;
            edge[x].push_back(y);
        }

        for(int i = 1; i <= n; i++)if(in[i] == 0){
            vis[i] = true;
            ans[i] = c[i];
            qu.push(i);
        }

        while(!qu.empty()){
            int now = qu.front();qu.pop();
            for(int i = 0; i < edge[now].size(); i++)
            {
                int dest = edge[now][i];
                in[dest]--;
                if(ans[now] + c[dest] > ans[dest])
                    ans[dest] = ans[now] + c[dest];
                if(in[dest] == 0){
                    vis[i] = true;
                    qu.push(dest);
                }
            }

        }

        int aa = -0X7fffffff;
        for(int i = 1; i <= n; i++)if(out[i] == 0 && ans[i] > aa)
            aa = ans[i];
//
//        for(int i = 1; i <= n; i++)
//            printf("%d %d\n", i, ans[i]);

        printf("%d\n", aa);

    }




    return 0;
}
