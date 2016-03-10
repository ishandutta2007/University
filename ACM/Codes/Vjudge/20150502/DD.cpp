#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define LL long long


using namespace std;

int pos[1000020];
LL dp[1000020];


int main(){

    int t;
    scanf("%d", &t);
while(t--){
    int n;
    scanf("%d", &n);
    memset(pos, 0, sizeof(pos));
    int a;
    LL ans = 0;
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        dp[i] = dp[i - 1] + (LL)a * (i - pos[a]);
        pos[a] = i;
        ans += dp[i];
    }
    printf("%lld\n", ans);
}
    return 0;
}
