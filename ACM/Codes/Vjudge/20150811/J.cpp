#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>

#define maxn 1000

using namespace std;


int adp[maxn];
int mp[maxn][maxn];
int vis[maxn];
int d[maxn];

int main(){


    int t;
    int n;

    scanf("%d", &t);
    while(t--){


        memset(d, 0x3f, sizeof(d));
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &adp[i]);

        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            scanf("%d", &mp[i][j]);
            if(i != j)
                mp[i][j] += adp[i] + adp[j];
        }


        vis[1] = true;
        for(int i = 2; i <= n; i++)
            d[i] = min(d[i], mp[1][i]);

        int ans = 0;
        for(int i = 1; i < n; i++){
            int k = 0;
            int mint = 0x3f3f3f3f;
            for(int j = 1; j <= n; j++)
            if(!vis[j] && d[j] < mint){
                mint = d[j];
                k = j;
            }

            if(k == 0) break;
            ans += mint;
            vis[k] = true;
            for(int j = 1; j <= n; j++)if(!vis[j] && mp[k][j] < d[j])
                d[j] = mp[k][j];



        }


        printf("%d\n", ans);

    }


    return 0;
}
