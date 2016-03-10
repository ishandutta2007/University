#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

#define ll long long


using namespace std;

struct point{
    int x, y;
}p[1020];

int fa[1020];
int N, d;
bool dis[1020][1020];
bool rep[1020];

bool caldis(int x, int y){

    int tmp = (p[x].x - p[y].x) * (p[x].x - p[y].x);
    tmp += (p[x].y - p[y].y) * (p[x].y - p[y].y);
    return tmp <= d;
}

int root(int a){
    while(a != fa[a])
        a = fa[a] = fa[fa[a]];
    return a;
}
void unionset(int x, int y){
    int rx = root(x);
    int ry = root(y);

    if(rx == ry) return;
    else fa[rx] = ry;
}




int main(){

    scanf("%d%d", &N, &d);
    d = d * d;

    for(int i = 1; i <= N; i++)
        fa[i] = i;

    for(int i = 1; i <= N; i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }

    for(int i = 1; i <= N; i++)
    for(int j = i + 1; j <= N; j++){
        dis[i][j] = dis[j][i] = caldis(i, j);
    }


    char cmd[10];

    while(scanf("%s", cmd) != EOF){

//        for(int i = 1; i <= N; i++)
//                printf("%d %d\n", i, root(i));

        if(cmd[0] == 'O'){
            int a;
            scanf("%d", &a);
            rep[a] = true;
            for(int i = 1; i <= N; i++)if(rep[i] && dis[a][i] == true)
                unionset(a, i);
        }
        else{
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%s\n", root(a) == root(b) ? "SUCCESS" : "FAIL");
        }
    }


    return 0;
}
