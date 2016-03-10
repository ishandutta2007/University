#include<stdio.h>
#include<math.h>
#include<iostream>
#define EPS 1e-8



using namespace std;

const double pi = acos(-1.0), g = 9.8;
double x, y, v;


double cal(double theta){
    double tmp = x / (v * cos(theta));
    return tan(theta) * x - 0.5 * g * tmp * tmp;
}


int main(){


    int T;
    scanf("%d", &T);
    while(T--){
        cin >> x >> y >> v;

        double l = 0.0, r = pi / 2;
        double mid1, mid2;

        while(r - l > EPS){
            mid1 = l + (r - l) / 3;
            mid2 = r - (r - l) / 3;
            if(cal(mid1) < cal(mid2)) l = mid1;
            else r = mid2;
        }
        if(cal(mid1) < y){
            printf("-1\n");
        }
        else{
            l = 0.0;
            r = mid2;
            while(r - l > EPS){
                mid1 = (l + r) / 2;
                if(cal(mid1) < y) l = mid1;
                else r = mid1;
            }
            printf("%.6lf\n", mid1);
        }

    }

    return 0;
}
