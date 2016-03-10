#include<bits/stdc++.h>
#define LL long long

using namespace std;

int a[200020];


int main(){

    int n, w;
    scanf("%d %d",&n, &w);

    for(int i = 0; i < 2 * n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n * 2);

    double g = a[0];
    double b = (double)a[n] / 2.0;


    double sum = min(g, b) * 3 * n;

//    printf("%f %f\n",sum, (double)w);
    printf("%f\n", min(sum, (double)w));

    return 0;
}
