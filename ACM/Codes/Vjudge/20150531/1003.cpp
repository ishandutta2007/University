#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

#define LL long long

int n, m;
int town[520][520];
int vis[520][520];
int ans ;
int mx[5] = {-1, 0, 1, 0, -1};
int my[5] = {0, 1, 0, -1, 0};

bool check(int x, int y){
    if(x > 0 && x <= n && y > 0 && y <= m) return true;
    return false;
}

void invade(int x, int y){

    int down = 0;

    for(int i = 0; i < 4; i++){
        int tmpx1 = x + mx[i];
        int tmpy1 = y + my[i];
        int tmpx2 = x + mx[i + 1];
        int tmpy2 = y + my[i + 1];
//        if(check(tmpx1, tmpy1) && check(tmpx2, tmpy2))
        if(check(tmpx1, tmpy1) && check(tmpx2, tmpy2) && town[tmpx1][tmpy1] == 1 && town[tmpx2][tmpy2] == 1){
//            printf("%d %d %d %d\n", tmpx1, tmpy1, tmpx2, tmpy2);
            down = 1;
            break;
        }
    }
    if(down == 0) return;
    town[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int tx = x + mx[i];
        int ty = y + my[i];

        if(town[tx][ty] == 0 && check(tx, ty))
            invade(tx, ty);
    }
}




int main(){
    int T;
    scanf("%d", &T);

    for(int ka = 1; ka <= T; ka++){
        scanf("%d%d", &n, &m);
        memset(town, 0, sizeof(town));
        memset(vis, 0, sizeof(vis));
        int g, x, y;
        scanf("%d", &g);
        while(g--){
            scanf("%d%d", &x, &y);
            town[x][y] = 1;
        }
//        printf("---------------------\n");
//        for(int i = 1; i <= n; i++)
//            for(int j = 1; j <= m; j++)
//                printf("%d%c", town[i][j], j == m? '\n':' ');
//        printf("---------------------\n");
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(town[i][j] == 0)
                    invade(i, j);

        ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(town[i][j]) ans++;
        printf("Case #%d:\n%d\n", ka, ans);
    }


    return 0;
}
