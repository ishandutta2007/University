#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;


int a[1020];
int b[1020];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        memset(a, 0 ,sizeof(a));
        memset(b, 0 ,sizeof(b));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            a[x] ++;
            b[x] ++;
        }

        sort(a, a + 1001, greater<int>());

        if(a[0] == a[1]){
            printf("Nobody\n");
            continue;
        }
        for(int i = 1; i <= 1000; i++)if(b[i] == a[0]){
            printf("%d\n", i);
            break;
        }

    }


    return 0;
}
