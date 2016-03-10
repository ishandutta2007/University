#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

#define LL long long

using namespace std;

int n;
char f[1020];
char t[1020];


int main(){

    scanf("%d", &n);

    scanf("%s%s", f,t);

    int ans = 0;

    for(int i = 0; i < n; i++){
        int a = f[i] - '0';
        int b = t[i] - '0';
        if(a < b) swap(a, b);
        ans += min(a - b,b + 10 - a);
    }


    printf("%d\n", ans);

    return 0;
}
