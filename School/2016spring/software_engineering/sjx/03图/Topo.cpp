#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

template < typename T >
inline bool upd_min(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }

const int MAXV = 2511, MAXE = 6211;
struct Arc
{
	int dest, cost; Arc *next;
	inline Arc() { next = NULL; }
	inline Arc(int iD, int iC, Arc *iN)
	{ dest = iD, cost = iC, next = iN; }
}*adj[MAXV], Npool[MAXE], *Nptr; int V, E;

int intp[MAXV];
inline void insert(int start, int finish, int cost)
{
    adj[start] = new (Nptr++) Arc(finish, cost, adj[start]);
    intp[finish]++;
}

queue < int > q;
int sht[MAXV];
void TopoDP()
{
    memset(sht, 0x7f, sizeof(sht));

    while (!q.empty())
        q.pop();
    for (int i = 1; i <= V; i++)
        if (intp[i] == 0)
        {
            q.push(i);
            sht[i] = 0;
        }

    while (!q.empty())
    {
        int i = q.front(); q.pop();
        printf("Now at %d.\n", i);
        for (Arc *p = adj[i]; p; p = p->next)
        {
            if (upd_min(sht[p->dest], sht[i] + p->cost))
                printf("Update path to %d as %d, the path costs %d.\n", p->dest, sht[p->dest], p->cost);
            if (--intp[p->dest] == 0)
            {
                q.push(p->dest);
                printf("Vertex %d degree becomes 0.\n", p->dest);
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= V; i++)
        printf("Shortest path to %d is %d.\n", i, sht[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("topo.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d%d", &V, &E) > 0)
    {
        Nptr = Npool;
        memset(adj, 0, sizeof(adj));
        memset(intp, 0, sizeof(intp));

        for (int i = 1; i <= E; i++)
        {
            int s, t, c;
            scanf("%d%d%d", &s, &t, &c);
            insert(s, t, c);
        }

        TopoDP();
    }
    return 0;
}
