#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdlib.h>

using namespace std;


int dp[52][1020];



int main(){


    for(int i = 1; i <= 1000; i++) dp[1][i] = i;
    for(int i = 1; i <= 50; i++) dp[i][1]  = 1;

    for(int i = 2; i <= 50; i++)
        for(int j = 1; j <= 1000;j++){
            int mint = 0x3f3f3f3f;
            for(int k = 1; k <= j; k++)
            {
//                printf("%d %d %d\n", dp[i - 1][k - 1], i - 1, k - 1);
//                printf("%d %d %d\n", dp[i][j - k], i, j - k);
                mint = min(mint, max(dp[i - 1][k - 1], dp[i][j - k]));
//                mint = min(mint, dp[i][j - k]);
//                system("pause");
            }
//            printf("%d\n",)
            dp[i][j] = 1 + mint;
        }

//    for(int i = 1; i <= 5; i++)
//    for(int j = 1; j <= 10; j++)
//        printf("%d%c", dp[i][j], j == 10? '\n':' ');

    int t;
    scanf("%d", &t);
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d %d\n", a, dp[b][c]);
    }



    return 0;
}
