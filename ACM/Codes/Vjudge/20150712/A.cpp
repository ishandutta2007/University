#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

#define LL long long

using namespace std;



int main(){


    int T;
    scanf("%d", &T);
    while(T--){
        int n, m;
        scanf("%d %d", &n, &m);
        int sn = 0;
        int sm = 0;
        int x;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            sn += x;
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &x);
            sm += x;
        }
        if(sn > sm){
            printf("Calem\n");
        }
        else if(sn < sm) printf("Serena\n");
        else printf("Draw\n");
    }

    return 0;
}
