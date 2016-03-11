#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define maxn 50020
using namespace std;
struct ST
{
    int high[maxn][33],low[maxn][33], a[maxn];
    int n;
    int depth;
    void clear()
    {
        n = 0;
        depth = 1;
        memset(high, 0, sizeof(high));
        memset(low, 0, sizeof(low));
        memset(a, 0, sizeof(a));
    }
    void rmq()
    {
        for(int j = 1; j <= 20; j++)
        for(int i = 1; i <= n; i++)if(i + (1 << j) - 1 <= n){
            high[i][j] = max(high[i][j - 1], high[i + (1 << (j - 1))][j - 1]);
            low[i][j] = min(low[i][j - 1], low[i + (1 << (j - 1))][j - 1]);
        }

    }
    void init()
    {
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            high[i][0] = low[i][0] = a[i];
        }
    }
    int query(int s, int e)
    {
        int k = log2(e - s + 1);
//        printf("max : %d , min : %d\n",max(high[s][k], high[e - (1 << k) + 1][k]),  min(low[s][k], low[e - (1 << k) + 1][k]));
        return max(high[s][k], high[e - (1 << k) + 1][k]) - min(low[s][k], low[e - (1 << k) + 1][k]);
    }
    void check()
    {
        for(int j = 0; j <= 3; j++)
            for(int i = 1; i <= n; i++)
                printf("%d%c", low[i][j], i == n? '\n':' ');
        printf("\n\n");
    }
}st;
int main()
{
    st.clear();
    int m;
    scanf("%d%d", &st.n, &m);
    st.init();
    st.rmq();
//    st.check();
    int s, e;
    while(m--)
    {
        scanf("%d%d",&s,&e);
        printf("%d\n",st.query(s, e));
    }
    return 0;
}
