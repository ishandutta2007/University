#include<iostream>
#include<stdio.h>
#include<algorithm>

#define ll long long
using namespace std;


int main(){


    ll n, m, x, y , wd;
    while(~scanf("%I64d%I64d%I64d%I64d", &n, &m, &x, &y)){
        if(n <= 2 || m <= 2){
            printf("1\n");
            continue;
        }

        wd = n * m - (n - 2) * (m - 2);

        if(x == 1 || x == n || y == 1 || y == m)
            wd--;


        ll sum = n * m;

        if(sum % wd == 0LL) printf("%I64d\n", sum / wd);
        else printf("%I64d\n", sum / wd + 1LL);
    }

    return 0;
}

