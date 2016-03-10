#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>


#define ll long long

using namespace std;

int cd[120][120];
int md[120][120];
int room, startc, startm;
int creach[120],mreach[120];

void walk(int door[120][120], int reach[120], int start){

    reach[start] = 1;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int now = q.front();q.pop();
        reach[now] = 1;
        for(int i = 1; i <= room; i++)if(door[now][i] == 1 && reach[i] == 0)
            q.push(i);
    }
//    for(int i = 1; i <= room; i++) printf("%d ", reach[i]);
//    printf("\n");
}




int main(){


    int T;
    scanf("%d", &T);

    while(T--){
        scanf("%d%d%d", &room, &startc, &startm);
        memset(cd, 0, sizeof(cd));
        memset(md, 0, sizeof(md));
        memset(creach, 0, sizeof(creach));
        memset(mreach, 0, sizeof(mreach));

        int x,y;
        while(scanf("%d%d", &x, &y)){
            if(x == -1) break;
            cd[x][y] = 1;
        }
        while(scanf("%d%d", &x, &y)){
            if(x == -1) break;
            md[x][y] = 1;
        }

        walk(cd, creach, startc);
        walk(md, mreach, startm);
        int flag = 0;
        for(int i = 1; i <= room; i++)if(creach[i] == 1 && mreach[i] == 1) flag = 1;
        printf("%c ", flag? 'Y' : 'N');

        for(int i = 1; i <= room; i++)if(creach[i] == 1){
            for(int j = 1; j <= room; j++) md[i][j] = 0;
        }

        memset(mreach, 0, sizeof(mreach));
        walk(md, mreach, startm);
        flag = 0;
        for(int i = 1; i <= room; i++)
            if(mreach[i] == 1 && md[i][startm] == 1)
                flag = 1;
//        printf("\n");
//        for(int i = 1; i <= room; i++)
//            for(int j = 1; j <= room; j++)
//                printf("%d%c", md[i][j], j == room ? '\n': ' ');

        printf("%c\n",  flag == 1? 'Y' : 'N');

    }






    return 0;
}
