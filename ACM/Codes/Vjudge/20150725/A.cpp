#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ll long long
#define eps 1e-10




double H, h, D;



double callen(double x){
    double len = (h * x) / (H - h);

//        cout << "int cal\n" << endl;
    if(x + len > D){

        len = (x * H - D * (H - h)) / x + D - x;

//        cout << "int if\n" << endl;
    }
//    cout << "callen" << endl;
//    cout << x << "    "<<len << endl;

    return len;
}


int main(){


    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lf%lf%lf", &H, &h, &D);
//        cout << callen(0.0) <<endl;
        double low = D * (1-(h / H)), high = D;
        double mid1, mid2;

        while(high - low > eps){


//            printf("low : %f   high : %f\n", low, high);
            mid1 = low + (high - low) / 3;
            mid2 = high - (high - low) / 3;

            if(callen(mid1) > callen(mid2)) high = mid2;
            else low = mid1;
        }

        printf("%.3lf\n", callen(mid1));
    }



    return 0;
}
