#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int de[100020];
int n;
bool ans = true;
vector<int>G[100020];
bool vis[100020];
void dfs(int x)
{
    vis[x] = true;
    for(int i = 0, len = G[x].size(); i < len;i++)
    {
        int to = G[x][i];
        if(!vis[to])
    }
}

int main()
{
    int x, y;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d", &x,&y);
        de[x]++;
        de[y]++;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int i;
    for(i = 1; i <= n;i++)
    {
        if(de[i] == 1)
            break;
    }
    vis[i] = true;
    dfs(i);


    return 0;
}