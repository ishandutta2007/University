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

int main(){

    int t;
    scanf("%d", &t);
    while(t-- ){
        int n, N;
        scanf("%d", &N);
        n = N - ((N + 1) % 2);
        if(n < 3 || n > 12){
            printf("No\n");
            continue;
        }
        double theta = PI / n;
        double edge = sqrt(1 + 1 - 2 * cos(theta));
        double edge1 = edge / (2 * sin(theta));
        double s = n * edge1 * edge1 * sin(2 * theta) / 2;
        if(N % 2 == 0)
            s = s - edge1 * edge1 * sin(2 * theta) / 2 + edge * (1 - edge1) / 2;
//        printf("s : %lf\n", s);
        if(s <= 0.75 + EPS && s >= 0.5 - EPS){
            printf("Yes\n");
            double sta = PI / 2;
            theta *= 2;
            for(int i = 0; i < n; i++){
                printf("%.6lf %.6lf\n", edge1 * cos(sta + theta * i), edge1 * sin(sta + theta * i));
                if(i == n / 2 && N % 2 == 0)
                    printf("%.6lf %.6lf\n", edge1 * cos(sta), edge1 * sin(sta) - 1);
            }
        }
        else printf("No\n");
    }

    return 0;
}

