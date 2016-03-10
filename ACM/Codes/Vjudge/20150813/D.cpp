#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;


int dp1[20200],dp2[20200];
int v[120], num[120];
int n, V;


int main(){

    int ka = 0;
    while(scanf("%d%d", &n, &V) != EOF){
        if(n == 0 && V == 0) return 0;
        ka ++;
        memset(dp1, 0x3f, sizeof(dp1));
        memset(dp2, 0x3f, sizeof(dp2));
        memset(v, 0, sizeof(v));
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &num[i]);

        dp1[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = v[i]; j <= 20000; j++)
                dp1[j] = min(dp1[j], dp1[j-v[i]] + 1);

        dp2[0] = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] * num[i] >= 20000)
                for(int j = v[i]; j <= 20000; j++)
                    dp2[j] = min(dp2[j], dp2[j - v[i]] + 1);
            else{
                int k = 1;
                while(k < num[i]){
                    for(int j = 20000; j >= v[i] * k; j--)
                        dp2[j] = min(dp2[j], dp2[j - v[i]*k] + k);
                    num[i] -= k;
                    k *= 2;
                }
                for(int j = 20000; j >= v[i]*num[i]; j--)
                    dp2[j] = min(dp2[j], dp2[j-v[i]*num[i]] + num[i]);

            }

        }

        int ans = 0x3f3f3f3f;

        for(int i = V; i <= 20000;i++)
            if(dp2[i] + dp1[i - V] < ans)
                ans = dp2[i] + dp1[i - V];
        if(ans == 0x3f3f3f3f) ans = -1;
        printf("Case %d: %d\n",ka, ans);
    }






    return 0;
}
