#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

#define maxn 100010


#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;

long long ans;

struct SegTree{


    int segsum[maxn<<2];
    int lazy[maxn<<2];
    int vvis[maxn<<2];
    void clear(){
        memset(segsum, 0, sizeof(segsum));
        memset(lazy, 0, sizeof(lazy));
        memset(vvis, 0, sizeof(vvis));
        vvis[0] = 1;
    }
//    void pushup(int rt){
//        segsum[rt] = segsum[rt<<1] + segsum[rt<<1|1];
//    }
    void build(int l, int r, int rt)
    {
        if(l == r){
            return;
        }
        int m = (l+r)>>1;
        build(lson);
        build(rson);
//        pushup(rt);
    }

    void pushdown(int rt){
        lazy[rt << 1] = lazy[rt];
        lazy[rt << 1 | 1] = lazy[rt];
        segsum[rt << 1] = lazy[rt];
        segsum[rt << 1 | 1] = lazy[rt];
        lazy[rt] = 0;
        segsum[rt] = 0;
    }
    void update(int L, int R, int c, int l, int r, int rt){
        if(L <= l && r <= R){
            lazy[rt] = c;
            segsum[rt] = c;
    //        printf("%d %d %d\n", l, r, segtree[rt]);
            return;
        }
        if(lazy[rt] != 0)
            pushdown(rt);
        int m = (l + r) >> 1;
        if(L <= m) update(L, R, c, lson);
        if(R > m) update(L, R, c, rson);
//        pushup(rt);
    }
    void check(int l, int r, int rt)
    {

        if(segsum[rt] != 0 || l == r){

//            printf("id = %d, color = %d\n", l, segsum[rt]);
            if(vvis[segsum[rt]] == 0){
                vvis[segsum[rt]] = 1;
                ans++;
            }
            return;
        }
        if(lazy[rt] != 0)
            pushdown(rt);
        int m = (l+r)>>1;
        check(lson);
        check(rson);
    }

}segtree;


int l[maxn], r[maxn];
int all[maxn];
int cnt;
int vis[maxn <<2];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &l[i], &r[i]);
            if(vis[l[i]] == 0){
                vis[l[i]] = 1;
                all[++cnt] = l[i];
            }
            if(vis[r[i]] == 0){
                vis[r[i]] = 1;
                all[++cnt] = r[i];
            }
        }

        sort(all + 1, all + cnt + 1);
//        /*
        int add = 0;
        for(int i = 1; i < cnt; i++){
            if(all[i] + 1 < all[i + 1]){
                add++;
                all[cnt + add] = all[i] + 1;
            }

        }
        cnt += add;
        sort(all + 1, all + cnt + 1);
//        */

//        for(int i = 1; i <= cnt; i++)
//            printf("%d ", all[i]);
//
//
//        printf("\n================\n");

        segtree.clear();
        segtree.build(1, cnt, 1);
        for(int i = 1; i <= n; i++){
            int x = lower_bound(all + 1, all + cnt + 1, l[i]) - all;
            int y = lower_bound(all + 1, all + cnt + 1, r[i]) - all;

//            printf("%d %d\n", x, y);
            segtree.update(x, y, i, 1, cnt, 1);
        }
        ans = 0LL;
        segtree.check(1, cnt, 1);
        printf("%I64d\n", ans);

    }
    return 0;
}



