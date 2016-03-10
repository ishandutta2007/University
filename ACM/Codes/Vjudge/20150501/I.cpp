#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;


char a[120][120];


int main(){

    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++){
        int n, m;
        scanf("%d %d", &n,&m);
        memset(a, 0,sizeof(a));

        for(int i = 0; i < n; i++)
            scanf("%s", a[i]);
        int cnt = 0;

//        printf("!!!\n");
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < m; j++)
                if(a[i][j] == 'O')
                    cnt ++;

        printf("Case %d: %s\n", k, cnt % 2 == 0 ? "Fat brother" : "Maze");
    }




    return 0;
}

