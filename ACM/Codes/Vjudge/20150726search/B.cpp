#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;



int n = 8, m = 8;
bool vis[10][10];
int mx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int my[8] = {2, -2, 1, -1, 2, -2, 1, -1};
queue<int>qx, qy, qt;

bool check(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == false)
    {
        vis[x][y] = true;
        return true;
    }

    return false;
}



int bfs(int sx, int sy, int ex, int ey){
//    printf("%d %d   %d %d\n", sx, sy, ex, ey);
    memset(vis, 0, sizeof(vis));
    queue<int>qx, qy, qt;
    vis[sx][sy] = true;
    qx.push(sx);qy.push(sy);qt.push(0);
    int nowx, nowy, nowt, tmpx, tmpy, tmpt;
    while(!qx.empty()){
        nowx = qx.front();nowy = qy.front();nowt = qt.front();
        qx.pop();qy.pop();qt.pop();

        if(nowx == ex && nowy == ey)
            return nowt;
//        printf("%d %d\n", nowx, nowy);
        for(int i = 0; i < 8; i++)
        {
            tmpx = nowx + mx[i];
            tmpy = nowy + my[i];
            if(check(tmpx, tmpy))
            {
                qt.push(nowt + 1);
                qx.push(tmpx);
                qy.push(tmpy);
            }
        }

    }
    return 0;
}






int main(){



    char s1[5], s2[5];
    while(~scanf("%s%s", s1, s2)){
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, bfs(s1[0] - 'a', s1[1] - '1', s2[0] - 'a', s2[1] - '1'));
    }


    return 0;
}
