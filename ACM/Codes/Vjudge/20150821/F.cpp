#include "string.h"
#include "iostream"
#include "queue"
#include "iostream"
#include "algorithm"
#define __maxNodes 100020
#include "stdio.h"


using namespace std;


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
// int num_right;
int matching[__maxNodes]; /* 存储求解结果 */
int check[__maxNodes];
int n, m, sum;
int tot;


/*DFS*/
bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); i++) { 
        int v = edges[G[u][i]].to;
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
    for (int u=1; u <= n; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int c;
    while(cin >> n)
    {   
        if(n == 0) return 0;
        cin >> m >> c;
        sum = n + m;
        for(int i = 0; i <= sum; i++) G[i].clear();
        edges.clear();
        tot = 0;
        int x, y, z;
        for(int i = 1; i <= c; i++)
        {
            cin >> z >> x >> y;
            if(x == 0 || y == 0) continue;
            edges.push_back(Edge(x, n + y, 0));
            G[x].push_back(tot++);
            edges.push_back(Edge(n + y, x, 0));
            G[n + y].push_back(tot++);
        }

        // for(int i = 1; i <= n + m; i++)
        // {
        //     cout << i << " : ";
        //     for(int j = 0; j < G[i].size(); j++)
        //     {
        //         cout << edges[G[i][j]].to << " ";
        //     }
        //     cout << endl;
        // }

        cout << hungarian() << endl;

    }


    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}