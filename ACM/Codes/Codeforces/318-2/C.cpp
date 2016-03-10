#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

#define __maxn 0x3f3f3f3f3f
using namespace std;

int n,a[100500],ans,m;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        while(a[i] % 2 == 0) a[i] /= 2;
        while(a[i] % 3 == 0) a[i] /= 3;
        if(a[i] != a[1])
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}