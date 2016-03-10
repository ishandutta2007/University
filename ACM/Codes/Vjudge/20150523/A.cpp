#include<stdio.h>
#define M 1000000007
#define LL long long


LL f[1000020];


int main(){

    f[0] = 0;
    f[1] = 1;
    f[2] = 2;

    for(int i = 3; i < 1000020; i++)
        f[i] = (f[i - 1] + (i - 1) * f[i - 2]) % M;

    int t;
    scanf("%d", &t);

    for(int ka = 1; ka <= t; ka ++){
        int n;
        scanf("%d", &n);

        printf("Case #%d:\n%I64d\n", ka, f[n]);
    }

    return 0;
}


