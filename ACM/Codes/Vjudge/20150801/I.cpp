#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

#define ll long long

using namespace std;

int n, m;
char t[120][120];
int mx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int my[8] = {1, 1, 1, 0, -1, -1, -1, 0};


void expand(int x, int y){
    t[x][y] = '*';
    for(int i = 0; i < 8; i++){
        int tx = x + mx[i], ty = y + my[i];
        if(tx >= 0 && tx < n && ty >= 0 && ty < m && t[tx][ty] == '@')
            expand(tx, ty);
    }
}




int main(){

    while(~scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) return 0;

        for(int i = 0; i < n; i++) scanf("%s", t[i]);

        int ans = 0;
        for(int i = 0; i < n; i++)
        for(int j = 0 ; j < m ; j++){
            if(t[i][j] == '@'){
                ans++;
                expand(i, j);
            }
        }

        printf("%d\n", ans);


    }
    return 0;
}

