#include<map>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define LL long long




using namespace std;


struct items{
    int num;
    int v;
}it[10020];


bool cmp(struct items a, struct items b){
    if(a.num > b.num) return true;
    return false;
}

LL v[10020];

int main(){

    int t;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++){
        int m, n, c;
        memset(it, 0, sizeof(it));
        memset(v, 0, sizeof(v));
        scanf("%d%d%d", &m, &n, &c);
        for(int i = 0; i <= 10000; i++){
            it[i].num = 0;
            it[i].v = (i * i) % c;
        }
        for(int i = 1; i <= m; i++){
            int x;
            scanf("%d", &x);
            it[x].num++;
        }

        sort(it + 1, it + 1001, cmp);

        for(int i = 1;it[i].num > 0;i++){
            v[i] = v[i - 1] + it[i].v;
        }
//        for(int i = 1;it[i].num;i++){
//            printf("%d %d\n",it[i].num,it[i].v);
//        }
        LL ans = 0;

        for(int i = 1; it[i].num > 0; i++){
            LL tmp = it[i].num * v[i];
            if(tmp > ans)
                ans = tmp;
        }

        printf("Case %d: %I64d\n",ca, ans);
    }
    return 0;
}
