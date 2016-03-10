#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>



using namespace std;

int c[10020];
int w[10020];
int ans[10020];

int main(){

    int v;
    int n;

    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d",&n,&v);
        for(int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= n; i++){
            for(int j = v; j >= c[i];j--)
                ans[j] = max(ans[j], ans[j - c[i]] + w[i]);
        }
        printf("%d\n", ans[v]);



    }

    return 0;
}

