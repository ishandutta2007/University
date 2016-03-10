#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>

#define maxn 10000020


using namespace std;

int Hash[50000];
bool vis[maxn];
int l[50000], r[50000];
int tot;
int ans;
int segtree[50000];

void update(int L, int R, int c, int l , int r, int rt){

//    printf("%d %d %d %d %d %d\n", L, R, c, l, r, rt);

    if(L <= l && r <= R){
        segtree[rt] = c;
        return;
    }

    if(segtree[rt] != 0){
        segtree[rt*2] = segtree[rt*2+1] = segtree[rt];
    }
    segtree[rt] = 0;
    int m = (l + r) / 2;
    if(L <= m) update(L, R, c, l, m, rt*2);
    if(R > m) update(L, R, c, m+1, r, rt*2+1);
}

void calans(int l, int r, int rt){


//    printf("%d %d %d %d\n",l, r, rt, segtree[rt]);
    if(segtree[rt] > 0){
        int x = segtree[rt];
        if(vis[x] == false){
            vis[x] = true;
            ans++;
        }
        return;
    }
//    if(l >= r) return;
    if(l >= r) return;
    int m = (l+r)/2;
    if(l <= m) calans(l, m, rt*2);
    if(m < r) calans(m+1,r, rt*2+1);
    return;
}



int main(){

    int t;
    int n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        tot = 0;
        memset(vis, 0, sizeof(vis));
        memset(Hash, 0, sizeof(Hash));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d",&l[i], &r[i]);
            if(vis[l[i]] == false){
                vis[l[i]] = true;
                Hash[++tot] = l[i];
            }
            if(vis[r[i]] == false){
                vis[r[i]] = true;
                Hash[++tot] = r[i];
            }
        }
        sort(Hash + 1, Hash + tot + 1);
        int add = 0;
        for(int i = 1; i < tot; i++){
            if(Hash[i] + 1 < Hash[i + 1]){
                add++;
                Hash[tot + add] = Hash[i] + 1;
            }
        }
        tot += add;
        sort(Hash + 1, Hash + tot + 1);


        memset(segtree, 0, sizeof(segtree));
        for(int i = 1; i <= n; i++){
            int x = lower_bound(Hash + 1, Hash + tot + 1, l[i]) - Hash;
            int y = lower_bound(Hash + 1, Hash + tot + 1, r[i]) - Hash;

            update(x, y, i, 1, tot, 1);

        }

        memset(vis, 0, sizeof(vis));
        ans = 0;
        calans(1, tot, 1);
        printf("%d\n", ans);
    }




}

