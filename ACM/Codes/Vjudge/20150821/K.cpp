#include "string.h"
#include "iostream"
#include "queue"
#include "iostream"
#include "algorithm"
#define __maxNodes 250 * 250
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


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--)
    {   
        cin >> n >> m;
        sum = n * 2;
        for(int i = 0; i <= sum; i++) G[i].clear();
        edges.clear();
        tot = 0;
        int x, y;
        for(int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            edges.push_back(Edge(x, y + n, 0));
            G[x].push_back(tot++);
            edges.push_back(Edge(y + n, x, 0));
            G[y + n].push_back(tot++);
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

        cout << n - hungarian() << endl;

    }


    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}