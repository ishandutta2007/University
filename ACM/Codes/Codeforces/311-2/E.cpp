#include<bits/stdc++.h>
#define LL long long

using namespace std;

int cnt[100020];

struct leg{
    int len;
    int cost;
}l[100020];


bool cmp(struct leg a, struct leg b){
    return a.cost < b.cost;
}


int main(){

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i].len);
        cnt[l[i].len] ++;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i].cost);
    }

    sort(l, l + n);

    for(int i = 0; i < n; i++)
        printf("%d %d\n", l[i].cost, l[i].len);


    return 0;
}

