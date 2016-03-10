#include<map>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define LL long long

using namespace std;


int a[4][1020];
int N;
int dest;
int flag;
int roll[4];
//bool vis1[4][4000020];
//bool vis2[4][4000020];


bool check(){
    for(int i = 0; i < N; i++)
    {
        if(a[0][i] + a[1][(i + roll[1]) % N] + a[2][(i + roll[2]) % N] + a[3][(i + roll[3]) % N] != dest)
            return false;
    }

    return true;
}


void DFS(int now, int lev){
    if(lev > 3){
        if(now == dest && check()){ flag = 1;}
        return;
    }
    for(int i = 0; i < N && (flag == 0); i++){
        if(now + a[lev][i] + (3 - lev) <= dest){
//            vis1[lev][i] = 1;
            roll[lev] = i;
            DFS(now + a[lev][i], lev + 1);
        }
    }
    return;
}



int main(){

    int t;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca ++){
        memset(a, 0, sizeof(a));
        scanf("%d", &N);


        LL sum = 0;

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &a[i][j]);
                sum += a[i][j];
            }

        if(sum % N != 0){
            printf("Case %d: No\n", ca);
            continue;
        }
        dest = sum / N;

        flag = 0;
        roll[0] = 0;
        DFS(a[0][0], 1);
        if(flag) printf("Case %d: Yes\n", ca);
        else printf("Case %d: No\n", ca);
    }

    return 0;
}
