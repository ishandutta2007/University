#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>


using namespace std;

double a[123], b[123];
double dt = 0.005;



int main(){

    a[0] = b[0] = 0;
    a[1] = 1; b[1] = 0;
    a[2] = 0.5; b[2] = sqrt(1 - 0.5 * 0.5);
    a[3] = 0.5; b[3] = b[2] - 1;

    for(int i = 4; i < 101; i++){
        b[i] = i * dt;
        a[i] = sqrt(1 - b[i] * b[i]);
    }

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        if(n < 4){ printf("No\n"); continue;}

        printf("Yes\n");
        for(int i = 0; i < n; i++)
            printf("%.6lf %.6lf\n", a[i], b[i]);

    }

    return 0;
}
