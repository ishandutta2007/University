#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#define N 1006
using namespace std;

struct node{
    int x, y, w, next;
}e[100006];
int a[N], d[N], v[N], head[N],
    ans, tot, n, m, x, y, w;
queue <int> Q;
inline void addEdge(int x,int y,int w)
{
    tot++; e[tot].x = x; e[tot].y = y; e[tot].w = w;
    e[tot].next = head[x]; head[x] = tot;
}
void spfa(int S)
{
    int x, k;
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    Q.push(S); v[S] = 1;
    d[S] = 0;
    while(!Q.empty())
    {
        x = Q.front(); Q.pop();
        v[x] = 0; k = head[x];
        while(k != -1)
        {
            if(d[x]+e[k].w < d[e[k].y])
            {
                d[e[k].y] = d[x] + e[k].w;
                if(!v[e[k].y])
                {
                    Q.push(e[k].y);
                    v[e[k].y] = 1;
                }
            }
            k = e[k].next;
        }
    }
}
inline void init()
{
    memset(head, -1, sizeof(head));
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        init();	//别忘了初始化head数组
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &x, &y, &w);
            addEdge(x, y, w);
            addEdge(y, x, w);
        }
        int st, ed;
        scanf("%d%d", &st, &ed);
        spfa(st);
        int ans = d[ed];
        if(ans >= 0x3f3f3f3f) ans = -1;
        printf("%d\n", ans);
    }
}
