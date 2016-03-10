#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1000;
const int oo = 10000000;

int n, m, x, y, w, d[N][N];
void Floyed()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int Check()
{
    for(int i = 1; i <= n; i++)
        if(d[i][i] < 0){
        //第i个点到第i个点距离被更新了，存在负权回路
            return false;
        }
    return true;
}

int main()
{
    freopen("H:\\Code\\test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= n; i++)
        d[i][i] = 0;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &w);
        d[x][y] = w;
    }
    Floyed();

    if(Check() == false){
        printf("存在负权回路！\n");
        return 0;
    }
    cout << "请输入起点:";
    cin >> x;
    cout << endl;
    printf("编号为%d的点到其他点的最短路为\n", x);
    for(int i = 1; i <= n; i++)
        if(d[x][i] > oo)
            printf("%d->%d: oo\n", x, i);
        else
            printf("%d->%d: %d\n", x, i, d[x][i]);
    return 0;
}
