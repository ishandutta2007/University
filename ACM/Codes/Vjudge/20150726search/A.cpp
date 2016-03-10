#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;



int n, m;
char tab[22][22];
bool vis[22][22];
int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};
queue<int>qx, qy;

bool check(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == false && tab[x][y] == '.')
    {
        vis[x][y] = true;
        return true;
    }

    return false;
}



int bfs(int sx, int sy){
//    printf("%d %d\n", sx, sy);
    memset(vis, 0, sizeof(vis));
    int ans = 1;

    vis[sx][sy] = true;
    qx.push(sx);qy.push(sy);
    int nowx, nowy, tmpx, tmpy;
    while(!qx.empty()){
        nowx = qx.front();nowy = qy.front();
        qx.pop();qy.pop();

        for(int i = 0; i < 4; i++)
        {
            tmpx = nowx + mx[i];
            tmpy = nowy + my[i];
            if(check(tmpx, tmpy))
            {
                ans++;
                qx.push(tmpx);
                qy.push(tmpy);
            }
        }

    }

    return ans;
}






int main(){

    while(~scanf("%d%d", &m, &n)){
        if(n == 0 && m == 0) return 0;

        for(int i = 0; i < n; i++)
            scanf("%s", tab[i]);

        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(tab[i][j] == '@') ans = bfs(i, j);


        printf("%d\n", ans);

    }


    return 0;
}
