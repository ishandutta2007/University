#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>


using namespace std;

int a[1000020];


int main(){
    int t;
    scanf("%d", &t);
while(t--){
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);
    int ans = 0;
    int m = 2;
    int p = 0;
    for(int i = 0; i < n; i++){
        if(i >= p) {p = lower_bound(a, a + n, m) - a; m *= 2;}
        if(p >= n) break;
//        printf("p : %d\n", p);
        for(int j = p; j < n; j++)
        if((a[i] ^ a[j]) > a[j])
        {
            ans ++;
//            printf("ans + when : %d %d\n", i, j);
//            printf("%d %d\n", a[i] ^ a[j], a[j]);
        }
    }
    printf("%d\n", ans);
}
    return 0;
}





