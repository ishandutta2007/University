#include<bits/stdc++.h>
#define LL long long

using namespace std;

int main(){


    int mmax[3];
    int mmin[3];
    int n = 0;

    scanf("%d", &n);

    int a, b;
    for(int i = 0; i < 3; i++){
        scanf("%d%d", &a, &b);
        mmax[i] = b - a;
        n -= a;
        mmin[i] = a;
    }

    int x, y, z;

    x = min(mmax[0], n);
    n -= x;
    y = min(mmax[1], n);
    n -= y;
    z = min(mmax[2], n);

    printf("%d %d %d\n",x + mmin[0],y + mmin[1], z + mmin[2]);

    return 0;
}
