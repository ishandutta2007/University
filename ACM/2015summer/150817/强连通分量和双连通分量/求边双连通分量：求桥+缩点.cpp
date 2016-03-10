
/*
(1) n 为顶点数, 标号从 1 开始
(2) c 为原图的邻接表, g 为 E_BCC 图的邻接表
(3) num[u] 表示原图中的点 u 属于新图中的第 num[u] 个 E_BCC
(4) edge[] 存储所有的桥
(5) 注意 pool[M] 要开得足够大以容得下新旧两个图中所有的边
(6) E_BCC 图中去掉了自环 ( 显然不存在多重边 )
*/

#include <cstdio>
#include <cstring>

const int N = 505;
const int M = 20005;

struct List {
    int v, id;
    List *next;
} pool[M], *c[N], *g[N], *pp;

inline void add_edge(int u, int v, int id, List *c[])
{
    pp->v = v;
    pp->id = id;
    pp->next = c[u];
    c[u] = pp ++;
}

struct Edge {
    int u, v;
} edge[M];

int n, m, label, tot, top;
int low[N], dfn[N], num[N], stack[N];
bool eflag[M];

void E_BCC_VISIT(int u)
{
    low[u] = dfn[u] = label ++;
    stack[++ top] = u;

    for(List *p = c[u]; p; p = p->next) {
        int v = p->v;
        if(eflag[p->id])    continue;
        eflag[p->id] = true;
        if(dfn[v]) { low[u] <?= dfn[v]; continue; }
        E_BCC_VISIT(v);
        low[u] <?= low[v];
        if(low[v] > dfn[u]) {
            edge[m].u = u;
            edge[m ++].v = v;
            ++ tot;
            do {
                num[stack[top]] = tot;
            } while( stack[top --] != v );
        }
    }
}

void E_BCC()
{
    int i;

    tot = 0;
    m = 0;
    for(i = 1; i <= n; ++ i)    dfn[i] = 0, num[i] = -1;
    for(i = 0; i < m; ++ i)     eflag[i] = false;
    for(i = 1; i <= n; ++ i)
        if(dfn[i] == 0) {
            label = 1;
            top = -1;
            E_BCC_VISIT(i);
            ++ tot;
            while( top >= 0 ) {
                num[stack[top]] = tot;
                -- top;
            }
        }

    for(i = 1; i <= tot; ++ i)  g[i] = NULL;
    for(i = 1; i <= n; ++ i) {
        int u = num[i];
        for(List *p = c[i]; p; p = p->next) {
            int v = num[p->v];
            if(u != v)  add_edge(u, v, 0, g);
        }
    }
}

int main()
{
    int i, j, k;

    while( scanf("%d %d", &n, &m) == 2 ) {
        for(i = 1; i <= n; ++ i)    c[i] = NULL;
        pp = pool;
        for(k = 0; k < m; ++ k) {
            scanf("%d %d", &i, &j);
            add_edge(i, j, k, c);
            add_edge(j, i, k, c);
        }

        E_BCC();
    }

    return 0;
}
