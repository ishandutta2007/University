#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

#define LL long long

using namespace std;


int n, m;
int vis[20];
int point[20][20];
int ans;
int fact[20];

void DFS(int depth, int sum){
    if(sum >= m){
        ans += fact[n - depth];
        return;
    }
    if(depth >= n) return;

    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            vis[i] = 1;
            DFS(depth + 1, sum + point[depth][i]);
            vis[i] = 0;
        }
    }
}



int main(){

    fact[0] = 1;
    for(int i = 1; i <= 13; i++)
        fact[i] = fact[i - 1] * i;

    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(vis, 0, sizeof(vis));
        memset(point, 0, sizeof(point));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &point[i][j]);


        ans = 0;
        DFS(0, 0);

        printf("%d/%d\n", fact[n], ans);
//        output();
    }


    return 0;
}
