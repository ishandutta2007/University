#include <bits/stdc++.h>
using namespace std;
#define N 105
#define M 2005
#define L 10000005
#define O 100005
#define MOD 1000000007
using namespace std;
typedef long long LL;
int n, m, a[N], c[O], e[L], sum, f[M], Max;
struct node
{
    int d[N], t;
}b[M];
void init()
{
    n=2;

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        a[i]--;
        sum += a[i];
        Max = max(Max, a[i]);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            scanf("%d", &b[i].d[j]);
            b[i].d[j]--;
            b[i].t += b[i].d[j];
        }
}
int pow(int x, int y)
{
    int res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (LL)res * x % MOD;
        x = (LL)x * x % MOD;
        y >>= 1;
    }
    return res % MOD;
}
bool cmp(const node &x, const node &y)
{
    return x.t < y.t;
}
void deal()
{
    sort(b + 1, b + m + 1, cmp);
    m++;
    for(int i = 1; i <= n; ++i)
    {
        b[m].d[i] = a[i];
        b[m].t += b[m].d[i];
    }
    e[0] = e[1] = 1;
    sum++;
    for(int i = 2; i <= sum; ++i)
        e[i] = (LL)e[i - 1] * i % MOD;
    c[0] = 1;
    c[Max + 1] = pow(e[Max + 1], MOD - 2);
    for(int i = Max; i >= 1; --i)
        c[i] = (LL)c[i + 1] * (i + 1) % MOD;
    for(int i = 1; i <= m; ++i)
    {
        f[i] = e[b[i].t];
        int tmp2[N];
        for(int j = 1; j <= n; ++j)
            tmp2[j] = b[i].d[j];
        for(int j = 1; j <= n; ++j)
            f[i] = (LL)f[i] * c[tmp2[j]] % MOD;
        for(int j = 1; j < i; ++j)
        {
            bool flag = true;
            for(int k = 1; k <= n; ++k)
                if(b[i].d[k] < b[j].d[k])
                {
                    flag = false;
                    break;
                }
            if(flag)
            {
                int sum1 = 0;
                for(int k = 1; k <= n; ++k)
                {
                    tmp2[k] = b[i].d[k] - b[j].d[k];
                    sum1 += tmp2[k];
                }
                sum1 = e[sum1];
                for(int k = 1; k <= n; ++k)
                    sum1 = (LL)sum1 * c[tmp2[k]] % MOD;
                f[i] = (f[i] - (LL)sum1 * f[j] % MOD + MOD) % MOD;
            }
        }
    }
    printf("%d\n", f[m]);
}
int main()
{
    init();
    deal();
    return 0;
}
