#include<stdio.h>
#include<string.h>



int gcd(int a, int b){

    if(a % b == 0) return b;

    return gcd(b, a % b);
}

int main(){

    int a[20];
    printf("Input 10 numbers:\n");
    int i;
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    int max = a[0];
    int min = a[0];

    for(i = 0; i < 10; i++)
    {
        if(max < a[i]) max = a[i];
        if(min > a[i]) min = a[i];
    }

    printf("maxNum=%d\n", max);
    printf("minNum=%d\n", min);
    printf("%d", gcd(max, min));

    return 0;
}
