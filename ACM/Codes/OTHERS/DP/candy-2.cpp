#include<bits/stdc++.h>
#define M 10000007

int dp[21][10020];
int a[21];

int main(){

    int t;
    scanf("%d", &t);
    for(int ka = 1; ka <= t; ka++){
        int n,m;
        memset(dp, 0, sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            a[i] = y - x;
            m -= x;
        }

        if(m < 0){
            printf("Case #%d: %d\n", ka, 0);
            continue;
        }
        int mx = 0;
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i][0] = 1;
            mx += a[i];
            int s = 0;
            for(int j = 0; j <= mx && j <= m; j++){
                s += dp[i-1][j];
                if(j > a[i]) s = (s + M - dp[i - 1][j -a[i] - 1]) % M;
                s %= M;
                dp[i][j] = s;
            }
        }

//        for(int i = 0; i <= n; i++)
//            for(int j = 0; j <= m; j++)
//                printf("%d%c", dp[i][j], j == m? '\n':' ');

        printf("Case #%d: %d\n", ka, dp[n][m]);


    }



    return 0;
}
