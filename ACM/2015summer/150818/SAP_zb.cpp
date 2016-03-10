#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5005;
const int M = 30005;
struct Enode{
    int y, c, next;
} e[M * 2];

int n, m, tot, head[N], now[N], h[N], vh[N], augc, found, flow;

void Addedge(int x, int y, int c){
    e[++tot].y = y; e[tot].c = c; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].c = 0; e[tot].next = head[y]; head[y] = tot;
}
void Init(){
    int x, y, c, i;
    scanf("%d%d", &n, &m);
    tot = -1; memset(head, -1, sizeof(head));
    for (i = 0; i < m; i++){
        scanf("%d%d%d", &x, &y, &c);
        Addedge(x, y, c);
    }
    memcpy(now, head, sizeof(head));
}

void Aug(int x, int st, int ed, int n){
    int p = now[x], minh = n - 1, augco = augc;
    if (x == ed){
        found = 1;
        flow += augc;
        return;
    }
    while (p != -1){
        if (e[p].c > 0 && h[e[p].y] + 1 == h[x]){
            augc = min(augc, e[p].c);
            Aug(e[p].y, st, ed, n);
            if (h[st] >= n) return;
            if (found) break;
            augc = augco;
        }
        p = e[p].next;
    }
    if (found){
        e[p].c -= augc;
        e[p ^ 1].c += augc;
    }else{
        p = head[x];
        while (p != -1){
            if (e[p].c > 0 && h[e[p].y] < minh){
                minh = h[e[p].y];
                now[x] = p;
            }
            p = e[p].next;
        }
        vh[h[x]] --;
        if (!vh[h[x]]) h[st] = n;
        h[x] = minh + 1;
        vh[h[x]] ++;
    }
}
void Maxflow(int st, int ed, int n){
    flow = 0;
    memset(h, 0, sizeof(h));
    memset(vh, 0, sizeof(vh));
    vh[0] = n;
    while (h[st] < n){
        found = 0;
        augc = 1 << 30;
        Aug(st, st, ed, n);
    }
}
int main(){
    Init();
    Maxflow(1, n, n);
    printf("%d\n", flow);
}
