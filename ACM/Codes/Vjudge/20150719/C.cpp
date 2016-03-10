#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>


#define EPS 1e-5


using namespace std;

double y;
inline double f(double x){
    return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6 - y;
}

double binary_f(double l, double r){
    double mid = (l + r) / 2;
    double fmid = f(mid);
    if(fabs(fmid) < EPS) return mid;

    if(fmid * f(l) < 0) return binary_f(l, mid);
    else return binary_f(mid, r);
}



int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lf", &y);

//        printf("%f\n", y);
//        printf("%f %f", f(0.0), f(100.0));

        if(f(0.0) * f(100.0) > 0.0)
        {
            printf("No solution!\n");
            continue;
        }

        printf("%.4lf\n", binary_f(0.0, 100.0));
    }


    return 0;
}
