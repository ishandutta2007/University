#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>

#define EPS 1e-8

using namespace std;

double x, y, l, w;
const double pi = acos(-1.0);


double cal(double theta){
    double tthe = tan(theta + pi / 2);
    return tthe * l * sin(theta) + y - tthe * x - (w / sin(theta));
}

double getlow(){
    double ex = sqrt(l*l + w*w);
    return asin(x / ex);

}


int main(){

    while(~scanf("%lf%lf%lf%lf",&x,&y,&l,&w)){


        double low = 0.0, high = pi / 2;
        double mid1, mid2;
        while(high - low > EPS){
//            cout << low <<"   "<< high << endl;
            mid1 = low + (high - low) / 3;
            mid2 = high - (high - low) / 3;

            if(cal(mid1) < cal(mid2)) high = mid2;
            else low = mid1;
        }
//        cout << cal(mid1) << endl;
        if(cal(mid1) + EPS > 0) printf("yes\n");
        else printf("no\n");

    }
    return 0;
}
