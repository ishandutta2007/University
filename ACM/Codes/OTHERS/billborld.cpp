#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

#define maxn 200020

using namespace std;


int segtree[maxn * 4];
int wide;

void pushup(int rt){
    segtree[rt] = max(segtree[rt<<1], segtree[rt << 1 | 1]);
}

void segupdate(int p, int c, int l, int r, int rt){
    if(l == r){
        segtree[rt] -= c;
        return;
    }
    int m = (r + l) >> 1;
    if(p <= m) segupdate(p, c, lson);
    else segupdate(p, c, rson);
    pushup(rt);
}


int segquery(int x, int l, int r, int rt){
    if(l == r){
        return l;
    }
    int m = (r + l) >> 1;
    if(segtree[rt << 1] >= x) return segquery(x, lson);
    return segquery(x, rson);
}

void segbuild(int l, int r, int rt){
    if(l == r)
    {
        segtree[rt] = wide;
        return;
    }
    int m = (l + r) >> 1;
    segbuild(lson);
    segbuild(rson);
    pushup(rt);
}


int main(){
    int n, ccmd;
    while(scanf("%d%d%d", &n, &wide, &ccmd) == 3){
        memset(segtree, 0, sizeof(segtree));
        if(n > ccmd) n = ccmd;
        segbuild(1, n, 1);
        int x;
        while(ccmd --){
            scanf("%d",&x);
            if(x > segtree[1])
                printf("-1\n");
            else{
                int p = segquery(x, 1, n, 1);
                printf("%d\n",p);
                segupdate(p, x, 1, n, 1);
            }
        }

    }
    return 0;
}
