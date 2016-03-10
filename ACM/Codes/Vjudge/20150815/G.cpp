#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 100200
#define ll long long


#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;
int n, q;


struct SegTree{


    ll segsum[maxn<<2];
    ll lazy[maxn<<2];

    void clear(){
        memset(segsum, 0, sizeof(segsum));
        for(int i = 1; i <= n * 4; i ++)
            lazy[i] = 1LL;
    }
    void pushup(int rt){
        segsum[rt] = max(segsum[rt<<1] , segsum[rt<<1|1]);
    }
    void build(int l, int r, int rt)
    {
        if(l == r){
            segsum[rt] = 1LL;
            return;
        }
        int m = (l+r)>>1;
        build(lson);
        build(rson);
        pushup(rt);
    }
    void pushdown(int rt, int m){
        lazy[rt << 1] *= lazy[rt];
        lazy[rt << 1 | 1] *= lazy[rt];
        segsum[rt << 1] *= lazy[rt];
        segsum[rt << 1 | 1] *= lazy[rt];
        lazy[rt] = 1LL;
    }
    void update(int L, int R, int l, int r, int rt){
        if(L <= l && r <= R){
            lazy[rt] *= 2;
            segsum[rt] *= 2;
    //        printf("%d %d %d\n", l, r, segtree[rt]);
            return;
        }
        if(lazy[rt] != 0)
            pushdown(rt, r - l + 1);
        int m = (l + r) >> 1;
        if(L <= m) update(L, R, lson);
        if(R > m) update(L, R, rson);
        pushup(rt);
    }
    void check(int l, int r, int rt)
    {

        printf("l=%d r=%d rt=%d sum=%d\n", l,r,rt,segsum[rt]);
        if(l == r){
            return;
        }
        int m = (l+r)>>1;
        check(lson);
        check(rson);
    }
    ll querysum(int L, int R, int l, int r, int rt){
//        printf("L=%d   R=%d\n", L, R);
        if(L <= l && R >= r) {

//            printf("%d %d %I64d\n", L, R, segsum[rt]);
            return segsum[rt];
        }
        if(lazy[rt] != 0)
            pushdown(rt, r - l + 1);
        int m = (l+r)>>1;
        ll tmp = 0;
        if(L <= m) tmp += querysum(L, R, lson);
        if(R > m) tmp += querysum(L, R, rson);
        return tmp;
    }
}segtree;




int main(){


    int t;
    scanf("%d", &t);
for(int ka = 1; ka <= t; ka++){

    printf("Case #%d:\n", ka);
    scanf("%d%d",&n,&q);
    segtree.clear();
    segtree.build(1, n, 1);
//    segtree.check(1,n,1);
    char cmd[2];
    int x, y;
    while(q--){
        scanf("%s%d%d", cmd, &x, &y);
        if(cmd[0] == 'D'){
            segtree.update(x, y, 1, n, 1);
        }
        else{
            printf("%I64d\n", segtree.querysum(x, y, 1, n, 1));
        }
    }

    return 0;
}





}


