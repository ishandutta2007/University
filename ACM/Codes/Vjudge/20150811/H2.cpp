#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>

#define maxn 120


using namespace std;

int dis[120][120];


int main(){

    int n, m;
    while(scanf("%d%d", &n,&m) != EOF){
        if(n == 0 && m == 0) return 0;

        memset(dis, 0x3f, sizeof(dis));
        for(int i = 1; i <= n; i++)
            dis[i][i] = 0;
        while(m--){
            int x, y, z;
            scanf("%d%d%d", &x,&y,&z);
            dis[x][y] = min(dis[x][y], z);
            dis[y][x] = min(dis[y][x], z);
        }



        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            if(dis[i][j] > dis[i][k] + dis[k][j])
                dis[i][j] = dis[i][k] + dis[k][j];


        printf("%d\n", dis[1][n]);
    }




    return 0;
}
