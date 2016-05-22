#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL mod = 100000000000000;
LL ans[10000000];

int main()
{
    int n;
    scanf("%d", &n);
    ans[0] = 1;
    LL len = 1;
    
    for (int i = 1; i <= n; i++)
    {
        LL c = 0;
        for (int j = 0; j < len; j++)
        {
            ans[j] *= i;
            ans[j] += c;
            c = ans[j] / mod;
            ans[j] %= mod;
        }

        while(c > 0)
        {
            ans[len++] = c % mod;
            c /= mod;
        }
    }
    // cout << ans[len-1];
    printf("%I64d", ans[len - 1]);
    for(int i = len - 2; i >= 0; i--)
        printf("%0.14I64d", ans[i]);
        // cout << ans[i] << " ";
    printf("\n");
    
}