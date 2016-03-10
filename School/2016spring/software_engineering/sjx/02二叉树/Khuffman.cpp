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

const int MAXN = 1011, MAXV = MAXN * 2;
struct Arc
{
    int dest; Arc *next;
    inline Arc() { next = NULL; }
    inline Arc(int _dest, Arc *_next)
    { dest = _dest, next = _next; }
}*adj[MAXV];

inline void insert(int i, int j)
{ adj[i] = new Arc(j, adj[i]); }

int N, K, a[MAXV], V, sum;
struct HeapNode
{
    int i, num;
    inline HeapNode() { }
    inline HeapNode(int _i, int _num)
    { i = _i, num = _num; }
    inline friend bool operator <(const HeapNode& a, const HeapNode& b)
    { return b.num < a.num; }
};

priority_queue < HeapNode > pq;
inline void CreateHuffman()
{
    while (pq.top().num != sum)
    {
        int ns = 0, ni = ++V;
        for (int i = 1; i <= K; i++)
        {
            HeapNode ip = pq.top(); pq.pop();
            insert(ni, ip.i);
            ns += ip.num;
        }
        a[ni] = ns;
        pq.push(HeapNode(ni, ns));
    }
}

char code[MAXN];
inline void _Display(int i, int depth)
{
    if (i <= N)
    {
        code[depth] = '\0';
        printf("%c, Code: %s, Freq: %d\n", i + 64, code, a[i]);
        return;
    }

    int order = 0;
    for (Arc *p = adj[i]; p; p = p->next)
    {
        code[depth] = (order++) + '0';
        _Display(p->dest, depth + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("Khuffman.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    memset(adj, 0, sizeof(adj));

    scanf("%d%d", &N, &K); sum = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", a + i);
        pq.push(HeapNode(i, a[i])); // a[i] > 0
        sum += a[i];
    }

    V = N;

    int K0 = (N - 1) % (K - 1);
    if (K0 != 0)
    {
        V += K - 1 - K0;
        for (int i = K - 1 - K0; i >= 1; i--)
        {
            a[i + N] = 0;
            pq.push(HeapNode(i + N, 0));
        }
    }

    CreateHuffman();
    _Display(V, 0);

    return 0;
}
