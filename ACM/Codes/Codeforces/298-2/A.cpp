#include<stdio.h>




int main(){

    int n;
    while(scanf("%d", &n) == 1){
        if(n == 1 || n == 2){
            printf("%d\n%d\n", 1, 1);
            continue;
        }
        if(n == 3){
            printf("%d\n%d %d\n", 2, 1, 3);
            continue;
        }
        if(n == 4){
            printf("4\n2 4 1 3\n");
            continue;
        }
        int m = (n + 1) >> 1;
        printf("%d\n", n);
        for(int i = 1; i + m <= n; i++)
            printf("%d %d ", i, i + m);
        if(n % 2 == 1)
            printf("%d\n", m);
        else
            printf("\n");
    }
    return 0;
}
