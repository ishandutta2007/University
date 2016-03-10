#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define maxn 1200000
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
            segsum[rt] = 4;
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


    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdin);
    #endif
    int n, m;
    while(scanf("%d%d", &n, &m))
    {   
        printf("!!!!\n");
        system("pause");
        if(n == 0 && m == 0) {    return 0;}
        segtree.clear();
        segtree.build(1, n, 1);
    //    segtree.check(1,n,1);
        char cmd[10];
        int x, y ,z;
        while(m--){
            scanf("%s", cmd);
            printf("p = [%c]\n", cmd[0]);
            if(cmd[0] == 'P'){
                scanf("%d%d%d",&x,&y,&z);
                printf("x=%d y=%d\n", x,y);
    //            printf("%d\n", segtree.querysum(x, y, 1, n, 1));
                segtree.update(x, y, 1 << (z - 1), 1, n, 1);
            }
            else{
                scanf("%d%d",&x,&y);
                printf("x=%d y=%d\n", x,y);
                int tmp = segtree.querysum(x, y, 1, n, 1);
                int nnum = 0;
                int ans;
                vector<int>ss;
                ss.clear();
                printf("tmp = %d\n", tmp);
                while(tmp > 0){
                    ans = tmp % 2;
                    nnum++;
                    if(ans == 1) ss.push_back(nnum);
                    tmp /= 2;
                }
                for(int i = 0; i < ss.size(); i++)
                    printf("%d%c",ss[i], i == ss.size() - 1? '\n' : ' ');
            }
        }
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}

