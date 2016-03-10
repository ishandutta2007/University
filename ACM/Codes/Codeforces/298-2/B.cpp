#include<stdio.h>


int main(){
    int v1, v2, t, d;
    scanf("%d%d%d%d",&v1, &v2, &t, &d);

    int sum = v1;
    int tmp;
    for(int i = 2; i <= t; i++){
        tmp = v1 + d;
        while(tmp - (t - i) * d > v2)
            tmp --;
//        printf("%d\n", tmp);
        sum += tmp;
        v1 = tmp;
    }

    printf("%d\n",sum);



    return 0;
}
