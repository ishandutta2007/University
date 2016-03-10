#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define LL long long

using namespace std;

int main(){

    int A, B, n;
    scanf("%d%d%d", &A, &B, &n);
    while(n--){
        int l, t, m;

        scanf("%d%d%d",&l, &t, &m);

        LL left = A + (l - 1) * B;
        if(t < left){
            printf("-1\n");
            continue;
        }
        int r = (t - A) / B + 1;

        int ans = l;
//        printf("%d %d\n",l, r);
        while(l < r){
            int mid = (l + r) / 2;

//            printf("%d %d %d\n", l, mid, r);
//            system("pause");
            LL right = A + (r - 1) * B;
            LL mmm = A + (mid - 1) * B;
            if((right + left) * (r - l + 1) / 2 <= m* t && ans < r) ans = r;
            if((mmm + left) * (mid - l + 1) / 2 <= m* t && ans < mid) ans = mid;
            if((mmm + left) * (mid - l + 1) / 2 <= m * t)
                l = mid + 1;
            else r = mid - 1;
        }


        /*
        if(l + m - 1 >= r){
            printf("%d\n", r);
            continue;
        }

        LL right = A + (r - 1) * B;
        while(true){
            if((right + left) * (r - l + 1) / 2 <= m * t)
                break;
            r--;
            right -= B;
        }
        */
        printf("%d\n", ans);
    }

    return 0;
}
