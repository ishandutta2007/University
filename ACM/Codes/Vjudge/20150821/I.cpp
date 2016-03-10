#include "string.h"
#include "iostream"
#include "queue"
#include "iostream"
#include "algorithm"
#define __maxNodes 4020
#include "stdio.h"


using namespace std;

int matching[__maxNodes]; /* 存储求解结果 */
int check[__maxNodes];
int n, m, c;
bool G[__maxNodes][__maxNodes];

bool dfs(int u)
{
    for(int v = 1; v <= m; v++)
    {
        if(!check[v] && G[u][v])
        {
            check[v] = true;
            if(matching[v] == -1 || dfs(matching[v]))
            {
                matching[v] = u;
                // matching[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=1; u <= n; ++u) {
        // if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        // }
    }
    return ans;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int ka = 0;
    while(cin >> n >> m >> c && (n + m + c))
    {   
        memset(G, true, sizeof(G));
        int x, y;
        for(int i = 1; i <= c; i++)
        {
            cin >> x >> y;
            G[x][y] =  false;
        }
        printf("Case %d: %d\n", ++ka, m + n - hungarian());

    }


    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}