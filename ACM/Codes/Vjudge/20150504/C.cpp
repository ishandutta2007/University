#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#define LL long long

using namespace std;




int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        LL n,k,d1,d2;
        scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);

        if(n % 3 != 0){
            printf("no\n");
            continue;
        }
        LL avg = n / 3;
        LL x, y, z;
        if(k - 2 * d1 - d2 >= 0){
            x = (k - 2 * d1 - d2) / 3;
            y = x + d1;
            z = y + d2;
            if(x + y + z == k && 0 <= x && x <= avg && 0 <= y && y <= avg && 0 <= z && z <= avg){
                printf("yes\n");
                continue;
            }
        }
        if(k - 2 * d1 + d2 >= 0){
            x = (k - 2 * d1 + d2) / 3;
            y = x + d1;
            z = y - d2;
            if(x + y + z == k && 0 <= x && x <= avg && 0 <= y && y <= avg && 0 <= z && z <= avg){
                printf("yes\n");
                continue;
            }
        }
        if(k + 2 * d1 - d2 >= 0){
            x = (k + 2 * d1 - d2) / 3;
            y = x - d1;
            z = y + d2;
            if(x + y + z == k && 0 <= x && x <= avg && 0 <= y && y <= avg && 0 <= z && z <= avg){
                printf("yes\n");
                continue;
            }
        }
        if(k + 2 * d1 + d2 >= 0){
            x = (k + 2 * d1 + d2) / 3;
            y = x - d1;
            z = y - d2;
            if(x + y + z == k && 0 <= x && x <= avg && 0 <= y && y <= avg && 0 <= z && z <= avg){
                printf("yes\n");
                continue;
            }
        }
        printf("no\n");
    }

    return 0;
}
