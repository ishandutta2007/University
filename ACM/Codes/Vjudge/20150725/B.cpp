#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#define eps 1e-5

using namespace std;


const double pi = acos(-1.0);
double s[10020];
int F, N;


bool check(double x){

    int tmp = 0;
    for(int i = 0; i < N; i++){
        if(s[i] >= x)
            tmp += (int)(s[i] / x);
        else break;
    }

    return tmp >= F;
}



int main(){

    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &F);
        F ++;
        for(int i = 0; i < N; i++)
        {
            scanf("%lf", &s[i]);
            s[i] = pi * s[i] * s[i];
        }
        sort(s, s + N, greater<double>());


//        for(int i = 0; i < N; i++)
//            cout << s[i] << " ";
//        cout << endl;
        double low = 0.0, high = s[0];
        double mid;
        while(high - low > eps){
            mid = (high + low) / 2;
            if(check(mid)) low = mid;
            else high = mid;
        }

        printf("%.4lf\n", low);
    }



    return 0;
}
