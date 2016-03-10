#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

#define INF 0x3f3f3f3f

using namespace std;


int dist[120][120];
int n;


void floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
    }
}

int main()
{

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;



        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                scanf("%d", &dist[i][j]);

                if(dist[i][j] == -1)
                    dist[i][j] = INF;
            }


        if(n == 1)
        {
            printf("1\n");
            continue;
        }

        int ans = 2;
        floyd();
        for(int i = 2; i < n; i++)
            if(dist[1][i] + dist[i][n] == dist[1][n])
                ans++;


        if(dist[1][n] == INF)
        {
            printf("0\n");
            continue;
        }

        // for(int i = 1; i <= n; i++)
        //     for(int j = 1; j <= n; j++)
        //         printf("\t%d%c", dist[i][j], j == n ? '\n' : ' ');

        printf("%d\n", ans);

    }


    return 0;
}
