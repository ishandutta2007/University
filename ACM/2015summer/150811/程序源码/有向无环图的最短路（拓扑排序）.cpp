//By Sss 2015.4.12
//有向图无环路的最快算法，拓扑排序再扫描， o(n + m)
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
const int N = 100;
using namespace std;
struct Edge{
    int ed, w; //边的终点和边权
    Edge* next;
    Edge(int _ed, int _w, Edge* _next)
    {
        ed = _ed; w = _w; next = _next;
    }
};

struct Node{
    int du; //记录此点的入度
    Edge* e; //邻接表存储此点所连的边
    Node()
    {
        du = 0; e = NULL;
    }
};

int n, m, x, y, w, d[N];
Node* st[N];

int main()
{
    //freopen("test.in", "r", stdin);
    cout << "请输入点数和边数" << endl;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        st[i] = new Node();
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &x, &y, &w);
        st[x]->e = new Edge(y, w, st[x]->e);
        st[y]->du++; //更新其入度
    }
    stack<int> S; //存储入度为零的点
    queue<int> Q; //存储拓扑序列
    while(!S.empty()) S.pop();
    while(!Q.empty()) Q.pop();
    for(int i = 1; i <= n; i++)
        if(st[i]->du == 0) S.push(i);
    //根据入度进行拓扑排序
    while(!S.empty()){
        x = S.top(); S.pop();
        Q.push(x);
        for(Edge* p = st[x]->e; p != NULL; p = p->next)
        {
            st[p->ed]->du--;
            if(st[p->ed]->du == 0) S.push(p->ed);
        }
    }
    memset(d, 0x3f, sizeof(d));
    cout << "请输入起点：" << endl;
    cin >> y; d[y] = 0;
    //按拓扑序列以每个点为起点更新相连的点的最短距离
    while(!Q.empty()){
        x = Q.front(); Q.pop();
        for(Edge* p = st[x]->e; p != NULL; p = p->next)
            d[p->ed] = min(d[p->ed], d[x] + p->w);
    }
    printf("编号为%d的点到所有点的最短路径为\n", y);
    for(int i = 1; i <= n; i++)
        if(d[i] == 0x3f3f3f3f)
            printf("%d: oo\n", i);
        else
            printf("%d: %d\n", i, d[i]);
}
