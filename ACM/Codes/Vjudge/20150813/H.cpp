#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<math.h>

using namespace std;


int a[500020];
int ans[500020];


int main(){

    int ka = 0;
    int n;
    while(scanf("%d", &n) != EOF){
        ka ++;
        int x, y;
        for(int i = 1; i <= n; i++){
            scanf("%d%d",&x,&y);
            a[x] = y;
        }

        memset(ans, 0, sizeof(ans));
        ans[1] = a[1];
        int len = 1;
        for(int i = 2; i <= n; i++){
            if(a[i] > ans[len])
                ans[++len] = a[i];


            else{
                int p = lower_bound(ans, ans + len + 1, a[i]) - ans;
                ans[p] = a[i];
            }

        }
        if(len == 1)
            printf("Case %d:\nMy king, at most %d road can be built.\n\n",ka, len);
        else
            printf("Case %d:\nMy king, at most %d roads can be built.\n\n",ka, len);
    }






    return 0;
}
