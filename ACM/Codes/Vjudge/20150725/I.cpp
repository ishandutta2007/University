#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>

#define eps 1e-9

using namespace std;


double a[10020], b[10020], c[10020];
int n;


double cal(double x, int i){
    return a[i] * x * x + b[i] * x + c[i];
}


double calf(double x){

    double tmp = cal(x, 0);


    for(int i = 1; i < n; i++)
        tmp = max(tmp, cal(x, i));


    return tmp;
}


double calmin(){
    double low = 0.0, high = 1000.0;
    double mid1, mid2;
    while(low + eps < high){

//        cout << low << "   " << high << endl;
        mid1 = (high - low) / 3 + low;
        mid2 = high - (high - low) / 3;

        if(calf(mid1) > calf(mid2)) low = mid1;
        else high = mid2;
    }

    return calf(mid1);

}



int main(){


    int T;
    scanf("%d", &T);
    while(T--){
        double ans;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }

        printf("%.4lf\n", calmin());
    }


    return 0;
}
