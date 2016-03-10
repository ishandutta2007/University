#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;



int L, R, C;
char tab[32][32][32];
bool vis[32][32][32];
int mx[6] = {1, -1, 0, 0, 0, 0};
int my[6] = {0, 0, 1, -1, 0, 0};
int mz[6] = {0, 0, 0, 0, 1, -1};

bool check(int x, int y ,int z){
    if(x >= 0 && x < L && y >= 0 && y < R && z >= 0 && z < C && vis[x][y][z] == false && (tab[x][y][z] == '.' || tab[x][y][z] == 'E'))
    {
        vis[x][y][z] = true;
        return true;
    }

    return false;
}



int bfs(int sx, int sy, int sz){
//    printf("%d %d %d\n", sx, sy, sz);
    memset(vis, 0, sizeof(vis));
    queue<int>qx, qy, qz, qt;

    vis[sx][sy][sz] = true;
    qx.push(sx);qy.push(sy);qz.push(sz);qt.push(0);
    int nowx, nowy, nowz, nowt, tmpx, tmpy, tmpz;
    while(!qx.empty()){
        nowx = qx.front();nowy = qy.front();nowz = qz.front();nowt = qt.front();
        qx.pop();qy.pop();qz.pop();qt.pop();


//        printf("try : %d %d %d %d\n", nowx, nowy, nowz, nowt);
        if(tab[nowx][nowy][nowz] == 'E')
        {
//            printf("%d %d %d\n", nowx, nowy, nowz);
            return nowt;
        }
        for(int i = 0; i < 6; i++)
        {
            tmpx = nowx + mx[i];
            tmpy = nowy + my[i];
            tmpz = nowz + mz[i];
            if(check(tmpx, tmpy, tmpz))
            {
                qt.push(nowt + 1);
                qx.push(tmpx);
                qy.push(tmpy);
                qz.push(tmpz);
            }
        }

    }
    return 0;
}






int main(){

    while(~scanf("%d%d%d", &L, &R, &C)){
        if(L == 0 && R == 0 && C == 0) return 0;

        for(int i = 0; i < L; i++)
        for(int j = 0; j < R; j++)
            scanf("%s", tab[i][j]);

        int ans = 0;
        for(int i = 0; i < L; i++)
            for(int j = 0; j < R; j++)
                for(int k = 0; k < C; k++)
                    if(tab[i][j][k] == 'S') ans = bfs(i, j, k);


        if(ans > 0) printf("Escaped in %d minute(s).\n", ans);
        else printf("Trapped!\n");
    }


    return 0;
}

