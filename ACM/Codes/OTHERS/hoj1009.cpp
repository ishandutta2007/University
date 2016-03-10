#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxn 120

using namespace std;

int room[maxn][maxn];
int movex[4] = {0, 0, 1, -1};
int movey[4] = {1, -1, 0, 0};
int n, m;

int main(){

    while(scanf("%d%d", &n, &m) != EOF){
        memset(room, 0, sizeof(room));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &room[i][j]);

        int my = 1, mx = 1;
        int ans = 0;
        int cx, cy;
        scanf("%d %d", &cx, &cy);
        cx ++;
        cy ++;
        while(true){
            ans ++;
            room[mx][my] = 0;
            int maxi = -1;
            int maxch = 0;
            for(int i = 0; i < 4; i++)
                if(room[mx + movex[i]][my + movey[i]] > maxch){
                    maxi = i;
                    maxch = room[mx + movex[i]][my + movey[i]];
                }
            if(maxi == -1){
                printf("impossible\n");
                break;
            }
            mx += movex[maxi];
            my += movey[maxi];
            if(ans >= abs(cx - mx) + abs(cy - my)){
                printf("%d\n", ans);
                break;
            }
        }
    }

    return 0;
}
