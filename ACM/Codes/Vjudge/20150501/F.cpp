#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

#define EPS 1e-6
#define PI acos(-1)


using namespace std;


int x[33];
int y[33];

double gettheta(int a, int b, int c){
    int sx = x[b] - x[a];
    int sy = y[b] - y[a];
    int ex = x[c] - x[a];
    int ey = y[c] - y[a];
    double theta = sx * ex + sy * ey;
    theta /= sqrt(sx*sx + sy*sy) * sqrt(ex*ex + ey*ey);
//    printf("cos theta %lf\n", theta);
//    printf("%d %d %d\n", a, b, c);
//    printf("theta %lf\n", acos(theta));
    return acos(theta);
}

double max(double a, double b, double c){
    double tmp = a;
    if(b > tmp) tmp = b;
    if(c > tmp) tmp = c;
    return tmp;
}


bool check(int a1, int a2, int a3, int a4){
    double theta = 0;
    theta += max(gettheta(a1, a2, a3), gettheta(a1, a2, a4), gettheta(a1, a3, a4));
    theta += max(gettheta(a2, a1, a3), gettheta(a2, a1, a4), gettheta(a2, a3, a4));
    theta += max(gettheta(a3, a1, a2), gettheta(a3, a1, a4), gettheta(a3, a2, a4));
    theta += max(gettheta(a4, a1, a2), gettheta(a4, a1, a3), gettheta(a4, a2, a3));
    if(fabs(theta - 2 * PI) < EPS)
        return true;
    return false;
}


int main(){
    int t;
    scanf("%d", &t);
    int n;
    for(int k = 1; k <= t; k++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &x[i], &y[i]);

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int i1 = i + 1; i1 <= n; i1++)
                for(int i2 = i1 + 1; i2 <= n; i2++)
                    for(int i3 = i2 + 1; i3 <= n; i3++)
                        if(check(i, i1, i2, i3))
                            ans ++;

        printf("Case %d: %d\n", k, ans);

    }


    return 0;
}
