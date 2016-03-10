#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>

#define LL long long



using namespace std;




LL n;

struct Flyer{
    LL a, b, c;
}flyer[20020];


LL getsum(LL p)
{
    LL sum = 0;
    for(int i = 0; i < n; i++){
        LL now = min(flyer[i].b, p);
        if(now >= flyer[i].a)
            sum += (now - flyer[i].a) / flyer[i].c + 1;
    }
    return sum;
}

int main(){

    while(scanf("%I64d", &n) == 1){
        for(int i = 0; i < n; i++){
            scanf("%I64d%I64d%I64d",&flyer[i].a,&flyer[i].b,&flyer[i].c);
        }

        LL l = 0; LL r = (1LL << 31);

        while(l < r){

            LL mid = (l + r) / 2;
//            printf("%I64d %I64d %I64d\n", l, mid, r);
            if(getsum(mid) % 2 == 1) r = mid;
            else l = mid + 1;
        }
//        printf("%d\n", l);
        if(l == (1LL << 31)) printf("DC Qiang is unhappy.\n");
        else printf("%I64d %I64d\n" ,l ,getsum(l) - getsum(l - 1));


    }
    return 0;
}
