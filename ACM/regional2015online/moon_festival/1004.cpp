#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>




using namespace std;


int trans[10020][60];
int acstd[10020];


int N, M, K;



int main()
{

    int T;
    scanf("%d", &T);
    for(int ka = 1; ka <= T; ka++)
    {
        scanf("%d%d%d", &N,&M,&K);

        memset(trans, 0, sizeof(trans));
        memset(acstd, 0, sizeof(acstd));

        int x, y;
        char ch[5];
        for(int i = 1; i <= K; i++)
        {
            scanf("%d", &x);
            acstd[x] += 1;
        }

        for(int i = 1; i <= M; i++)
        {
            scanf("%d%d%s", &x, &y, ch);
        }


    }



    return 0;
}