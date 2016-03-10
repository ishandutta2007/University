#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

const int INF = 0x7f7f7f7f;
template < typename T >
inline bool upd_min(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }

const int MAXV = 2511, MAXE = 6211 * 2;

struct Arc
{
	int dest, cost; Arc *next;
	inline Arc() { next = NULL; }
	inline Arc(int iD, int iC, Arc *iN)
	{ dest = iD, cost = iC, next = iN; }
}*adj[MAXV], Npool[MAXE], *Nptr; int V, E;

inline void insert(int start, int finish, int cost)
{ adj[start] = new (Nptr++) Arc(finish, cost, adj[start]); }

int sht[MAXV], preV[MAXV]; bool chk[MAXV];
inline int Prim()
{
    const int start = 1;

    int ret = 0;
	memset(sht, 0x7f, sizeof(sht)); sht[start] = 0;
	memset(chk, 0, sizeof(chk)); chk[start] = true;
	memset(preV, 0xff, sizeof(preV));

	int id = start;
	for (int i = 1; i < V; i++)
	{
		for (Arc *p = adj[id]; p; p = p->next)
            if (!chk[p->dest] && upd_min(sht[p->dest], p->cost))
                preV[p->dest] = id;

		int minValue = INF;
		for (int j = 1; j <= V; j++)
			if (!chk[j] && upd_min(minValue, sht[j]))
				id = j;
		chk[id] = true;
		ret += sht[id];
	}
	return ret;
}

void printResult(int ans)
{
    for (int i = 2; i <= V; i++)
        printf("Edge from %d to %d, spend %d.\n", preV[i], i, sht[i]);
    printf("All cost is %d.\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("mst.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (scanf("%d%d", &V, &E) > 0)
    {
        Nptr = Npool;
        memset(adj, 0, sizeof(adj));

        for (int i = 1; i <= E; i++)
        {
            int s, t, c;
            scanf("%d%d%d", &s, &t, &c);
            insert(s, t, c);
            insert(t, s, c);
        }
        printResult(Prim());
    }

    return 0;
}
