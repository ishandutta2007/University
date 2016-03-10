#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

template < typename T >
inline bool upd_min(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }

const int MAXV = 1011, MAXE = 10111;
struct Arc
{
    int dest; Arc *next;
    inline Arc() { next = NULL; }
    inline Arc(int _dest, Arc *_next)
    { dest = _dest, next = _next; }
}*adj[MAXV], *Nptr, Npool[MAXE]; int V, E;

inline void insert(int i, int j)
{ adj[i] = new(Nptr++)Arc(j, adj[i]); }

int DFN[MAXV], LOW[MAXV], Stap[MAXV], Belong[MAXV], index, Stop, Bcnt;
bool instack[MAXV];
void Tarjan(int i)
{
    DFN[i] = LOW[i] = ++index;
    instack[i] = true;
    Stap[++Stop] = i;
    for (Arc *p = adj[i]; p; p = p->next)
        if (!DFN[p->dest])
        {
            Tarjan(p->dest);
            upd_min(LOW[i], LOW[p->dest]);
        }
        else if (instack[p->dest])
            upd_min(LOW[i], DFN[p->dest]);
    if (DFN[i] == LOW[i])
    {
        int j;
        printf("Number %d connectivity: ", ++Bcnt);
        do
        {
            j = Stap[Stop--];
            instack[j] = false;
            Belong[j] = Bcnt;
            printf("%d ", j);
        }while (j != i);
        printf("\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("DirectedGraphStrongConnectivity.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int Tc = 0;
    while (scanf("%d%d", &V, &E) > 0)
    {
        printf("Test Case %d:\n", ++Tc);

        Nptr = Npool;
        memset(adj, 0, sizeof(adj));

        for (int i = 1; i <= E; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            insert(s, t);
        }

        Stop = Bcnt = index = 0;
        memset(DFN, 0, sizeof(DFN));
        for (int i = 1; i <= V; i++)
            if (!DFN[i])
                Tarjan(i);
        for (int i = 1; i <= V; i++)
            printf("Vertex %d, DFN: %d, LOW %d\n", i, DFN[i], LOW[i]);
        printf("\n");
    }

    return 0;
}
