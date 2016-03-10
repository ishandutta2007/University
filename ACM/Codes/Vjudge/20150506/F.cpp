#include<math.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>

#define LL long long

using namespace std;

struct Point{
    double x, y, z;
}p[4];


int cmp(double a, double b){
    if(fabs(a - b) < 1e-9) return 0;
    return 1;
}

double cal_seg(struct Point a, struct Point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}


int main(){
    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++){
        for(int i = 0; i < 4; i++)
            cin >> p[i].x >> p[i].y >> p[i].z;
        printf("Case #%d: ",k);
        int x = 0;
        double seg[4] = {0};
        for(int i = 1; i < 4; i++)
        {
            seg[i] = cal_seg(p[0], p[i]);
            if(seg[i] > seg[x])
            x = i;
        }
        if(x == 0){
            printf("No\n");
            continue;
        }
        swap(p[x], p[2]);
        swap(seg[x], seg[2]);

        for(int i = 1; i < 4; i++){
            p[i].x -= p[0].x;
            p[i].y -= p[0].y;
            p[i].z -= p[0].z;
        }

        if((cmp(p[1].x + p[3].x , p[2].x) != 0) || (cmp(p[1].y + p[3].y , p[2].y) != 0) || (cmp(p[1].z + p[3].z , p[2].z) != 0)){
            printf("No\n");
            continue;
        }

        if(cmp(p[1].x * p[3].x + p[1].y * p[3].y + p[1].z * p[3].z , 0.0) != 0){
            printf("No\n");
            continue;
        }
        if(cmp(seg[1], seg[3]) != 0){
            printf("No\n");
            continue;
        }



        printf("Yes\n");
    }
    return 0;
}
