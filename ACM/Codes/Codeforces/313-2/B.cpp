#include<bits/stdc++.h>
#define LL long long

using namespace std;

int a[3], b[3];


int main(){


    for(int i = 0; i < 3; i++)
        scanf("%d %d", &a[i], &b[i]);

    bool flag = false;
    if(a[0] >= a[1] && b[0] >= b[1]){
        if(a[0] - a[1] >= a[2] && b[0] >= b[2]){
            flag = true;
        }
        if(b[0] - b[1] >= b[2] && a[0] >= a[2]){
            flag = true;
        }
        if(a[0] - a[1] >= b[2] && b[0] >= a[2]){
            flag = true;
        }
        if(b[0] - b[1] >= a[2] && a[0] >= b[2])
            flag = true;
    }
    if(a[0] >= b[1] && b[0] >= a[1]){
        if(a[0] - b[1] >= a[2] && b[0] >= b[2]){
            flag = true;
        }
        if(b[0] - a[1] >= b[2] && a[0] >= a[2]){
            flag = true;
        }
        if(a[0] - b[1] >= b[2] && b[0] >= a[2])
            flag = true;
        if(b[0] - a[1] >= a[2] && a[0] >= b[2])
            flag = true;
    }


    if(flag) printf("YES\n");
    else printf("NO\n");



    return 0;
}
