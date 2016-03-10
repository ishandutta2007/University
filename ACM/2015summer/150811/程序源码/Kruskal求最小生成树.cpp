//By Sss 2015.4.11
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100000;

struct Edge{
    int x, y, w; //边的起点，终点，边权
};

int cmp(const Edge & A, const Edge & B)
{
    return A.w < B.w;
}
struct Graph{
    int n; //顶点数
    int m; //边数
    Edge e[N];
    int fa[N];
    void init()
    {
        scanf("%d%d", &n, &m);
        if(n == 0) return ;
        for(int i = 0; i < m; i++)
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
        for(int i = 1; i <= n; i++) fa[i] = i;
    }

    //并查集，用于优化Kruskal
    int father(int x)
    {
        if(fa[x] == x) return x;
        return fa[x] = father(fa[x]);
    }

    //Kruskal法求最小生成树,适用于图稀疏时
    void Kruskal()
    {
        int sum = 0;
        cout << "---------Kruskal方法得到最小生成树如下--------" << endl;
        sort(e, e + m, cmp);
        for(int i = 0 ; i < m; ++i){
            int fx = father(e[i].x);
            int fy = father(e[i].y);
            if(fx == fy) continue; //判断两点是不是在同一块中
            fa[fx] = fy; //合并两块（此边为最小生成树边）
            sum += e[i].w;
            printf("%d %d %d\n", e[i].x, e[i].y, e[i].w);
        }
        printf("最小生成树的权值大小为：%d\n", sum);
    }
};

Graph* G;

int main()
{
    G = new Graph;
    while(true){
        G->init();
        if(G->n == 0) return 0;
        G->Kruskal();
    }
}
