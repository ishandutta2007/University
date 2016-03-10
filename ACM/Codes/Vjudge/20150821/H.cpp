#include "string.h"
#include "iostream"
#include "queue"
#include "iostream"
#include "algorithm"
#define __maxNodes 260000
#include "stdio.h"


using namespace std;

int n, m, sum;
struct Edge
{
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w):from(f), to(t), weight(w) {
        // if(f <= n * m)
        // printf("Add edge %d - > %d\n", f, t - n * m);
    }
};

struct Line{
    int r, s, e;
}line[__maxNodes];



int cnt_line;
vector<int> G[__maxNodes]; /* G[i] 存储顶点 i 出发的边的编号 */
vector<Edge> edges;
typedef vector<int>::iterator iterator_t;
int num_nodes;
int num_left;
// int num_right;
int matching[__maxNodes]; /* 存储求解结果 */
int check[__maxNodes];

int tot;
char mp[100][100];
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
bool vis1[100][100], vis2[100][100];

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


    while(cin >> n >> m)
    {   
        tot = 0;
        for(int i = 0; i < n; i++)
            scanf("%s", mp[i]);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)if(mp[i][j] == '*')
            {
                int ii = i, jj = j;
                while(ii - 1 >= 0 && mp[ii][j] == '*') ii--;
                while(jj - 1 >= 0 && mp[i][jj] == '*') jj--;

                edges.push_back(Edge(1 + i * m + jj, 1 + n * m + ii * m + j, 0));
                G[1+i*m+jj].push_back(tot++);
                edges.push_back(Edge(1 + n * m + ii * m + j, 1 + i * m + jj, 0));
                G[1+n*m+ii*m+j].push_back(tot++);
            }

        cout << hungarian() << endl;

    }


    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}