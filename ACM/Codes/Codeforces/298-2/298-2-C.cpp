#include<stdio.h>
#include<iostream>
#include<string.h>

#define maxn 200020
#define LL long long


using namespace std;


int a[maxn];
LL sum;
LL A;
int n;

int main(){

    scanf("%d%I64d", &n, &A);
    memset(a, 0, sizeof(a));
    sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if(n == 1)
    {
        printf("%d\n", a[0] - 1);
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        LL mmax = sum - a[i];
        LL mmin = n - 1;
        int tmp = 0;
        if(mmin <= mmax)
        {
            LL bot = A - mmax;
            LL top = A - mmin;
            bot = max(bot, 1LL);
            top = min(top, a[i] + 0LL);
            if(bot <= top && bot >= 1 && top <= a[i])
                tmp = top - bot + 1;
        }
//        for(int j = 1; j <= a[i]; j++)
//            if(A - j >= min && A - j <= max)
//                tmp++;
        printf("%d%c",a[i] - tmp, i == (n - 1) ? '\n':' ');
    }

    return 0;
}
