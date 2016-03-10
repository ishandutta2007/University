#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


const int __maxNodes = 300;
// 顶点、边的编号均从 0 开始
struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};

vector<int> G[__maxNodes]; /* G[i] 存储顶点 i 出发的边的编号 */
vector<Edge> edges;
typedef vector<int>::iterator iterator_t;
int num_nodes;
int num_left;
int num_right;
int matching[__maxNodes]; /* 存储求解结果 */
int check[__maxNodes];




/*DFS*/
bool dfs(int u)
{
    for (iterator_t i = G[u].begin(); i != G[u].end(); ++i) { 
        int v = edges[*i].to;
        if (!check[v]) {     // 要求不在交替路中
            check[v] = true; // 放入交替路
            if (matching[v] == -1 || dfs(matching[v])) {
                // 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false; // 不存在增广路，返回失败
}

int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=0; u < num_left; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}



/*BFS*/
queue<int> Q;
int prev[__maxNodes];
int Hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    memset(check, -1, sizeof(check));
    for (int i=0; i<num_left; ++i) {
        if (matching[i] == -1) {
            while (!Q.empty()) Q.pop();
            Q.push(i);
            prev[i] = -1; // 设 i 为路径起点
            bool flag = false; // 尚未找到增广路
            while (!Q.empty() && !flag) {
                int u = Q.front();
                for (iterator_t ix = G[u].begin(); ix != G[u].end() && !flag; ++ix) {
                    int v = edges[*ix].to;
                    if (check[v] != i) {
                        check[v] = i;
                        Q.push(matching[v]);
                        if (matching[v] >= 0) { // 此点为匹配点
                            prev[matching[v]] = u;
                        } else { // 找到未匹配点，交替路变为增广路
                            flag = true;
                            int d=u, e=v;
                            while (d != -1) {
                                int t = matching[d];
                                matching[d] = e;
                                matching[e] = d;
                                d = prev[d];
                                e = t;
                            }
                        }
                    }
                }
                Q.pop();
            }
            if (matching[i] != -1) ++ans;
        }
    }
    return ans;
}


int mp[__maxNodes][__maxNodes];
int rt[__maxNodes];
int rel[__maxNodes][2];


int root(int a){
    while(a != rt[a])
        a = rt[a] = rt[rt[a]];
    return a;
}
int main()
{

    int T;
    int n, m, f;
    int x, y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &f);

        memset(mp, 0, sizeof(mp));
        for(int i = 0; i <= n ;i++)
            G[i].clear();
        edges.clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &rel[i][0], &rel[i][1]);
        }
        for(int i = 1; i <= n; i++)
        {
            rt[i] = i;
        }

        int rx, ry;
        for(int i = 0; i < f; i++)
        {
            scanf("%d%d",&x,&y);
            rx = root(x);
            ry = root(y);
            if(rx != ry)
            {
                rt[rx] = ry;
            }
        }


        for(int i = 0; i < m; i++)
        {
            int ri = root(rel[i][0]);
            mp[ri][rel[i][1]] = 1;
        }
        num_nodes = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int ri = root(i);
                if(mp[ri][j] == 1)
                {
                    edges.push_back(Edge(i-1, j-1, 1));
                    G[i-1].push_back(num_nodes++);
                    edges.push_back(Edge(j-1, i-1, 1));
                    G[j-1].push_back(num_nodes++);
                }
            }
        }

        


    }
    return 0;
}

