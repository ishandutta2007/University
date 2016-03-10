#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int speed[1020];
int n;

int main(){


    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);

        for(int i = 0; i < n; i++) scanf("%d", &speed[i]);

        sort(speed, speed + n);
        int ans = 0;

        while(n >= 4){


            ans += min(speed[0] + speed[1] * 2 + speed[n - 1], speed[0] * 2 + speed[n - 1] + speed[n - 2]);
//            ans += speed[0] + speed[1] + speed[1] + speed[n - 1];
            n -= 2;
        }

        if(n == 3)
            ans += speed[0] + speed[1] + speed[2];
        else if(n == 2)
            ans += speed[1];
        else if(n == 1)
            ans += speed[0];

        printf("%d\n", ans);

    }


    return 0;
}
