#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 100020

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;


struct SegTree{


    int segmax[maxn<<2];
    int segmin[maxn<<2];

    void clear(){
        memset(segmax, 0, sizeof(segmax));
        memset(segmin, 0, sizeof(segmin));
    }
    void pushup(int rt){
        segmax[rt] = max(segmax[rt<<1], segmax[rt<<1|1]);
        segmin[rt] = min(segmin[rt<<1], segmin[rt<<1|1]);
    }
    void build(int l, int r, int rt)
    {
        if(l == r){
            scanf("%d",&segmax[rt]);
            segmin[rt] = segmax[rt];
            return;
        }
        int m = (l+r)>>1;
        build(lson);
        build(rson);
        pushup(rt);
    }
    void check(int l, int r, int rt)
    {

        printf("l=%d r=%d rt=%d max=%d\n", l,r,rt,segmax[rt]);
        if(l == r){
            return;
        }
        int m = (l+r)>>1;
        check(lson);
        check(rson);
    }
    int querymax(int L, int R, int l, int r, int rt){

        if(L <= l && R >= r) {
            return segmax[rt];
        }

        int m = (l+r)>>1;
        int tmp = -0x7f7f7f7f;
        if(L <= m) tmp = max(querymax(L, R, lson),tmp);
        if(R > m) tmp = max(querymax(L, R, rson), tmp);
        return tmp;
    }
    int querymin(int L, int R, int l, int r, int rt){
        if(L <= l && R >= r) return segmin[rt];

        int m = (l+r)>>1;
        int tmp = 0x7f7f7f7f;
        if(L <= m) tmp = min(querymin(L, R, lson),tmp);
        if(R > m) tmp = min(querymin(L, R, rson), tmp);
        return tmp;
    }
}segtree;




int main(){

    int n, q;
    scanf("%d%d",&n,&q);
    segtree.clear();
    segtree.build(1, n, 1);
//    segtree.check(1,n,1);
    int x,y;


    while(q--){
        scanf("%d%d",&x, &y);
        printf("%d\n", segtree.querymax(x, y, 1, n, 1) - segtree.querymin(x, y, 1, n, 1));
    }

    return 0;
}
