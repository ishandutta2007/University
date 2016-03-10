#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXE = 2222, MAXV = 1111;
struct Arc
{
    int dest;
    Arc *next;
    inline Arc() {}
    inline Arc(const int &_dest, Arc *_next):dest(_dest), next(_next) {}
}Npool[MAXE], *Nptr = Npool, *adj[MAXV];
vector<int> com[MAXV];
int n, m, dfn[MAXV], low[MAXV], belong[MAXV], index, cnt;
bool instack[MAXV];
stack<int> s;
inline void addEdge(const int &start, const int &finish)
{
    adj[start] = new(Nptr++)Arc(finish, adj[start]);
}

inline void tarjan(const int &i)
{
    dfn[i] = low[i] = ++index;
    instack[i] = true;
    s.push(i);
    for (Arc *p = adj[i]; p; p = p->next)
    {
        if (!dfn[p->dest])
        {
            tarjan(p->dest);
            if (low[i] > low[p->dest])
                low[i] = low[p->dest];
        }
        else if (instack[p->dest])
            if (low[i] > dfn[p->dest])
                low[i] = dfn[p->dest];
    }
    if (dfn[i] == low[i])
    {
        com[++cnt].clear();
        int j;
        do
        {
            j = s.top();
            s.pop();
            instack[j] = false;
            com[cnt].push_back(j);
            belong[j] = cnt;
        }while (j != i);
    }
}


int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(adj, 0, sizeof(adj));
        memset(instack, false, sizeof(instack));
        memset(dfn, 0, sizeof(dfn));
        index = 0, Nptr = Npool, cnt = 0;
        while (!s.empty())
            s.pop();
        for (int i = 1; i <= m; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            addEdge(s, t);
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
#define miao
#ifdef miao
        for (int i = 1; i <= n; i++)
            printf("%d, ", belong[i]);
        putchar('\n');
        for (int i = 1; i <= cnt; i++)
        {
            sort(com[i].begin(), com[i].end());
            for (vector<int>::iterator j = com[i].begin(); j != com[i].end(); j++)
                printf("%d, ", *j);
            putchar('\n');
        }
#endif // miao

    }
    return 0;
}
