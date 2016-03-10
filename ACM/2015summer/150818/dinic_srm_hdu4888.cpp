#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lc(x) (x << 1)
#define  rc(x) (lc(x) + 1)
#define  lowbit(x) (x & (-x))
#define  PI    (acos(-1))
#define  lowbit(x) (x & (-x))
#define  LL    long long
#define  DB    double
#define  ULL   unsigned long long
#define  PII   pair<int, int>
#define  PLL   pair<LL, LL>
#define  PB    push_back
#define  MP    make_pair

using namespace std;

const int N = 1005;
const int M = 400 * 400 * 4 + 5;
const int INF = 0x3fffffff;
const int MOD = 1e9 + 7;
const DB  EPS = 1e-8;



struct edge{
    int u, v, next, flow;
}e[M];

int first[N], nw[N], level[N], ecnt, pre[M];

void addedge(int u, int v, int flow){
    e[++ ecnt].next = first[u], first[u] = ecnt, e[ecnt].u = u, e[ecnt].v = v, e[ecnt].flow = flow;
    e[++ ecnt].next = first[v], first[v] = ecnt, e[ecnt].u = v, e[ecnt].v = u, e[ecnt].flow = 0;
}

//========================================================
//========================================================

// by ztb by mt

bool Make_level(int S, int T){
     memset(level, 0, sizeof(level));
     memcpy(nw, first, sizeof(first));
     level[S] = 1;
     queue <int> Q;
     Q.push(S);
     while(!Q.empty()){
        int f = Q.front(); Q.pop();
        for(int i = first[f]; i != -1; i = e[i].next)
           if(e[i].flow && !level[e[i].v]){
              level[e[i].v] = level[f] + 1;
              Q.push(e[i].v);
              if(e[i].v == T) return true;
           }
     }
     return false;
}
int Maxflow(int S, int T){
    int i = S, j, flow = 0;
    while(level[S]){
        for(j = nw[i]; j != -1; j = e[j].next)
            if(e[j].flow && level[i] + 1 == level[e[j].v])
                 break;
        nw[i] = j;
        if(j != -1){
            i = e[j].v, pre[i] = j;
            if(i == T){
                int delta = INF;
                for(int k = T; k != S; k = e[pre[k]].u)
                    if(e[pre[k]].flow < delta)
                        delta = e[pre[k]].flow, i = e[pre[k]].u;
                flow += delta;
                for(int k = T; k != S; k = e[pre[k]].u)
                    e[pre[k] ^ 1].flow += delta, e[pre[k]].flow -= delta;
            }
        } else{
            level[i] = 0;
            i = e[pre[i]].u;
        }
    }
    return flow;
}
int Dinic(int S, int T){
    int res = 0;
    while(Make_level(S, T))
        res += Maxflow(S, T);
    return res;
}

//========================================================
//========================================================

int ans[N][N]; bool vis[N];

bool dfs(int u, int pre, int t){
    vis[u] = true;
    for(int i = first[u]; i != -1; i = e[i].next){
        int v = e[i].v;
        if(e[i].flow == 0 || v == pre) continue;
        if(v == t) return false;
        if(vis[v]) return false;
        // cout << u << ' ' << v << ' ' << pre << endl;
        if(!dfs(v, u, t)) return false;
    }
    vis[u] = false;
    return true;
}

int n, m, K;

bool check(){
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i ++){
        if(!vis[i]){
            if(!dfs(i, -1, i)) return false;
        }
    }
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i ++){
        int sum = 0;
        for(int j = first[i]; j != -1; j = e[j].next){
            int v = e[j].v;
            if(v == 0) continue;
            ans[i][v - n] = K - e[j].flow;
        }
    }
    return true;
}

int r, c;

int main(){

    while(scanf("%d%d%d", &n, &m, &K) == 3){

        memset(first, -1, sizeof(first));
        ecnt = -1;
        int sumr = 0, sumc = 0;

        for(int i = 1; i <= n; i ++) scanf("%d", &r), addedge(0, i, r), sumr += r;
        for(int i = 1; i <= m; i ++) scanf("%d", &c), addedge(n + i, n + m + 1, c), sumc += c;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++)
                addedge(i, n + j, K);
        int res = Dinic(0, n + m + 1);

        if(res != sumr || res != sumc){
            puts("Impossible"); continue;
        }
        if(!check()){
            puts("Not Unique");
        } else{
            puts("Unique");
            for(int i = 1; i <= n; i ++)
                for(int j = 1; j <= m; j ++)
                    printf("%d%c", ans[i][j], j == m ? '\n' : ' ');
        }

    }
}
