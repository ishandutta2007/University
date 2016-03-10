#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define LL long long


using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d%d", &n, &k);
        int mem = n / k;
        LL ans = 0;
        ans += mem * mem * k * (k - 1) / 2;
        int rest = n - mem * k;
        ans += rest * (n - mem - 1);
        if(rest > 0) ans -= rest * (rest - 1) / 2;
        printf("%I64d\n", ans);
    }
    return 0;
}
