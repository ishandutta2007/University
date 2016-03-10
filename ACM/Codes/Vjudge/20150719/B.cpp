#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;


long long a[19];


void init(){
    double rest = 1.0;

    long long now = 2;

    for(int i = 1; i <= 19; i++){

        double tmp = 1.0 / rest;
//        printf("%lf %d\n", tmp, int(tmp));
        now = (long long)tmp + 1;
        a[i] = now;
        rest -= 1.0 / now;
    }

}



int main(){

    init();
    printf("!!!\n");

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        printf("%lld\n", a[i]);
    return 0;
}
