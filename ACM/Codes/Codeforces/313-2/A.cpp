#include<bits/stdc++.h>
#define LL long long


using namespace std;

int a[1020];

int main(){

    int n;
    int flag = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] == 1) flag = 1;
    }
    if(flag)
    printf("-1\n");
    else printf("1\n");

    return 0;
}
