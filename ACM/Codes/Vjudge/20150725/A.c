#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ll long long
#define eps 1e-6




double H, h, D;



double callen(double x){
    double len = (h * x) / (H - h);

    if(x + len > D){

        len = (x * H - D * (H - h)) / x + D - x;

    }

    return len;
}


int main(){


    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lf%lf%lf", &H, &h, &D);
        double low = 0.0, high = D;
        double mid1, mid2;

        while(high - low > eps){
            mid1 = low + (high - low) / 3;
            mid2 = high - (high - low) / 3;

            if(callen(mid1) > callen(mid2)) high = mid2;
            else low = mid1;
        }

        printf("%.3lf\n", callen(mid1));
    }



    return 0;
}
