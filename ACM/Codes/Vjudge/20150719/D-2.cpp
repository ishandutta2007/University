#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

#define LL long long


using namespace std;


LL ha[250020];
int A[520];
int B[520];
int C[520];
int cnt;


bool bi_search(int l, int r, LL v){

    int pos = lower_bound(ha, ha + cnt, v) - ha;
    if(ha[pos] == v) return true;
    return false;
}




int main(){


    int L, N, M;
    int kase = 0;
    while(scanf("%d%d%d",&L,&N,&M) == 3){
        kase ++;
        printf("Case %d:\n", kase);
        memset(ha, 0, sizeof(ha));
        cnt = 0;
        for(int i = 0; i < L; i++)
            scanf("%d", &A[i]);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &B[i]);
            for(int j = 0; j < L; j++)
                ha[cnt++] = A[j] + B[i];
        }

        sort(ha, ha + cnt);

        for(int i = 0; i < M; i++)
            scanf("%d", &C[i]);

        int q;
        bool isfound = false;
        scanf("%d", &q);
//        printf("%d\n", q);
        for(int i = 0; i < q; i++){
            LL x;
            scanf("%I64d", &x);
            for(int j = 0; j < M; j++){
                LL tmp = x - C[j];
                isfound = bi_search(0, cnt - 1, tmp);
                if(isfound) break;
            }
            if(isfound) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
