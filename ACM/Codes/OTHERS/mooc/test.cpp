#include<stdio.h>
#define max(a, b)(a > b) ? a:b

int main()
{

    #define xxx printf("!!!\n")
    xxx;
    int a = 1, b = 2;
    printf("%d\n", max(a, b));
    return 0;
}
