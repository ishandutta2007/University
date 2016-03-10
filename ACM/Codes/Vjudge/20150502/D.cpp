#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>


#define LL long long

using namespace std;

LL pos[1000020];
LL times[1000020];
int main(){

    int t;
    scanf("%d", &t);
    while(t --){
        memset(pos, 0, sizeof(pos));
        memset(times, 0, sizeof(times));
        int n;
        scanf("%d", &n);
        LL ans = 0;
        int a;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a);
            ans += (LL)a * (i * (n + 1 - i));
            times[a] ++;
            if(times[a] > 1){
                ans -= (LL)a * (pos[a] * (n + 1 - i));
//                printf(" - %d\n", a * (pos[a] * (n + 1 - i)));
            }
            pos[a] = i;
        }

        printf("%lld\n", ans);

    }
    return 0;
}
