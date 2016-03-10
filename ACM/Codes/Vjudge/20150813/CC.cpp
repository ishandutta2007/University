#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>

using namespace std;





int n;
int c[52];
int num[52];
int dp[250000];
int sum;

int main(){


    while(scanf("%d", &n) != EOF){
        if(n < 0) return 0;


        memset(dp, 0, sizeof(dp));
        sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &c[i], &num[i]);
            sum += c[i] * num[i];
        }


        int v = sum / 2;

        for(int i = 1; i <= n; i++){
            if(c[i] * num[i] >= v)
                for(int j = c[i]; j <= v; j++)
                    dp[j] = max(dp[j], dp[j - c[i]] + c[i]);
            else{
                int k = 1;
                while(k < num[i]){
                    for(int j = v; j >= c[i] * k; j--)
                        dp[j] = max(dp[j], dp[j - c[i]*k] + c[i]*k);
                    num[i] -= k;
                    k *= 2;
                }
                for(int j = v; j >= c[i]*num[i]; j--)
                    dp[j] = max(dp[j], dp[j-c[i]*num[i]] + c[i]*num[i]);

            }

        }

        printf("%d %d\n", sum - dp[sum/2], dp[sum/2]);


    }







    return 0;
}
