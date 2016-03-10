#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

#define ll long long

using namespace std;

int w, h;
char t[100][100];
int anss[100][100];
int vis[100][100];
int qx[10000],qy[10000], qt[10000],qd[10000];
int head, tail;
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};


bool check(int x, int y){
    if(x >= 0 && x <= w + 1 && y >= 0 && y <= h + 1 && t[y][x] != 'X' && vis[y][x] == false)
    {
        vis[y][x] = true;
        return true;
    }
    return false;
}


int cal(int sx, int sy, int ex, int ey){

//    printf("%d %d %d %d\n", sx, sy, ex, ey);
    memset(vis, 0, sizeof(vis));
    memset(anss, 0, sizeof(anss));
    head = tail = 0;
    qx[head] = sx;
    qy[head] = sy;
    qt[head] = 0;
    tail = 1;
    vis[sy][sx] = true;
    while(head < tail){
        int sx = qx[head], sy = qy[head];
//        printf("%d %d %d\n", sx, sy, qt[head]);
        anss[sy][sx] = qt[head];

        for(int i = sx + 1; i <= w + 1; i++){
            if(check(i, sy)){
                qx[tail] = i;
                qy[tail] = sy;
                qt[tail] = qt[head] + 1;
                tail ++;
            }
            else{
                if(i == ex && sy == ey) return qt[head] + 1;
                break;
            }
        }
        for(int i = sx - 1; i >= 0; i--){
            if(check(i, sy)){
                qx[tail] = i;
                qy[tail] = sy;
                qt[tail] = qt[head] + 1;
                tail++;
            }
            else{

                if(i == ex && sy == ey) return qt[head] + 1;
                break;
            }
        }
        for(int i = sy + 1; i <= h+1; i++){
            if(check(sx, i)){
                qx[tail] = sx;
                qy[tail] = i;
                qt[tail] = qt[head] + 1;
                tail++;
            }
            else{
                if(sx == ex && i == ey) return qt[head] + 1;
                break;
            }
        }
        for(int i = sy - 1; i >= 0; i--){
            if(check(sx, i)){
                qx[tail] = sx;
                qy[tail] = i;
                qt[tail] = qt[head] + 1;
                tail++;
            }
            else{
                if(sx == ex && i == ey) return qt[head] + 1;
                break;
            }
        }
        head++;
    }
//    for(int i = 0; i <= h + 1; i++){
//        for(int j = 0; j <= w + 1; j++)
//            printf("%d ", anss[i][j]);
//        printf("\n");
//    }

    int ans = 0x3f3f3f3f;

    for(int i = 0; i < 4; i++){
        int tx = ex + mx[i], ty = ey + my[i];
        if(tx >= 0 && tx <= w + 1 && ty >= 0 && ty <= h + 1 && anss[ty][tx] > 0)
            ans = min(ans, anss[ty][tx]);
    }
    return ans + 1;

}



int main(){

    int bd = 0;

    while(scanf("%d%d", &w, &h)){
        if(w == 0 && h == 0) return 0;

        bd ++;
        getchar();
        int pa = 0;
        for(int i = 1; i <=h; i++){
            gets(t[i] + 1);
        }
        printf("Board #%d:\n", bd);
        int sx, sy, ex, ey;
        while(scanf("%d%d%d%d",&sx,&sy,&ex,&ey)){
            if(sx == 0) break;
            pa++;
            printf("Pair %d: ", pa);

            int ans = cal(sx, sy, ex, ey);
            if(ans != 0x3f3f3f3f + 1) printf("%d segments.\n", ans);
            else printf("impossible.\n");
        }


        printf("\n");
    }
    return 0;
}

