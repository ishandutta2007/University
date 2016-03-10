#include "string.h"
#include "iostream"
#include "queue"
#include "iostream"
#include "algorithm"
#define __maxNodes 4020
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
char mp[50][20];
int mx[4] = {0,0,-1,1};
int my[4] = {1,-1,0,0};

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
    for (int u=1; u <= n * m; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}


bool __check(int x, int y)
{
    if(x >= 0 && x < n && y >= 0 && y < m && mp[x][y] == '*') return true;
    return false;
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
        sum = n * m * 2;
        for(int i = 0; i <= sum; i++) G[i].clear();
        edges.clear();
        tot = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++)
            scanf("%s", mp[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)if(mp[i][j] == '*')
            {   
                cnt++;
                for(int k = 0; k < 4; k++)if(__check(i + mx[k], j + my[k]))
                {
                    // cout << i + mx[k] << "    " << j + my[k] << endl;
                    edges.push_back(Edge(1 + i * m + j, 1 + m * n + (i + mx[k]) * m + j + my[k], 0));
                    G[1 + i*m +j].push_back(tot++);
                    edges.push_back(Edge(1 + m * n + (i + mx[k]) * m + j + my[k], 1 + i * m + j, 0));
                    G[1 + m * n + (i + mx[k]) * m + j + my[k]].push_back(tot++);
                }
            }
        int tmp = hungarian();

        cout << cnt - tmp + tmp / 2 << endl;

    }


    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}