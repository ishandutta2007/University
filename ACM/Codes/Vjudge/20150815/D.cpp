#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define maxn 100200
#define ll long long


#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;


struct SegTree{


    int segsum[maxn<<2];
    int lazy[maxn<<2];

    void clear(){
        memset(segsum, 0, sizeof(segsum));
        memset(lazy, 0, sizeof(lazy));
    }
    void pushup(int rt){
        segsum[rt] = segsum[rt<<1] | segsum[rt<<1|1];
    }
    void build(int l, int r, int rt)
    {
        if(l == r){
            segsum[rt] = 1;
            return;
        }
        int m = (l+r)>>1;
        build(lson);
        build(rson);
        pushup(rt);
    }
    void pushdown(int rt, int m){
        lazy[rt << 1] = lazy[rt];
        lazy[rt << 1 | 1] = lazy[rt];
        segsum[rt << 1] = lazy[rt];
        segsum[rt << 1 | 1] = lazy[rt];
        lazy[rt] = 0;
    }
    void update(int L, int R, int c, int l, int r, int rt){
        if(L <= l && r <= R){
            lazy[rt] = c;
            segsum[rt] = c;
    //        printf("%d %d %d\n", l, r, segtree[rt]);
            return;
        }
        if(lazy[rt] != 0)
            pushdown(rt, r - l + 1);
        int m = (l + r) >> 1;
        if(L <= m) update(L, R, c, lson);
        if(R > m) update(L, R, c, rson);
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
    int querysum(int L, int R, int l, int r, int rt){
//        printf("L=%d   R=%d\n", L, R);
        if(L <= l && R >= r) {

//            printf("%d %d %d\n", L, R, segsum[rt]);
            return segsum[rt];
        }
        if(lazy[rt] != 0)
            pushdown(rt, r - l + 1);
        int m = (l+r)>>1;
        int tmp = 0;
        if(L <= m) tmp = tmp | querysum(L, R, lson);
        if(R > m) tmp = tmp | querysum(L, R, rson);
        return tmp;
    }
}segtree;




int main(){

    int n, t, o;
    scanf("%d%d%d",&n,&t,&o);
    segtree.clear();
    segtree.build(1, n, 1);
//    segtree.check(1,n,1);
    char cmd[2];
    int x, y ,z;
    while(o--){
        scanf("%s", cmd);
        if(cmd[0] == 'C'){
            scanf("%d%d%d",&x,&y,&z);
//            printf("x=%d y=%d\n", x,y);
//            printf("%d\n", segtree.querysum(x, y, 1, n, 1));
            if(x > y) swap(x, y);
            segtree.update(x, y, 1 << (z - 1), 1, n, 1);
        }
        else{
            scanf("%d%d",&x,&y);
            if(x > y) swap(x, y);
            int tmp = segtree.querysum(x, y, 1, n, 1);
            int ans = 0;
            while(tmp > 0){
                ans += tmp % 2;
                tmp /= 2;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}



