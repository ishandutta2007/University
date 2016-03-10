#include<bits/stdc++.h>
#define LL long long


using namespace std;





double a[6];

int main(){

    for(int i = 0; i < 6; i++)
        cin >> a[i];


    double S = 0.0;
    S += a[0] * a[1] * sqrt(3.0) / 4;
    S += a[2] * a[3] * sqrt(3.0) / 4;
    S += a[4] * a[5] * sqrt(3.0) / 4;

    double c1 = sqrt(a[0] * a[0] + a[1] * a[1] + a[0] * a[1]);
    double c2 = sqrt(a[2] * a[2] + a[3] * a[3] + a[2] * a[3]);
    double c3 = sqrt(a[4] * a[4] + a[5] * a[5] + a[4] * a[5]);

    double p = (c1 + c2 + c3) / 2;

    S += sqrt(p * (p - c1) * (p - c2) * (p - c3));


    double ans = S * 4 / sqrt(3.0);

    printf("%.0lf\n", ans);
    return 0;
}
