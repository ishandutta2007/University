#include <bits/stdc++.h>

using namespace std;

int n;
int a[200];
int vis[10020];
int ans, sum;

int main()
{
    scanf("%d", &n);
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    memset(vis, 0, sizeof(vis));
    ans = sum;
    vis[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum - a[i]; j >= 0; j--)
        {
            if (vis[j] == 1)
            {
                vis[j + a[i]] = 1;
                int tmp = j + a[i];
                ans = min(ans, abs(sum - 2*tmp));
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
