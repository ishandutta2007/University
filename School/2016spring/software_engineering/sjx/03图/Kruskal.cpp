#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

template < int maxN >
class Disjoint
{
private:
	int p[maxN], N;
public:
	inline void clear(int n) { N = n; for (int i = 1; i <= N; i++) p[i] = i; }
	inline int root(int i) { while (i != p[i]) i = p[i] = p[p[i]]; return i; }
	inline void unite(int a, int b) { p[root(a)] = root(b); }
	inline bool query(int a, int b) { return root(a) == root(b); }
};

const int MAXV = 2511, MAXE = 6211;
struct Edge
{
    int a, b, c;
    inline friend bool operator <(const Edge &A, const Edge &B)
    { return A.c < B.c; }
}e[MAXE]; int V, E;

Disjoint < MAXV > dis;
void Kruskal()
{
    int ans = 0;
    sort(e + 1, e + 1 + E);
    dis.clear(V);

    for (int i = 1; i <= E; i++)
        if (!dis.query(e[i].a, e[i].b))
        {
            printf("Edge from %d to %d, spend %d.\n", e[i].a, e[i].b, e[i].c);
            ans += e[i].c;
            dis.unite(e[i].a, e[i].b);
        }
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
        for (int i = 1; i <= E; i++)
            scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);

        Kruskal();
    }

    return 0;
}
