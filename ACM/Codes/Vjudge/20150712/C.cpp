
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

#define LL long long

using namespace std;



int main(){
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int mmax = 0;
        int n, m;
        int sum = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            sum += x;
            mmax = max(mmax, x);
        }
        int tot = sum;
        sum /= m;
        sum *= m;
        int ans;
        if(sum < tot) ans = tot / m + 1;
        else ans = tot / m;
        ans = max(ans, mmax);
        printf("%d\n", ans);
    }

    return 0;
}
