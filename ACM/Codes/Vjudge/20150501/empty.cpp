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
        int n;
        scanf("%d", &n);
        if(n % 2 == 0){
            printf("No\n");
            continue;
        }
        double theta = PI / n;
        double edge = sqrt(1 + 1 - 2 * cos(theta));
        double s = (n * (edge * edge) * (sin(2 * theta)) )/ (4 - 4 * cos(2 * theta));
        edge = edge / (2 * sin(theta));
        if(s < 0.75 + EPS && s > 0.5 + EPS){
            printf("Yes\n");
            double sta = PI / 2;
            theta *= 2;
            for(int i = 0; i < n; i++){
                printf("%.6lf %.6lf\n", edge * cos(sta + theta * i), edge * sin(sta + theta * i));
            }

        }
        else printf("No\n");
    }

    return 0;
}
