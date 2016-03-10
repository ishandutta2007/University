#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>

using namespace std;


int n;
int t[30][30];
bool vis[30][30];
int mx[4] = {0,0,-1,1};
int my[4] = {1,-1,0,0};

bool inrange(int x, int y){

    if(x >= 1 && x <= n && y >= 1 && y <= n) return true;
    return false;
}


void cal(int x, int y, int &cb, int &ca){
    int bb = 0;
    int ww = 0;
    int cnt = 1;
    int nowx,nowy,tmpx,tmpy;
    queue<int>qx, qy;
    vis[x][y] = 1;
    qx.push(x);qy.push(y);
    while(!qx.empty()){
        nowx = qx.front();nowy = qy.front();
        qx.pop();qy.pop();
        for(int i = 0; i < 4; i++){
            tmpx = nowx + mx[i];
            tmpy = nowy + my[i];
            if(inrange(tmpx, tmpy)){
                if(t[tmpx][tmpy] == 0 && vis[tmpx][tmpy] == 0){
                    cnt++;
                    qx.push(tmpx);
                    qy.push(tmpy);
                    vis[tmpx][tmpy] = true;
                }
                if(t[tmpx][tmpy] == 1) bb = 1;
                if(t[tmpx][tmpy] == 2) ww = 1;

            }
        }
    }

//    printf("%d %d %d %d %d\n", x, y, cnt, ww, bb);
    if(ww == 0 && bb == 1) cb += cnt;
    else if(ww == 1 && bb == 0) ca += cnt;
}



int main(){

    int ca, cb;

    while(~scanf("%d%d%d",&n, &ca, &cb)){
        if(n == 0) return 0;
        memset(t, 0, sizeof(t));
        memset(vis, 0, sizeof(vis));
        int x, y;
        for(int i = 0; i < ca; i++)
        {
            scanf("%d%d",&x,&y);
            t[x][y] = 1;
        }
        for(int i = 0; i < cb; i++)
        {
            scanf("%d%d",&x,&y);
            t[x][y] = 2;
        }

        ca = 0;
        cb = 0;

        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(t[i][j] == 0 && vis[i][j] == 0)
                cal(i, j, ca, cb);

        if(ca > cb) printf("Black wins by %d\n", ca - cb);
        else if(ca < cb) printf("White wins by %d\n", cb - ca);
        else printf("Draw\n");
    }


    return 0;
}
