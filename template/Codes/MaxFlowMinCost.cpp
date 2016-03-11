#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn=120;
const int oo = 0x3f3f3f3f;
 
struct Edge
{
    int u, v, cap, flow, cost;
    Edge(int u, int v, int cap, int f, int cost):u(u), v(v), cap(cap), flow(f), cost(cost) {}
};
 
struct MCMF
{
    int n, m, s, t;
    vector<Edge> edge;
    vector<int> G[maxn];
    int inq[maxn], d[maxn], p[maxn], a[maxn];
 
    void init(int n)
    {
        this->n=n;
        for(int i=0; i<=n; i++)G[i].clear();
        edge.clear();
    }
    void AddEdge(int u, int v, int cap, int cost)
    {
        edge.push_back(Edge(u, v, cap, 0, cost));
        edge.push_back(Edge(v, u, 0, 0, -cost));
        m=edge.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }
 
    bool SPFA(int s, int t, int& flow, int& cost)
    {
        memset(d, 0x3f, sizeof d);
        memset(inq, 0, sizeof inq);
        d[s]=0, inq[s]=1, p[s]=0, a[s]=oo;
 
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            inq[u]=0;
            for(int i=0; i<G[u].size(); i++)
            {
                Edge& e=edge[G[u][i]];
                if(e.cap>e.flow && d[e.v]>d[u]+e.cost)
                {
                    d[e.v]=d[u]+e.cost;
                    p[e.v]=G[u][i];
                    a[e.v]=min(a[u], e.cap-e.flow);
                    if(!inq[e.v])
                    {
                        q.push(e.v);
                        inq[e.v]=true;
                    }
                }
            }
        }
        if(d[t]==oo)return false;
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s)
        {
            edge[p[u]].flow+=a[t];
            edge[p[u]^1].flow-=a[t];
            u=edge[p[u]].u;
        }
        return true;
    }
 
    int Mincost(int s, int t, int& cost)
    {
        int flow=0;
        while(SPFA(s, t, flow, cost))
            ;
        return flow;
    }
} net;
 
int ord[55][55], sto[55][55];
 
int main()
{
    int n, m, k;
    while(~scanf("%d%d%d", &n, &m, &k) && n+m+k)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=k; j++)
                scanf("%d", &ord[i][j]);
        for(int i=1; i<=m; i++)
            for(int j=1; j<=k; j++)
                scanf("%d", &sto[i][j]);
        int S=0, T=n+m+2;
        int cost=0;
        for(int p=1; p<=k; p++)
        {
            int sum=0;
            net.init(n+m+10);
            for(int i=1; i<=n; i++)
            {
                net.AddEdge(i, T, ord[i][p], 0);
                sum+=ord[i][p];
            }
            for(int i=1; i<=m; i++)
                net.AddEdge(S, i+n, sto[i][p], 0);
            for(int i=1; i<=n; i++)
                for(int j=1; j<=m; j++)
                {
                    int x;
                    scanf("%d", &x);
                    net.AddEdge(n+j, i, oo, x);
                }
            if(~cost && net.Mincost(S, T, cost)<sum)
                cost=-1;
        }
        printf("%d\n", cost);
    }
    return 0;
}