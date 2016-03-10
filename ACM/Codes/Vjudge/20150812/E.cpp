#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;


int a[10000];
int dp[5][5][10000];


int move(int s, int e){
    if(s == 0) return 2;
    if(s == e) return 1;
    if(abs(s - e) == 1 || s + e == 5) return 3;
    return 4;

//    printf("!!!!!\n");
}



int main(){


    int len;
    while(scanf("%d", &a[0]) != EOF){
        if(a[0] == 0) return 0;
        len = 1;
        while(scanf("%d", &a[len])){
            if(a[len] == 0) break;
            len++;
        }


        memset(dp, 0x3f, sizeof(dp));
//        printf("%d\n", len);
        dp[0][0][0] = 0;
        for(int i = 0; i < len; i++){
            for(int li = 0; li < 5; li++)
            for(int ri = 0; ri < 5; ri++)if(dp[li][ri][i] != 0x3f3f3f3f){
                dp[li][a[i]][i+1] = min(dp[li][a[i]][i+1],dp[li][ri][i] + move(ri, a[i]));
                dp[a[i]][ri][i+1] = min(dp[a[i]][ri][i+1],dp[li][ri][i] + move(li, a[i]));
//                cout << dp[li][a[i]][i+1] << ' ' << dp[a[i]][ri][i+1] <<endl;

            }
//            for(int ii = 0; ii < 5; ii++)
//                for(int j = 0; j < 5; j++)
//                    printf("%d%c", dp[ii][j][i + 1], j == 4? '\n': ' ');
//
//            system("pause");

        }
        int ans = 0x3f3f3f3f;
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++){
//                printf("%d%c", dp[i][j], j == 4? '\n': ' ');
                ans = min(ans, dp[i][j][len]);
            }
        printf("%d\n", ans);


    }




    return 0;
}
