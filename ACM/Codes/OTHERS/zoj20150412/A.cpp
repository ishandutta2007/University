#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;


int a[10020];



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sort(a, a + n);
        if(a[0] == a[1])
            printf("%d\n", a[n - 1]);
        else
            printf("%d\n", a[0]);
    }

    return 0;
}
