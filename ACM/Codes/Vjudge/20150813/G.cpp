#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define ll long long


using namespace std;


ll a[1020];
ll ans[1020];


int main(){


    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) return 0;


        for(int i = 0; i < n; i++) scanf("%I64d",&a[i]);

        memset(ans, 0, sizeof(ans));

        ll maxc;
        ans[0] = maxc = (ll)a[0];
        for(int i = 1; i < n; i++){
            ans[i] = a[i];
            for(int j = 0; j < i; j++){
                if(a[j] < a[i] && ans[j] + a[i] > ans[i])
                {
                    ans[i] = ans[j] + a[i];
                    maxc = max(maxc, ans[i]);
                }
            }


        }
        printf("%I64d\n", maxc);



    }






    return 0;
}
