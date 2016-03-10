#include "string.h"
#include "iostream"
#include "queue"
#include "iostream"
#include "algorithm"
#define __maxNodes 150000
#include "stdio.h"
#include "math.h"

using namespace std;


struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w):from(f), to(t), weight(w) {
        // printf("add edge %d -> %d\n", f, t);
    }
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
int start[520][2], dest[520][2];
int time[520];



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


int caltime(int x, int y)
{
    return abs(dest[x][0] - start[x][0]) + abs(dest[x][1] - start[x][1]) + abs(start[y][0] - dest[x][0]) + abs(start[y][1] - dest[x][1]);
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
        cin >> n;
        sum = n * 2;
        for(int i = 0; i <= sum; i++) G[i].clear();
        edges.clear();
        tot = 0;
        int hh, mm;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d:%d%d%d%d%d", &hh, &mm, &start[i][0], &start[i][1], &dest[i][0], &dest[i][1]);
            time[i] = hh * 60 + mm;
        }

        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
            {
                if(time[i] + caltime(i, j) < time[j])
                {
                    edges.push_back(Edge(i, n + j, 0));
                    G[i].push_back(tot++);
                    edges.push_back(Edge(n + j, i, 0));
                    G[n + j].push_back(tot++);
                }
            }

        cout << n - hungarian() << endl;

    }


    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}