#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>

using namespace std;


int a[120][120];
int c[120][120];
int n, m;
int tmp[120], path[120];
int pree[120][120];



void dfs(int cow, int now, int pre){

    if(cow >= m)
    {
        return;
    }

    for(int i = 0; i < n; i++)if(now == c[i][cow] && (abs(pre-i)<=1 || abs(pre+n-i)<=1 || abs(i+n-pre)<=1))
    {
        printf("%d", i+1);
        if(cow != m-1)
            printf(" ");
        dfs(cow+1, now - a[i][cow], i);
        return;
    }
}


int main(){


    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);


        memset(c, 0x7f, sizeof(c));

        for(int i = 0; i < n; i++)
            c[i][m-1] = a[i][m-1];
        for(int j = m-2; j >= 0; j--)
        for(int i = 0; i < n; i++)
        {
            c[i][j] = min(c[(i + n - 1) % n][j+1], min(c[i][j+1], c[(i + 1) % n][j+1])) + a[i][j];
        }

//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < m; j++)
//                printf("%d%c", c[i][j], j == m - 1 ? '\n' : ' ');

        int ans = 0x6f6f6f6f;
        int k;
        for(int i = 0; i < n; i++)if(c[i][0] < ans){
            k = i;
            ans = c[i][0];
        }

        dfs(0, ans, k);

        printf("\n%d\n", ans);


    }
    return 0;

}
