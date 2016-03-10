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

const int MAXV = 1011;
int a[MAXV][MAXV], sht[MAXV][MAXV]; int V, E;

void Floyd()
{
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                upd_min(sht[i][j], sht[i][k] + sht[k][j]);
}

void printResult()
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
            printf("%d ", sht[i][j]);
        printf("\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("sht.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int TestCase = 0;
    while (scanf("%d%d", &V, &E) > 0)
    {
        printf("Case %d:\n", ++TestCase);
        scanf("%*d%*d");
        int directed;
        scanf("%d", &directed);

        memset(a, 0x3f, sizeof(a));
        memset(sht, 0x3f, sizeof(sht));

        for (int i = 1; i <= V; i++)
            sht[i][i] = 0;
        for (int i = 1; i <= E; i++)
        {
            int s, t, c;
            scanf("%d%d%d", &s, &t, &c);
            a[s][t] = c;
            upd_min(sht[s][t], c);

            if (directed == 0)
            {
                a[t][s] = c;
                upd_min(sht[t][s], c);
            }
        }

        Floyd();
        printResult();
        printf("\n");
    }

    return 0;
}
