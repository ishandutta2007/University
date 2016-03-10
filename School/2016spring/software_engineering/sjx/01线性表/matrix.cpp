//#define ONLINE_JUDGE
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

//Love lemon_TsyD
//Miss lydrainbowcat
//By ITX351

struct Unit
{
    int X, Y, value;
    inline Unit() { }
    inline Unit(int _X, int _Y, int _value)
    { X = _X, Y = _Y, value = _value; }
};

const int MAXN = 511, MAXY = 5111;
int num[MAXY], cpot[MAXY];

class Matrix
{
public:
    int ax, ay, N;
    Unit a[MAXN];

    Matrix Transpose()
    {
        Matrix ret; ret.ay = ax, ret.ax = ay;

        memset(num, 0, sizeof(num));
        for (int k = 1; k <= N; k++)
            num[a[k].Y]++;
        cpot[1] = 1;
        for (int j = 2; j <= ay; j++)
            cpot[j] = cpot[j - 1] + num[j - 1];

        for (int k = 1; k <= N; k++)
        {
            int loc = cpot[a[k].Y]++;
            ret.a[loc] = a[k];
            swap(ret.a[loc].X, ret.a[loc].Y);
        }
        return ret;
    }
}m;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    scanf("%d%d%d", &m.ax, &m.ay, &m.N);
    for (int i = 1; i <= m.N; i++)
        scanf("%d%d%d", &m.a[i].X, &m.a[i].Y, &m.a[i].value);

    Matrix m_ = m.Transpose();
    for (int i = 1; i <= m.N; i++)
        printf("%d %d %d\n", m_.a[i].X, m_.a[i].Y, m_.a[i].value);

    return 0;
}
