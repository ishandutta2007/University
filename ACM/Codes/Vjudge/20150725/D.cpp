#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define ll long long

using namespace std;

int N, C;
ll pos[100020];


bool check(int x){


    int tmp = 1, pre = 0;

    for(int i = 1; i < N; i++)
    {
        if(pos[i] - pos[pre] >= x){
            tmp ++;
            pre = i;
            if(tmp >= C) return true;
        }
    }

    return false;
}



int main(){


    scanf("%d%d", &N, &C);

    for(int i = 0; i < N; i++)
        scanf("%I64d", &pos[i]);

    sort(pos, pos + N);

    ll low = 1, high = 1000000000;
    ll mid;
    ll ans = 1;


    while(low <= high){
        mid = (low + high) / 2;
        if(check(mid)){
            ans = max(ans, mid);
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    printf("%I64d\n", ans);


    return 0;
}
