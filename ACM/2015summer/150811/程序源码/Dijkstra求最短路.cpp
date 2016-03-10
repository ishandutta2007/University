//By Sss 2015.4.11
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 100000;
const int oo = 0x7fffffff;
struct Edge{
    int ed, w; //边的终点和边权
    Edge(int _ed, int _w){
        ed = _ed; w = _w;
    }
};
struct Edge2{
    int st, w; //边的起点和边权
};

struct Graph{
    int n; //顶点数
    int m; //边数
    vector<Edge*> st[N];
    Edge2 d[N]; //记录第i个点到当前已处理块的最短距离
    bool flag[N]; //标记当前点是否已处理完
    void init()
    {
        int x, y, w;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            st[i].clear();
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &x, &y, &w);
            st[x].push_back(new Edge(y, w));
            st[y].push_back(new Edge(x, w));
        }
    }

    void Prim()
    {
        cout << "--------Prim算法得最小生成树如下--------" << endl;
        memset(flag, 0, sizeof(flag));//最初都未处理
        memset(d, 0x3f, sizeof(d)); //最初距离全为无穷大

        flag[1] = true; //1号节点作为最初已处理的块(染色)
        //更新最初的d数组，其值为到1的最短距离
        for(unsigned int i = 0; i < st[1].size(); i++){
            d[st[1][i]->ed].w = st[1][i]->w;
            d[st[1][i]->ed].st = 1;   //记录其起点
        }

        int tot = n - 1; //最小生成树边有n-1条边
        int sum = 0;
        while(tot--){//首先找d数组中未被染色的点到已染色点的最小距离点
            int k, mint = oo;
            for(int i = 1; i <= n; i++)
                if(!flag[i] && d[i].w < mint)
                    k = i, mint = d[i].w;
            printf("%d %d %d\n", d[k].st, k, d[k].w);
            sum += d[k].w;
            flag[k] = true;//对k点染色
            for(unsigned int i = 0; i < st[k].size(); i++) //由k点去更新d数组
                if(d[st[k][i]->ed].w > st[k][i]->w){
                    d[st[k][i]->ed].w = st[k][i]->w;
                    d[st[k][i]->ed].st = k;
                }
        }
        printf("最小生成树的权值大小为：%d\n", sum);
    }
};

Graph* G;

int main()
{
    G = new Graph;
    G->init();
    G->Prim();

}
