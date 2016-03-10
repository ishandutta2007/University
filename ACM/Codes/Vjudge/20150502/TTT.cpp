
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>

#define LL long long

using namespace std;

int a[100020];




int main(){

    int t;
    scanf("%d", &t);
    while(t --){
        memset(a, 0, sizeof(t));

        int n;
        scanf("%d", &n);
        LL ans = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            ans += a[i] * (i * (n + 1 - i));

            for(int j = 1; j < i; j++)if(a[j] == a[i]){
                ans -= a[i] * (j * (n + 1 - i));
            }
        }

        printf("%lld\n", ans);

    }
    return 0;
}
