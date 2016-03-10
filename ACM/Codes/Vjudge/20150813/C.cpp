#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>



using namespace std;


int n, num[520], v[520];
int tot;
int V[50200];
int ans[50200];
int sum[50200];

int main(){

    while(scanf("%d", &n) != EOF){
        if(n < 0) return 0;

        tot = 0;
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &v[i],&num[i]);
            for(int j = 1; j <= num[i];j++){
                tot++;
                sum[tot] = sum[tot - 1] + v[i];
                V[tot] = v[i];
            }
        }

//
//        for(int i = 1; i <= tot; i++)
//            printf("%d ", V[i]);
//        printf("\n=====================\n");

        memset(ans, 0x3f, sizeof(ans));
        ans[1] = V[1];
        ans[0] = 0;
        for(int i = 2; i <= tot; i++){
            for(int j = 0; j < i ;j++){
                int tmp = ans[j] + V[i] - sum[i - 1] + sum[j];

//                printf("tmp : %d\n", tmp);
                if(tmp >= 0 && tmp < ans[i])
                    ans[i] = tmp;
                tmp = ans[j] - sum[i] + sum[j];
                if(tmp >= 0 && tmp < ans[i])
                    ans[i] = tmp;
            }

        }
//
//        for(int i = 1; i <= tot; i++)
//            printf("%d ", ans[i]);
//        printf("\n");
        printf("%d %d\n", (ans[tot] + sum[tot]) / 2, (sum[tot] - ans[tot]) / 2);

    }



    return 0;
}
