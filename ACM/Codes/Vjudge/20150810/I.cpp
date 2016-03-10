#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>


using namespace std;


char field[120][120];
int n, m;
int mx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int my[8] = {-1, 0, 1, 1, 1, 0, -1, -1};


void expand(int x, int y){
    field[x][y] = '.';

    int tx, ty;
    for(int i = 0; i < 8; i++){
        tx = x + mx[i];
        ty = y + my[i];

        if(tx >= 0 && tx < n && ty >= 0 && ty < m && field[tx][ty] == 'W'){
            expand(tx, ty);
        }
    }


}


int main(){



    while(scanf("%d%d",&n,&m) == 2){

        for(int i = 0; i < n; i++)
            scanf("%s", field[i]);

        int ans = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(field[i][j] == 'W')
            {
                ans ++;
                expand(i, j);
            }

        }
        printf("%d\n", ans);
    }


    return 0;
}
