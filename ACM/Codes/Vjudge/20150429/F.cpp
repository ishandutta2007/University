#include<cmath>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;


int dev[100020];



int main(){

    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++)
    {
        memset(dev, 0, sizeof(dev));
        int n;
        int x;
        int ans = 1;
        scanf("%d", &n);
        while(n --){
            scanf("%d", &x);
            int sx = sqrt(x);
            for(int i = 1; i <= sx; i++)if(x % i == 0){
                    dev[i] ++;
                    dev[x / i] ++;
                if(x / i == i)
                    dev[i] --;
                if(dev[i] >= 2 && i > ans)
                    ans = i;
                if(dev[x / i] >= 2 && x / i > ans)
                    ans = x / i;
            }
        }
        printf("Case #%d: %d\n", k, ans);
    }


    return 0;
}
