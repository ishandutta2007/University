#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

#define LL long long


using namespace std;


int main(){

    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++)
    {
        LL a, b;
        scanf("%I64d%I64d", &a, &b);
        int ans = 0;
        while(a > b){
            ans ++;
            LL tmp = a / 2 + 1;
            a -= (a % tmp);
        }
        printf("Case %d: %d\n",k ,ans);

    }



    return 0;
}

