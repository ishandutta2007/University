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
        int x, y;
        scanf("%d%d",&x,&y);
        v = y - x;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &w[i], &c[i]);


        memset(ans, 0x3f, sizeof(ans));
        ans[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = c[i]; j <= v;j++)
                ans[j] = min(ans[j], ans[j - c[i]] + w[i]);
        }

        if(ans[v] == 0x3f3f3f3f) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", ans[v]);




    }

    return 0;
}
