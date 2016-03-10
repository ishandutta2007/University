#include<bits/stdc++.h>
#define LL long long

using namespace std;

LL F[20];
LL ans;
int a[30];
LL S;
int N,K;

map<pair<LL, int>, int> mp;


void init(){
    F[0] = 1;
    for(int i = 1; i < 20;i++){
        F[i] = F[i - 1] * i;
//        if(F[i] < 1e16 && F[i] > 0)
//            printf("%d, %I64d\n", i,F[i]);
    }
}

void dfs_1(int t, int k, LL s){
    if(k > K || s > S)
        return;
    if(t == (N + 1) / 2 + 1){
        mp[{s, k}] ++;
        return;
    }
    if(a[t] <= 18) dfs_1(t + 1, k + 1, s + F[a[t]]);
    dfs_1(t + 1, k, s + a[t]);
    dfs_1(t + 1, k, s);
}


void dfs_2(int t, int k, LL s) {
    if (k < 0 || S < s) return;
    if (t == N + 1) {
        for (int i = 0; i <= k; i++) ans += mp[{S - s, i}];
        return;
    }
    dfs_2(t + 1, k, s);
    dfs_2(t + 1, k, s + a[t]);
    if (a[t] <= 18) dfs_2(t + 1, k - 1, s + F[a[t]]);
}


int main(){

    init();

    scanf("%d%d%I64d",&N,&K,&S);
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    dfs_1(1, 0, 0);
    dfs_2((N + 1) / 2 + 1, K, 0);
    printf("%I64d\n", ans);
    return 0;
}
