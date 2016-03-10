#include<map>
#include<queue>
#include<stack>
#include<stdio.h>
#include<ctype.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

char ice[520][520];
int n ,m;
int ex, ey;
bool flag = 0;
int movex[4] = {0,0,1,-1};
int movey[4] = {1,-1,0,0};
bool vis[520][520];


void DFS(int x, int y){
    if(x == ex && y == ey){
        for(int i = 0; i < 4; i++){
            int tx = x + movex[i];
            int ty = y + movey[i];
            if(tx >=0 && ty >= 0 && tx < n && ty < m && ice[tx][ty] == '.') { flag = 1; return;}
        }
    }
    if(flag)
        return;

    for(int i = 0; i < 4 && !flag; i++){
        int tx = x + movex[i];
        int ty = y + movey[i];
        if(tx >= 0 && tx < n && ty >= 0 && ty < m)
        {
            if(tx == ex && ty == ey && ice[tx][ty] != '.') { flag = true; return;}
            if(ice[tx][ty] == '.')
            {
                ice[tx][ty] = 'x';
                DFS(tx, ty);
            }
        }
    }
}



int main(){

    scanf("%d%d",&n,&m);

    for(int i = 0; i < n;i++)
        scanf("%s", ice[i]);

    int sx, sy;
    scanf("%d%d%d%d", &sx,&sy, &ex,&ey);
    sx--;sy--;
    ex--;ey--;
    DFS(sx, sy);

    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
