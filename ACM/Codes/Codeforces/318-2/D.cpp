#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int dp1[100020], dp2[100020], a[100020];
int n;
int dp[100020];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        dp1[i] = min(dp1[i - 1] + 1, a[i]);
    }
    int ans = 0;
    for(int i = n; i >= 1; i--)
    {
        dp2[i] = min(dp2[i+1]+1, a[i]);
        dp1[i] = min(dp2[i], dp1[i]);
        ans = max(ans, dp1[i]);
    }

    printf("%d\n", ans);
    return 0;
}