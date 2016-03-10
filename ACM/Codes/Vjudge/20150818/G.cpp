#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>

#define maxn 50020
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
// #define ONLINE_JUDGE
using namespace std;

int ans;
int n;
int y[maxn], rain[maxn];
int cnt;

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
            cnt++;
            scanf("%d%d",&y[cnt], &rain[cnt]);
            segmax[rt] = rain[cnt];
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
        int tmp = 1000000020;
        if(L <= m) tmp = min(querymin(L, R, lson),tmp);
        if(R > m) tmp = min(querymin(L, R, rson), tmp);
        return tmp;
    }
}segtree;




int main(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    segtree.clear();
    scanf("%d", &n);
    segtree.build(1, n, 1);

    int m;
    scanf("%d", &m);
    int xx, yy;
    int posx, posy;
    while(m--)
    {
        scanf("%d%d", &xx, &yy);
        if(yy < xx)
        {
            printf("false\n");
            continue;
        }
        posx = lower_bound(y + 1, y + n + 1, xx) - y;
        posy = lower_bound(y + 1, y + n + 1, yy) - y;
        // printf("%d %d\n", posx, posy);
        if(y[posx] != xx && y[posy] != yy)
        {
            printf("maybe\n");
            continue;
        }
        else if(y[posx] == xx && y[posy] != yy)
        {
            int l = posx + 1;
            int r = posy - 1;
            if(l > r)
            {
                printf("maybe\n");
                continue;
            }
            int maxrain = segtree.querymax(l, r, 1, n, 1);
            if(maxrain >= rain[posx])
            {
                printf("false\n");
                continue;
            }
            else{
                printf("maybe\n");
                continue;
            }
        }
        else if(y[posx] != xx && y[posy] == yy)
        {
            int l = posx;
            int r = posy - 1;
            if(l > r)
            {
                printf("maybe\n");
                continue;
            }
            int maxrain = segtree.querymax(l, r, 1, n, 1);
            if(maxrain >= rain[posy])
            {
                printf("false\n");
                continue;
            }else{
                printf("maybe\n");
                continue;
            }
        }
        else if(y[posx] == xx && y[posy] == yy)
        {

            if(rain[posx] < rain[posy])
            {
                printf("false\n");
                continue;
            }

            int l = posx + 1;
            int r = posy - 1;
            if(l > r)
            {
                if(posy - posx == yy - xx)
                    printf("true\n");
                else printf("maybe\n");
                continue;
            }
            int maxrain = segtree.querymax(l, r, 1, n, 1);
            if(maxrain >= rain[posy])
            {
                printf("false\n");
                continue;
            }
            if(posy - posx == yy - xx)
            {
                printf("true\n");
                continue;
            }
            else
            {
                printf("maybe\n");
                continue;
            }
        }


    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}
