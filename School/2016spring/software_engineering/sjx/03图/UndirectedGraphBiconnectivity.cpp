#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

typedef pair < int, int > II;
template < typename T >
inline bool upd_min(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }

const int MAXV = 1011, MAXE = 10111;
struct Arc
{
    int dest; Arc *next;
    inline Arc() { next = NULL; }
    inline Arc(int _dest, Arc *_next)
    { dest = _dest, next = _next; }
}*adj[MAXV], *Nptr, Npool[MAXE * 2]; int V, E;

inline void insert(int i, int j)
{
    adj[i] = new(Nptr++)Arc(j, adj[i]);
    adj[j] = new(Nptr++)Arc(i, adj[j]);
}

int DFN[MAXV], LOW[MAXV], index, Bcnt;
bool CutPoint[MAXV];

map < int, bool > belong[MAXV];
II Stack[MAXV]; int top;

inline void Domake(int v, int b)
{
    if (belong[v].find(b) == belong[v].end())
    {
        belong[v][b] = true;
        printf("%d ", v);
    }
}

map < II, bool > bridges;
inline void addBridge(int i, int j)
{
    if (i > j)
        swap(i, j);
    bridges[II(i, j)] = true;
}

void Tarjan(int i, int father)
{
    DFN[i] = LOW[i] = ++index;
    int child = 0;

    for (Arc *p = adj[i]; p; p = p->next)
        if (p->dest != father && DFN[p->dest] < DFN[i])
        {
            Stack[top++] = II(i, p->dest);
            if (!DFN[p->dest])
            {
                child++;
                Tarjan(p->dest, i);
                upd_min(LOW[i], LOW[p->dest]);

                if (father == -1 && child > 1 || father != -1 && LOW[p->dest] >= DFN[i])
                    CutPoint[i] = true;
                if (LOW[p->dest] > DFN[i])
                    addBridge(i, p->dest);
                if (LOW[p->dest] >= DFN[i])
                {
                    printf("Number %d GraphBiConnectivity: ", ++Bcnt);
                    II ip;
                    do
                    {
                        ip = Stack[--top];
                        Domake(ip.first, Bcnt); Domake(ip.second, Bcnt);
                        //printf("<%d,%d>", ip.first, ip.second);
                    }while (ip != II(i, p->dest));
                    printf("\n");
                }
            }
            else if (p->dest != father)
                upd_min(LOW[i], DFN[p->dest]);
        }

}

bool dfsWithoutBridgeVisited[MAXV];
void dfsWithoutBridge(int i)
{
    printf("%d ", i);
    dfsWithoutBridgeVisited[i] = true;
    for (Arc *p = adj[i]; p; p = p->next)
        if (i < p->dest && !dfsWithoutBridgeVisited[p->dest] && bridges.find(II(i, p->dest)) == bridges.end())
            dfsWithoutBridge(p->dest);
}

int main()
{
// #ifndef ONLINE_JUDGE
    // freopen("UndirectedGraphBiconnectivity.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
// #endif

    int Tc = 0;
    while (scanf("%d%d", &V, &E) > 0)
    {
        printf("Test Case %d:\nGraphBiConnectivity in Vertex\n", ++Tc);

        Nptr = Npool;
        memset(adj, 0, sizeof(adj));
        memset(CutPoint, 0, sizeof(CutPoint));
        for (int i = 0; i < MAXV; i++)
            belong[i].clear();
        bridges.clear();

        for (int i = 1; i <= E; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            insert(s, t);
        }

        top = Bcnt = index = 0;
        memset(DFN, 0, sizeof(DFN));
        memset(LOW, 0, sizeof(LOW));

        for (int i = 1; i <= V; i++)
            if (!DFN[i])
                Tarjan(i, -1);
        for (int i = 1; i <= V; i++)
        {
            printf("Vertex %d, DFN: %d, LOW %d", i, DFN[i], LOW[i]);
            if (CutPoint[i])
                printf(", Cut Point");
            printf("\n");
        }
        printf("\nGraphBiConnectivity in Edge\n");

        printf("Bridges: ");
        for (map < II, bool > :: iterator it = bridges.begin(); it != bridges.end(); it++)
            printf("%d-%d ", it->first.first, it->first.second);
        printf("\n");

        int edgeBiconnectivityCount = 0;
        memset(dfsWithoutBridgeVisited, 0, sizeof(dfsWithoutBridgeVisited));
        for (int i = 1; i <= V; i++)
            if (!dfsWithoutBridgeVisited[i])
            {
                printf("Number %d GraphBiConnectivity: ", ++edgeBiconnectivityCount);
                dfsWithoutBridge(i);
                printf("\n");
            }
        printf("\n");
    }

    return 0;
}
