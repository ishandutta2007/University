#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int CrossProduct(LL x1, LL y1, LL x2, LL y2)
{
    LL xx = x1 * y2;
    LL yy = y1 * x2;
    if (xx == yy) return 0;
    return xx > yy ? 1 : -1;
}

int main()
{
    int T;
    cin >> T;
    LL x1, y1, x2, y2, x3, y3, x4, y4;

    while (T--) 
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        
        if (CrossProduct(x2 - x1, y2 - y1, x3 - x1, y3 - y1) * CrossProduct(x2 - x1, y2 - y1, x4 - x1, y4 - y1) <= 0 &&
            CrossProduct(x4 - x3, y4 - y3, x1 - x3, y1 - y3) * CrossProduct(x4 - x3, y4 - y3, x2 - x3, y2 - y3) <= 0)
        {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}