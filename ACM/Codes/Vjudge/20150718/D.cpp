#include<bits/stdc++.h>


using namespace std;

int a[10020];


int main(){

    int n;
    scanf("%d", &n);

    bool isyes = true;
    scanf("%d", &a[0]);
    int roll = n - a[0];
    for(int i = 1; i < n; i++){
        scanf("%d", &a[i]);
        int mm = 1;
        if(i % 2 == 1) mm = -1;

        a[i] = (a[i] + n + mm * roll) % n;

//        printf("%d\n", a[i]);
        if(a[i] != i) isyes = false;
    }

    if(isyes) printf("Yes\n");
    else printf("No\n");
    return 0;
}
