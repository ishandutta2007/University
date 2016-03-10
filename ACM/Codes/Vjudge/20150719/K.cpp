#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>

using namespace std;

struct point{
    double x, y;
}p[60];

double calseg(struct point a, struct point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


double getS(int a, int b, int c){
    double x, y, z;
    x = calseg(p[a], p[b]);
    y = calseg(p[b], p[c]);
    z = calseg(p[c], p[a]);
    double p = (x + y + z) / 2;
    return sqrt(p*(p - x)*(p - y)*(p - z));
}



int main(){

    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y ;

        double S = 0;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                for(int k = j + 1; k < n; k++)
                    S = max(S, getS(i, j, k));

        printf("%.1lf\n", S);
    }

    return 0;
}
