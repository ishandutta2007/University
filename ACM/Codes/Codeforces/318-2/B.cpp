#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

#define __maxn 0x3f3f3f3f3f
using namespace std;

struct Edge{
    int u, v;
    Edge(int u, int v):u(u),v(v){}
};

int G[4020][4020];
int de[4020];

vector<Edge>edges;
int n, m;
int main()
{
    scanf("%d%d", &n,&m);
    int x, y;
    for(int i = 0; i < m;i++)
    {
        scanf("%d%d",&x,&y);
        edges.push_back(Edge(x, y));
        G[x][y] = G[y][x] = 1;
        de[x]++;
        de[y]++;
    }
    int ans = 0x7f7f7f7f;
    for(int i = 0,len = edges.size(); i<len;i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        for(int j = 1; j <= n; j++)if(j != u && j != v)
        {
            if(G[j][v] && G[j][u] && de[j] + de[u] + de[v] < ans)
                ans = de[j] + de[u] + de[v];
        }

    }

    if(ans == 0x7f7f7f7f)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", ans-6);
    }
    return 0;
}