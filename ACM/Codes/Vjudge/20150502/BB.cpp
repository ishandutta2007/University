#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define LL long long


using namespace std;

int bit[33];
int a[100020];


int main(){
    int t;
    scanf("%d", &t);
while(t--){
    memset(bit, 0, sizeof(bit));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        int top = 31;
        while((a[i] & (1<<top)) == 0) top--;
        bit[top] ++;
    }

    LL ans = 0;
    for(int i = 1; i <= n; i++){
        int top = 31;
        while((a[i] & (1<<top)) == 0) top--;
        while(top >= 0){
            if((a[i] & (1<<top)) == 0)
                {
//                    printf("%d %d\n", a[i], top);
                    ans += bit[top];
                }
            top--;
        }
    }
    printf("%lld\n", ans);

}
    return 0;
}
