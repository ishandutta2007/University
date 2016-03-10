#include<stdio.h>
#include<iostream>

using namespace std;


int main(){

    int t;
    scanf("%d",&t);
    while(t --){
        int a1,h1,a2,h2;
        scanf("%d%d%d%d",&a1,&h1,&a2,&h2);
        if(a1 == 0)
            printf("Invalid\n");

        else{
            h1 -= a2;
            h2 -= a1;
            if(h1 <= 0)
                printf("Discard ");
            else
                printf("%d %d ",a1, h1);
            if(h2 <= 0)
                printf("Discard\n");
            else
                printf("%d %d\n", a2, h2);
        }
    }
    return 0;
}
