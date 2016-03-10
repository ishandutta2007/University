#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>


#define ll long long

using namespace std;

int a[120];
ll ans[120][120];

int main(){

    int n;
    scanf("%d", &n);


    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    memset(ans, 0x3f, sizeof(ans));

    for(int i = 1; i + 2 <= n; i++)
        ans[i][i + 2] = a[i]*a[i+1]*a[i+2];

    for(int i = 1; i + 1 <= n; i++)
        ans[i][i + 1] = 0LL;

    for(int k = 3; k <= n; k++){
        for(int i = 1; i+k-1 <= n; i++){
            int e = i + k - 1;
            for(int j = i + 1; j < e; j++){

//                printf("%d %d %d\n", i, j, e);
                ans[i][e] = min(ans[i][e], ans[i][j] + ans[j][e] + a[j]*a[i]*a[e]);
//                cout << ans[i][e] <<endl;
            }
        }
    }


    printf("%I64d\n", ans[1][n]);



    return 0;
}
