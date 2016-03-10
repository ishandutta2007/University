#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#define LL long long

using namespace std;


struct node{
    int x, y;
    int cost;
};

bool operator < (struct node a, struct node b){
    return a.cost > b.cost;
}


int vis[1020][1020];
int farm[1020][1020];
int mp[1020][1020];
int n, m;
int mx[4] = {0, 0, -1, 1};
int my[4] = {1, -1, 0, 0};

priority_queue<node> q;

int connect(){
    while(!q.empty()) q.pop();
    struct node nownode, tmpnode;
    int nowx, nowy, nowcost;
    int tx, ty, tcost;
    tmpnode.x = 1;
    tmpnode.y = 1;
    tmpnode.cost = 0;

    q.push(tmpnode);


    int ans = 0;
    while(!q.empty()){
        nownode = q.top();
        q.pop();
        nowx = nownode.x;
        nowy = nownode.y;
        if(vis[nowx][nowy] == 0)
        {
            ans += nownode.cost;
            vis[nowx][nowy] = 1;
//            printf("%d %d %d\n", nowx, nowy, nownode.cost);
            for(int i = 0; i < 4; i++){
                tx = nowx + mx[i];
                ty = nowy + my[i];
                tcost = abs(farm[nowx][nowy] - farm[tx][ty]);
                if(tx > 0 && tx <= n && ty > 0 && ty <= m && vis[tx][ty] == 0 && tcost < mp[tx][ty]){
                    tmpnode.x = tx;
                    tmpnode.y = ty;
                    tmpnode.cost = tcost;
                    mp[tx][ty] = tcost;
                    q.push(tmpnode);
                }
            }
        }
    }
    return ans;
}



int main(){
    int T;
    scanf("%d", &T);

    for(int ka = 1; ka <= T; ka++){
        scanf("%d%d", &n, &m);
        memset(farm, 0, sizeof(farm));
        memset(vis, 0, sizeof(vis));
        memset(mp, 0x7f7f7f7f, sizeof(mp));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &farm[i][j]);

        printf("Case #%d:\n%d\n", ka, connect());
    }


    return 0;
}
