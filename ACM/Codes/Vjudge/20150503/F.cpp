#include<math.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define LL long long

using namespace std;

char s[100];
int p[100];


int main(){

    int n;
    scanf("%d", &n);
    scanf("%s", s);

    for(int i = 0; i < n; i++){
        if(s[i] == 'A') p[i] = 1;
        else if(s[i] == 'B') p[i] = 2;
        else p[i] = 4;
    }
    int now = 1;
    LL ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
//        printf("now %d| p : %d\n", now, p[i]);
        if(p[i] == now) continue;
        ans += pow(2, i);
//        printf("%d\n", (int)pow(2, i));
        now = 7 - now - p[i];
    }
    printf("%I64d\n", ans);

    return 0;
}
