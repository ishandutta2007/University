#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int num[100010];

int main(){
    int n,m;
    while(scanf("%d%d", &n, &m) == 2){
        for(int i = 0; i < n;i++)
            scanf("%d",&num[i]);
        sort(num, num + n);
        for(int i = 0; i < n;i++)
            printf("%d\n", num[i]);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int dest = m - num[i];
            ans += upper_bound(num, num + n, dest) - lower_bound(num, num + n, dest);
            if(dest == num[i])
                ans --;
        }
        printf("%I64d\n", ans / 2);
    }

    return 0;

}
