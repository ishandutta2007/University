#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200002;
const int INF = 1e9;
const int MOD = 1000000;

struct Tnode{
    int c, lc, rc, fa;
} T[N];

int root;

void Update(int f, int x, int flag){
    if (x) T[x].fa = f;
    if (f){
        if (flag) T[f].lc = x; else T[f].rc = x;
    }
}
void Up(int x){
    int y, z;
    y = T[x].fa; z = T[y].fa;
    if (T[y].lc == x){
        Update(y, T[x].rc, 1);
        Update(x, y, 0);
        Update(z, x, T[z].lc == y);
    }else{
        Update(y, T[x].lc, 0);
        Update(x, y, 1);
        Update(z, x, T[z].lc == y);
    }
}
void Splay(int x, int &t){
    int y, z, limit;
    y = T[x].fa; z = T[y]. fa; limit = T[t].fa;
    while (y != limit){
        if (z != limit && (T[y].lc == x) == (T[z].lc == y)) Up(y);
        Up(x); y = T[x].fa; z = T[y].fa;
    }
    t = x;
}
void Insert(int i){
    int f = root;
    while (1){
        if (T[f].c >= T[i].c){
            if (!T[f].lc){
                Update(f, i, 1);
                break;
            }else f = T[f].lc;
        }else{
            if (!T[f].rc){
                Update(f, i, 0);
                break;
            }else f = T[f].rc;
        }
    }
    Splay(i, root);
}
int Pred(){
    int f = T[root].lc;
    while (T[f].rc) f = T[f].rc;
    return f;
}
int Succ(){
    int f = T[root].rc;
    while (T[f].lc) f = T[f].lc;
    return f;
}
void Delete(int &f){
    int l = T[f].lc, r = T[f].rc;
    T[l].fa = T[r].fa = 0;
    if (!l || !r){f = l + r; return;}
    int x = l;
    while (T[x].rc) x = T[x].rc; Splay(x, l);
    Update(x, r, 0);
    f = x;
}

int main(){
    int n, p, flag = 0, cnt = 0;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &p, &T[i].c);
        if (p == flag || !cnt){
            Update(i, 0, 0);
            if (!cnt) root = i; else Insert(i);
            cnt++;
            flag = p;
        }else{
            Insert(i);
            int r1 = Pred(), r2 = Succ();
            Delete(root);
            if (!r1) p = r2;
            else if (!r2) p = r1;
            else if (T[i].c - T[r1].c <= T[r2].c - T[i].c) p = r1;
            else p = r2;
            ans += abs(T[p].c - T[i].c);
            ans %= MOD;
            Splay(p, root);
            Delete(root);
            cnt--;
        }
    }
    printf("%lld\n", ans);
}
