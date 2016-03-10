#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

#define LL long long

using namespace std;

int a[100020];
int f[100020];

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    int minpos = 1;
    int mc = 0;
    int tmp = 0;
    int anspos = 1;
    for(int i = 2; i <= n; i++){
        tmp++;
        if(tmp > mc) {anspos = minpos; mc = tmp;}

        if(a[i] < a[minpos]){
            minpos = i;
            tmp = 1;
        }


    }

    printf("%d\n", anspos);

    return 0;
}

