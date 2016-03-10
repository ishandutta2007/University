#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int a[120][120];


int main(){

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);

        memset(a, 0, sizeof(a));


        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i ;j++)
            scanf("%d", &a[i][j]);


        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i ;j++)
                a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
//
//        for(int i = 1; i <= n; i++)
//        for(int j = 1; j <= i ;j++)
//            printf("%d%c", a[i][j], j == i? '\n' : ' ');

        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, a[n][i]);


        printf("%d\n", ans);
    }




    return 0;
}
