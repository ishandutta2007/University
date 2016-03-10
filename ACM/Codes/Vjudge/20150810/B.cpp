#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>


using namespace std;



int lastpre[10];
int tobeprint[10];
bool exist[1000000];
int n;

int addone(){
    tobeprint[0] ++;
    int p = 0;
    while(tobeprint[p] >= 10){
        tobeprint[p + 1] += 1;
        tobeprint[p] = 1;
        p++;
    }

    for(int i = 0; i < n; i++)
        ret = ret * 10 + tobeprint[i];
    return ret;
}


int main(){


    int num;
    while(scanf("%d", &n) != EOF){
        if(n == 0) return 0;
        memset(exist, 0, sizeof(exist));

        for(int i = 0; i < n; i++) lastpre[i] = tobeprint[i] = 0;



        for(int i = 1; i < n; i++) printf("0");
        exist[0] = true;

        num = addone();

        printf("||num = %d||", num);







    }





    return 0;
}
