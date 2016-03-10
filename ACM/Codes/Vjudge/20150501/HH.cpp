#include<queue>
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;


char grd[11][11];
bool vis[11][11];
int movex[4] = {0,0,1,-1};
int movey[4] = {1,-1,0,0};

int qx[120],qy[120],qt[120];
int head, tail;

int ans;
int cnt;
int n, m;

bool check(int x, int y)
{
    if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && grd[x][y] == '#') return true;
    return false;
}



int main(){

    int t;
    scanf("%d",&t);
    for(int k = 1; k <= t; k++){
        scanf("%d%d", &n, &m);
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s", grd[i]);
            for(int j = 0; j < m; j++)
                if(grd[i][j] == '#') cnt++;
        }
        ans = 0x7f7f7f7f;
        for(int i1 = 0; i1 < n; i1++)
        for(int i2 = 0; i2 < m; i2++)
            if(grd[i1][i2] == '#')
            for(int j1 = 0; j1 < n; j1++)
            for(int j2 = 0; j2 < m; j2++)if(grd[j1][j2] == '#'){
                memset(vis, 0, sizeof(vis));
                head = 0;
                tail = 0;
                qx[head] = i1;
                qy[head] = i2;
                qt[head] = 0;
                if(i1 != j1 || i2 != j2){
                    tail++;
                    qx[tail] = j1;
                    qy[tail] = j2;
                    qt[tail] = 0;
                }
                vis[i1][i2] = true;
                vis[j1][j2] = true;
                int tmpx,tmpy,tmpt,nowx,nowy,nowt;
                int vscnt = 0;
                while(head <= tail){
                    vscnt ++;
                    nowt = qt[head];
                    nowx = qx[head];
                    nowy = qy[head];
                    head ++;
                    for(int i = 0; i < 4; i++){
                        tmpx = nowx + movex[i];
                        tmpy = nowy + movey[i];
                        if(check(tmpx, tmpy)){
                            qt[++tail] = (nowt + 1);
                            qx[tail] = tmpx;
                            qy[tail] = tmpy;
                            vis[tmpx][tmpy] = true;
                        }

                    }

                }
                if(vscnt == cnt && nowt < ans) ans = nowt;
        }
        if(ans == 0x7f7f7f7f) printf("Case %d: %d\n", k, -1);
        else printf("Case %d: %d\n", k, ans);
    }
    return 0;
}
