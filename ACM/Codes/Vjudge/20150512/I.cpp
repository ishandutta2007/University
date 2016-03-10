#include<map>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define LL long long

using namespace std;

int main(){
    int t, n, k;

    scanf("%d", &t);
    for (int kk=1; kk<=t; kk++)
    {
        scanf("%d%d", &n, &k);
        while(n>=4*k)
            n -= 2*k;
        if (n == 3*k-1)
            printf("Case %d: Losing\n", kk);
        else
            printf("Case %d: Winning\n", kk);
    }

    return 0;
}
